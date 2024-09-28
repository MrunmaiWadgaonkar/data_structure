//implement stack datastucture using a)array                                  
//demonstrate stack operation such as push pop and print in the form of menu driven program

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;    
};
struct node *top = NULL; 
void push();
void pop();
void display();
int main() 
{
    int choice;
    printf("enter '1' for Push, '2' for Pop, '3' for Display Stack, and '4' for Exit\n");
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
                printf("Wrong input, please try again.\n");
        }
    } while (1);
    return 0;
}
void push() 
{
    int n;
    struct node*p; 
    p = (struct node*)malloc(sizeof(struct node));
    printf("enter data to push: ");
    scanf("%d", &n);
    p->data = n;
    p->next = top; 
    top = p; 
    printf("%d pushed\n", n);
}
void pop() 
{
    if (top == NULL) 
	{
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp = top; 
    int q = temp->data; 
    top = top->next; 
    free(temp); 
    printf("Removed %d from stack.\n", q);
}
void display() {
    if (top == NULL) 
	{
        printf("Stack is empty\n");
        return;
    }
    struct node *first = top; 
    printf("Stack is:\n");
    while (first != NULL) 
	{
        printf("%d\t", first->data);
        first = first->next;
    }
    printf("\n");
}

