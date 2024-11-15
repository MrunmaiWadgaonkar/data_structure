#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int F = -1;
int R = -1;
int size = 0;

void enqueue();
void dequeue();
void display();
void exit_program();

int main() 
{
    int choice;
    printf("1 for add (enqueue), 2 for delete (dequeue), 3 for print (display), 4 for exit\n");

    do {
        printf("enter choice: ");
        scanf("%d", &choice);

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
            case 4:
                exit_program();
                break;
            default:
                printf("wrong choice\n");
        }
    } while (choice != 4);
    return 0;
}

void enqueue() 
{
    int item;
    if (size == MAX) 
    {
        printf("overflow: queue is full\n");
        return;
    }
    printf("enter element to add: ");
    scanf("%d", &item);

    if (F == -1) 
    { 
        F = 0;
    }

    if (R == MAX - 1) 
    {
        R = 0;
    } 
    else 
    {
        R = R + 1;
    }

    queue[R] = item;
    size++;
    printf("inserted %d into the queue\n", item);
}

void dequeue() 
{
    if (size == 0) 
    {
        printf("underflow: queue is empty\n");
        return;
    }

    int item = queue[F];
    if (F == MAX - 1) 
    {
        F = 0;
    } 
    else 
    {
        F = F + 1;
    }

    size--;
    if (size == 0) 
    {
        F = R = -1;
    }

    printf("deleted %d from the queue\n", item);
}

void display() 
{
    if (size == 0) 
    {
        printf("queue is empty\n");
        return;
    }

    printf("queue contents: ");
    int i = F, count;
    for (count = 0; count < size; count++) 
    {
        printf("%d ", queue[i]);
        
        if (i == MAX - 1) 
        {
            i = 0;
        } 
        else
        {
            i = i + 1;
        }
    }
    printf("\n");
}
void exit_program() 
{
    printf("exiting program...\n");
    exit(0);
}
