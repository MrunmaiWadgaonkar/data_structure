#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *s;
int main() 
{ 
    char ch;
    struct node *p,*q;
    p=(struct node *)malloc(sizeof(struct node));
    if (p==NULL) 
    { 
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter data in node\n");
    scanf("%d",&p->data);
    s=p;
    do 
    {
        q = (struct node *)malloc(sizeof(struct node));
        printf("Enter data in next node\n");
        scanf("%d",&q->data);
        p->next=q;
        p=q;
        printf("Enter 'y' to continue\n");
        scanf(" %c",&ch);
    } 
    while(ch=='y'||ch=='Y');
    p->next=NULL;
    while(s!= NULL) 
    {
        printf("%d\n",s->data);
        s=s->next;
    }
    return 0; 
}
