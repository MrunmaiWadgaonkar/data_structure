#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *s=NULL;
void Delete_after(int key) 
{
    struct node *first;
    first=s;
    while (first->data!=key) 
	{
        first= first->next;
    }
    if(first==NULL) 
	{
        printf("no node to delete after %d", key);
        return;
    }
    struct node *r=first->next;
    first->next=r->next;
    free(r);
}
int main() 
{
    char ch;
    struct node *p=NULL,*q=NULL;
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
    printf("enter the item after which you want to delete the node\n");
    scanf("%d",&item);
    Delete_after(item);
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
