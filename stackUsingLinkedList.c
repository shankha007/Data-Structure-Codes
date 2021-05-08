#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

typedef struct slist
{
    int info;
    struct slist *next;
}node;

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
        printf("\n 1.PUSH \n 2.POP \n 3.Display\n 0.exit");
        printf("\n enter your choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1: H=insert_first(H);
                    break;
            case 2: H=del_first(H);
                    break;
            case 3: display(H);
                    break;
            case 0: exit(0);
            default:printf("\n Wrong cHoice");
        }
    }
}

node *insert_first(node *H1)
{
    node *p=H1;
    H1=(node *)malloc(sizeof(node));
    H1->next=p;
    printf("\n enter value");
    scanf("%d",&H1->info);
    return(H1);
}

node *del_first(node *H1)
{
    node *p=H1;
    H1=H1->next;
    free(p);
    return(H1);
}

void display(node *H1)
{
    node *p=H1;
    if(p==NULL)
    {
        printf("\n Stack is empty \n");
    }
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
}