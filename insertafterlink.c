#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *s=NULL;
void Insert_after(int key) 
{
    struct node *r,*t,*first;
    r = (struct node *)malloc(sizeof(struct node));
    printf("enter data for new node\n");
    scanf("%d",&r->data);
    first=s;
    while (first->data!=key) 
	{
        first=first->next;
    }    
    if (first!=NULL) 
	{
        t=first->next;
        first->next=r;
        r->next=t;
    } 
	else 
	{
        printf("entered element not found\n");
        free(r); 
    }
}
int main() 
{
    char ch;
    struct node *p,*q;
    int item;
    do 
	{
        q = (struct node *)malloc(sizeof(struct node));
        printf("enter data in node\n");
        scanf("%d",&q->data);
        q->next=NULL;
        if(s==NULL) 
		{
            s=q;
        } 
		else 
		{
            p->next=q;
        }
        p=q;
        printf("enter 'y' to continue\n");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("enter the item after which you want to insert a new node\n");
    scanf("%d",&item);
    Insert_after(item);
    printf("the list is\n");
    p=s;
    while(p!=NULL) 
	{
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    while (s!=NULL) 
	{
        p=s;
        s=s->next;
        free(p);
    }
    return 0;
}
