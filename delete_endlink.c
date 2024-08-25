#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *s=NULL;
void Delete_end() 
{
    struct node *first=s;
    struct node *r=NULL;
    while (first->next!=NULL) 
	{
        r=first;
        first=first->next;
    }
    if(r!=NULL) 
	{
        r->next=NULL;
    } 
	else 
	{
        s=NULL;
    }
    free(first);
}
int main() 
{
    char ch;
    struct node *p=NULL; 
    struct node *q=NULL;
    do {
        q=(struct node *)malloc(sizeof(struct node));
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
    Delete_end();
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
