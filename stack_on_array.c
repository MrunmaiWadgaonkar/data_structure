//implement stack datastucture using a)array                                  
//demonstrate stack operation such as push pop and print in the form of menu driven program

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;
void push();
void pop();
void display();
int main() 
{
    int choice;
    printf("enter '1' for Push, '2' for Pop,  '3' for Display Stack and '4' for Exit\n");
    do 
	{
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
		{
            case 1:
                push();
                break;
                
            case 2:
                pop();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("wrong input, please try again.\n");
        }
    } while (1);
    return 0;
}
void push() 
{
    int num;
    if (top == MAX - 1) 
	{
        printf("stack Overflow\n");
    } 
	else 
	{
        printf("enter data to push: ");
        scanf("%d", &num);
        top=top+1;
        stack[top] = num;
        printf("%d pushed\n", num);
    }
}
void pop() 
{
    if (top == -1) 
	{
        printf("stack Underflow\n");
    } 
	else 
	{
        printf("removed %d from stack.\n", stack[top--]);
    }
}

void display() 
{
	int i;
    if (top == -1) 
	{
        printf("stack is empty.\n");
    } 
	else 
	{
        printf("stack contents:\n");
        for ( i = 0; i <= top; i++) 
		{
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

