#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct queue_array
{
    int a[MAX];
    int rear,front;
}queue;

void insert(queue *p, int n);
void del(queue *p);
void display(queue *p);

void main()
{
    int x,m;
    queue q;
    q.rear=q.front=-1;
    while(1)
    {
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit ");
        printf("\n Enter Your Choice: ");
        scanf("%d",&x);
        switch(x)
        {
            case 1: printf("\n Enter the number: ");
                    scanf("%d",&m);
                    insert(&q,m);
                    break;
            case 2: del(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit(0);
            default: printf("\n Try Again.");
        }
    }
}

void display(queue *p)
{
    int x;
    if(p->front==-1 && p->rear==-1)
        printf("\n Underflow.");
    else
    {
        if(p->rear>p->front)
        {
            for(x=p->front;x<=p->rear;x++)
            printf("\t %d",p->a[x]);
        }
        else
        {
            for(x=p->front;x<=MAX-1;x++)
                printf("\t %d",p->a[x]);
            for(x=0;x<=p->rear;x++)
                printf("\t %d",p->a[x]);
        }
    }
}

void insert(queue *p, int x)
{
    if((p->rear+1)%MAX==p->front)
    {
        printf("\n Overflow.");
        return;
    }
    else if(p->rear==-1 && p->front==-1)
    {
        p->front=p->rear=0;
        p->a[p->rear]=x;
    }
    else if(p->rear==MAX-1 && p->front!=0)
    {
        p->rear=0;
        p->a[p->rear]=x;
    }
    else
    {
        p->rear++;
        p->a[p->rear]=x;
    }
    printf("\n Front reaches at= %d",p->front);
    printf("\n Rear reaches at= %d",p->rear);
    printf("\n Value Inserted.");
}

void del(queue *p)
{
    int x;
    if(p->front==-1 && p->rear==-1)
        printf("\n Underflow.");
    else
    {
        x=p->a[p->front];
        if(p->front==p->rear)
            p->front=p->rear=-1;
        else
        {
            if(p->front==MAX-1)
                p->front=0;
            else
                p->front++;
        }
        printf("\n %d is deleted.",x);
        printf("\n Front reaches at= %d",p->front);
        printf("\n Rear reaches at= %d",p->rear);
    }
}