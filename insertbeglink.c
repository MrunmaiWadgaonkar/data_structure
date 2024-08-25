#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *s=NULL;
void Insert_beg() 
{
    struct node *r;
    r=(struct node *)malloc(sizeof(struct node));
    printf("enter data for new node\n");
    scanf("%d",&r->data);
    r->next=s; 
    s=r;  
}
int main() 
{
    char ch;
    struct node *p,*q;
    do 
	{
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
    } while (ch=='y'||ch=='Y');
    Insert_beg();
    printf("the list is\n");
    p=s;
    while(p!=NULL) 
	{
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    while(s!=NULL) 
	{
        p=s;
        s=s->next;
        free(p);
    }
    return 0;
}

