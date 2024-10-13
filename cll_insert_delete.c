//Circular LL insert at beg, insert at end, delete from beg, delete from end.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *s = NULL;
struct node* Insert_Beg(struct node *top) 
{
    struct node *r = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &r->data);
    if (top == NULL) 
    {
        r->next = r;
        return r;
    }
    struct node *t = top;
    while (t->next != top) 
    {
        t = t->next;
    }
    t->next = r;
    r->next = top;
    return r;
}
struct node* Insert_End(struct node *top) 
{
    struct node *r = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &r->data);    
    if (top == NULL) 
    {
        r->next = r;
        return r;
    }
    struct node *t = top;
    while (t->next != top) 
    {
        t = t->next;
    }
    t->next = r;
    r->next = top;
    printf("current list: ");
    r=top;
    while(r->next!=top)
    {
    	printf("%d\t",r->data);
    	r=r->next;
	}
	printf("%d",r->data);
    return top;
}
struct node* Delete_Beg(struct node *top) 
{
    if (top == NULL) 
    {
        printf("list is empty!\n");
        return NULL;
    }
    if (top->next == top) 
    {
        free(top);
        return NULL;
    }
    struct node *r = top;
    struct node *last = top;
    while (last->next != top) 
    {
        last = last->next;
    }
    last->next = top->next;
    free(top);
    top = last->next;
    printf("current list: ");
    struct node *t = top;
    do 
    {
        printf("%d\t", t->data);
        t = t->next;
    } while (t != top);
    return top;
}
struct node* Delete_End(struct node *top) 
{
    if (top == NULL) 
    {
        printf("list is empty!\n");
        return NULL;
    }
    if (top->next == top) 
    {
        free(top);
        return NULL;
    }
    struct node *r = top;
    struct node *t = NULL;
    while (r->next != top) 
    {
        t = r;
        r = r->next;
    }
    t->next = top;
    free(r);
    printf("current list: ");
    struct node *u = top;
    do 
    {
        printf("%d\t", u->data);
        u = u->next;
    } while (u != top);
    return top;
}
int main() 
{
    struct node *p, *q;
    char ch;
    int op;
    p = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &p->data);
    s = p;
    p->next = s;
    do 
    {
        q = (struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d", &q->data);
        p->next = q;
        q->next = s;
        p = q;
        printf("enter 'y' to continue\n");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
    printf("enter '1' for Insert_Beg, '2' for Insert_End, '3' for Delete_Beg, '4' for Delete_End, '5' for Exit: ");
    scanf("%d", &op);
    while (op != 5) 
    {
        switch (op) 
        {
            case 1:
                s = Insert_Beg(s);
                printf("current list: ");
                struct node *current = s;
                do 
                {
                    printf("%d\t", current->data);
                    current = current->next;
                } while (current != s);
                break;
            case 2:
                s = Insert_End(s);
                break;
            case 3:
                s = Delete_Beg(s);
                break;
            case 4:
                s = Delete_End(s);
                break;
            default:
                printf("wrong input\n");
        }
        printf("\nenter your next operation: ");
        scanf("%d", &op);
    }
    return 0;
}
