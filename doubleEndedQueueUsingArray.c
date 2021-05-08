#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct dequeue_array
{
    int a[MAX];
    int rear,front;
}queue;

void insert_rear(queue *p, int n);
void insert_front(queue *p, int n);
void del_front(queue *p);
void del_rear(queue *p);
void display(queue p);

void main()
{
    int x,m;
    queue q;
    q.rear=q.front=-1;
    while(1)
    {
        printf("\n1. Insert Rear ");
        printf("\n2. Delete Front ");
        printf("\n3. Display ");
        printf("\n4. Insert Front ");
        printf("\n5. Delete Rear ");
        printf("\n6. Exit ");
        printf("\n Enter Your Choice: ");
        scanf("%d",&x);
        switch(x)
        {
            case 1: printf("\n Enter the number: ");
                    scanf("%d",&m);
                    insert_rear(&q,m);
                    break;
            case 2: del_front(&q);
                    break;
            case 3: display(q);
                    break;
            case 4: printf("\n Enter the number: ");
                    scanf("%d",&m);
                    insert_front(&q,m);
                    break;
            case 5: del_rear(&q);
                    break;
            case 6: exit(0);
            default: printf("\n Try Again.");
        }
    }
}

void insert_rear(queue *p, int n)
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

void del_front(queue *p)
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

void display(queue p)
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

void insert_front(queue *p, int n)
{
    if((p->front==0 && p->rear==MAX-1))
    {
        printf("\n Queue is full.");
        return;
    }
    if(p->front == -1)
    {
        p->front=0;
        p->rear=0;
    }
    else
    {
        if(p->front==0)
            p->front=MAX-1;
        else
            p->front=p->front -1;
    }
    p->a[p->front]=n;
    printf("\n Element inserted.");
}

void del_rear(queue *p)
{
    int x;
    if(p->front==-1)
    {
        printf("\n Queue is empty.");
        return;
    }
    x=p->a[p->rear];
    printf("\n %d is deleted.",x);
    if(p->front==p->rear)
    {
        p->rear=-1;
        p->front=-1;
    }
    else
    {
        if(p->rear==0)
            p->rear=MAX-1;
        else
            p->rear=p->rear-1;
    }
}