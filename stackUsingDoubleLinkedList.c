#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

typedef struct dstack
{ 
    struct dstack * pre;
    int info;
    struct dstack * next;
} node;

node *insert_first(node *);
node *del_first(node *);
void display(node *);

void main()
{
    int c;
    node *H=NULL;
    clrscr();
    while(1)
    {
        printf("\n 1.\2 PUSH \2 \n 2.\6 POP
        \6 \n 3.\3 DISPLAY \3 \n 0.\5 exit \5");
        printf("\n enter your choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:H=insert_first(H);
            break;
            case 2:H=del_first(H);
            break;
            case 3:display(H);
            break;
            case 0:exit(0);
            default:printf("\n wrong choice");
        }
    }
}

node *insert_first(node *H1)
{
    node *p=H1;
    H1=(node *)malloc(sizeof(node));
    H1->next=p;
    H1->pre=NULL;
    p->pre=H1;
    printf("\n enter value");
    scanf("%d",&H1->info);
    return(H1);
}

node *del_first(node *H1)
{
    node *p=H1;
    if(H1==NULL)
    {
        printf("\n stack is empty");
        return(H1);
    }
    else
    {
        H1=H1->next;
        H1->pre=NULL;
        printf("%d is deleted",p->info);
        free(p);
        return(H1);
    }
}

void display(node * H1)
{
    node *p=H1;
    if(H1==NULL)
    printf("\n stack is empty");
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
        p->next->pre=p;
    }
}