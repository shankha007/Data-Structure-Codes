#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

typedef struct slist
{
    int info;
    struct slist *next;
}node;

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
        printf("\n 1.Insert \n 2.Delete \n 3.Display\n 0.exit");
        printf("\n Enter your choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:H=insert_last(H);
            break;
            case 2:H=del_first(H);
            break;
            case 3:display(H);
            break;
            case 0: exit(0);
            default:printf("\n Wrong choice");
        }
    }
}

node *del_first(node *H1)
{
    node *p=H1;
    H1=H1->next;
    free(p);
    return(H1);
}

node *insert_last(node *H1)
{
    if(H1==NULL)
    { //insert_first
        node *p=H1;
        H1=(node *)calloc(sizeof(node),1);
        H1->next=p;
        printf("\n enter value");
        scanf("%d",&H1->info);
        return(H1);
    }
    else
    { //insert last
        node *p=H1;
        // node *p1=H1;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=(node *)calloc(sizeof(node),1);
        p=p->next;
        p->next=NULL;
        printf("\n enter the value");
        scanf("%d",&p->info);
        return(H1);
    }
}

void display(node *H1)
{
    node *p=H1;
    if(H1==NULL)
    {
        printf("\n Queue is empty \n");
    }
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
}