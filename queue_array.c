#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int R = -1;
int F = -1;
int queue[MAX];
void enqueue();
void dequeue();
void display();
void main() {
    int choice;
    printf("1 for insert, 2 for delete, 3 for display, 4 for exit\n");
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
    printf("exiting program...\n");
    exit(0);
}
void enqueue() 
{
    int item;
    printf("enter element: ");
    scanf("%d", &item);
    if (R == MAX - 1) 
	{
        printf("overflow\n");
        return;
    }
    if (F == -1 && R == -1) 
	{
        F = 0;
        R = 0;
    } 
	else 
	{
        R = R + 1;
    }
    queue[R] = item;
    printf("inserted\n");
}
void dequeue() 
{
    int item;
    if (F == -1 || F > R) 
	{
        printf("underflow\n");
        return;
    }
    item = queue[F];
    if (F == R) 
	{
        F = -1;
        R = -1;
    } 
	else 
	{
        F = F + 1;
    }
    printf("deleted\n");
}
void display() 
{
    int i;
    if (R == -1) 
	{
        printf("queue is empty\n");
    } 
	else 
	{
        printf("values are: ");
        for (i = F; i <= R; i++) 
		{
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

