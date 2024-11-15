#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node* F = NULL;
struct node* R = NULL;
void enqueue();
void dequeue();
void display();
void exit_program();
int main() 
{
    int choice;
    printf("1 for insert (enqueue), 2 for delete (dequeue), 3 for display, 4 for exit\n");
    printf("enter choice: ");
    scanf("%d", &choice);
    while (choice != 4) 
	{
        switch (choice) 
		{
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("wrong choice\n");
        }
        printf("enter next choice: ");
        scanf("%d", &choice);
    }
    exit_program();
    return 0;
}
void enqueue() 
{
    int item;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) 
	{
        printf("memory allocation failed.\n");
        return;
    }
    printf("enter element to insert: ");
    scanf("%d", &item);
    newNode->data = item;
    newNode->next = NULL;
    if (R == NULL) 
	{
        F = R = newNode;
    } 
	else 
	{
        R->next = newNode;
        R = newNode;
    }
    printf("inserted %d into the queue\n", item);
}
void dequeue() 
{
    if (F == NULL) 
	{
        printf("underflow: queue is empty\n");
        return;
    }
    struct node* temp = F;
    int item = F->data;
    F = F->next;
    if (F == NULL) 
	{
        R = NULL;
    }
    printf("deleted %d from the queue\n", item);
    free(temp);
}
void display() 
{
    if (F == NULL) 
	{
        printf("queue is empty\n");
        return;
    }
    struct node* temp = F;
    printf("queue contents: ");
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void exit_program() 
{
    printf("exiting program...\n");
    exit(0);
}

