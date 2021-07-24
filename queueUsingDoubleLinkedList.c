#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

typedef struct dqueue
{
    struct dqueue *pre;
    int info;
    struct dqueue *next;
} node;

node *insert_last(node *);
node *del_first(node *);
void display(node *);

void main()
{
    int c;
    node *H=NULL;
    clrscr();
    while(1)
    {
        printf("\n 1.insert_last \n 2.del_first \n 3.display \n 0.exit");
        printf(" \n enter your choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:H=insert_last(H);
            break;
            case 2:H=del_first(H);
            break;
            case 3:dispaly(H);
            break;
            case 0:exit(0);
            break;
            default:printf("\n wrong choice");
        }
    }
}

node *insert_last(node * H1)
{
    if(H1==NULL)
    {
        node *p=H1;
        H1=(node *)malloc(sizeof(node));
        H1->next=p;
        H1->pre=NULL;
        p->pre=H1;
        printf("\n enter the value");
        scanf("%d",&H1->info);
        return(H1);
    }
    else
    {
        node *p=H1;
        node *p1=H1;
        if(p->next==NULL)
        {
            p=p->next; 
        }
        p->next=(node *)malloc(sizeof(node));
        p=p->next;
        p->next->pre=NULL;
        p->pre=p1;
        p->next=NULL;
        printf("\n enter the value");
        scanf("%d",p1->info);
        return(H1);
    }
}

node *del_first(node *H1)
{
    node *p=H1;
    H1=H1->next;
    H1->pre=NULL;
    printf("%d is deleted",p->info);
    free(p);
    return(H1);
}

void display(node *H1)
{
    node *p=H1;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
        p->next->pre=p;
    }
}