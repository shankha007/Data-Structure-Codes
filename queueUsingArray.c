#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

//Structure Declaration
typedef struct queue_array
{
    int a[MAX];
    int rear,front;
}q1;

//Prototype Declaration
void insert(q1 *p, int n);
void del(q1 *p);
void display(q1 p);

void main()
{
    int x,m;
    q1 q;
    q.rear=q.front=-1; //Initial Declaration
    while(1)
    {
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit");
        printf("\n Enter your choice:");
        scanf("%d",&x);
        switch(x)
        {
            case 1: printf("\n Enter a number:");
                    scanf("%d",&m);
                    insert(&q,m);
                    break;
            case 2: del(&q);
                    break;
            case 3: display(q);
                    break;
            case 4: exit(0);
            default: printf("\n Try Again.");
        } //End of Switch
    } //End of While
} //End of Main 5

void insert(q1 *p, int n)
{
    if(p->rear==MAX-1)
        printf("\n Queue is full.");
    else if(p->front==-1 && p->rear==-1)
    {
        p->front=0;
        p->rear=0;
        p->a[p->rear]=n;
        printf("\n Element inserted.");
    }
    else
    {
        p->rear++;
        p->a[p->rear]=n;
        printf("\n Element inserted.");
    }
}

void del(q1 *p)
{
    int x;
    if(p->front==-1||p->front>p->rear)
        printf("\n Queue is empty.");
    else
    {
        x=p->a[p->front];
        p->front++;
        if(p->front>p->rear)
        p->front=p->rear=-1;
        printf("\n %d is Deleted.",x);
    }
}

void display(q1 p)
{
    int x;
    if(p.front==-1 || p.front>p.rear)
        printf("\n Queue is empty.");
    else
    {
        for(x=p.front;x<=p.rear;x++)
        printf("%d\t",p.a[x]);
    }
}