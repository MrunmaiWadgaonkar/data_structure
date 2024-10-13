#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    } else {
        printf("stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    printf("stack underflow\n");
    return ' ';
}

int precedence(char op) {
    if (op == '/' || op == '*' || op == '%') return 1;
    if (op == '+' || op == '-') return 0;
    return -1;
}

void infix_to_postfix(char *source, char *target) {
    int i = 0, j = 0;
    while (source[i]) {
        if (source[i] == '(') {
            push(source[i]);
        } else if (source[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                target[j++] = pop();
            }
            pop();
        } else if (isalnum(source[i])) {
            target[j++] = source[i];
        } else if (strchr("+-*/%", source[i])) {
            while (top >= 0 && precedence(stack[top]) >= precedence(source[i])) {
                target[j++] = pop();
            }
            push(source[i]);
        } else {
            printf("incorrect element in expression\n");
            exit(1);
        }
        i++;
    }
    while (top >= 0) {
        target[j++] = pop();
    }
    target[j] = '\0';
}

void reverse_string(char *str) 
{
    int n = strlen(str), i;
    for (i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infix_to_prefix(char *source, char *target) 
{
	int i;
    reverse_string(source);
    for (i = 0; source[i]; i++) {
        if (source[i] == '(') {
            source[i] = ')';
        } else if (source[i] == ')') {
            source[i] = '(';
        }
    }
    char postfix[MAX];
    infix_to_postfix(source, postfix);
    reverse_string(postfix);
    strcpy(target, postfix);
}

int evaluate_postfix(char *expression) {
    int eval_stack[MAX], eval_top = -1, i;
    for (i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            eval_stack[++eval_top] = expression[i] - '0';
        } else {
            int val2 = eval_stack[eval_top--];
            int val1 = eval_stack[eval_top--];
            switch (expression[i]) {
                case '+': eval_stack[++eval_top] = val1 + val2; break;
                case '-': eval_stack[++eval_top] = val1 - val2; break;
                case '*': eval_stack[++eval_top] = val1 * val2; break;
                case '/': eval_stack[++eval_top] = val1 / val2; break;
            }
        }
    }
    return eval_stack[eval_top];
}

int main() {
    char infix[100], postfix[100], prefix[100];
    int choice;
    do {
        printf("menu:\n1. infix to postfix\n2. infix to prefix\n3. postfix evaluation\n4. exit\nenter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter infix expression: ");
                scanf("%s", infix);
                infix_to_postfix(infix, postfix);
                printf("postfix: %s\n", postfix);
                break;
            case 2:
                printf("enter infix expression: ");
                scanf("%s", infix);
                infix_to_prefix(infix, prefix);
                printf("prefix: %s\n", prefix);
                break;
            case 3:
                printf("enter postfix expression: ");
                scanf("%s", postfix);
                printf("result: %d\n", evaluate_postfix(postfix));
                break;
            case 4:
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

