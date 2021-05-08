#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5

//Structure Declaration
typedef struct st_array
{
    int a[MAX];
    int top;
}stack;

//Prototype Declaration
void push(stack *p, int n);
void pop(stack *p);
void display(stack p);

//Main function
int main()
{
    int ch,val;
    stack s;
    s.top=-1; //Initial Declaration
    while(1)
    {
        printf("\n1. Push \n2. Pop \n3. Display \n4. Exit");
        printf("\n Enter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n Enter the value:");
                    scanf("%d",&val);
                    push(&s,val);
                    break;
            case 2: printf("\n Deleting the top:");
                    pop(&s);
                    break;
            case 3: printf("\n Display:");
                    display(s);
                    break;
            case 4: exit(0);
            default: printf("\n Wrong Input.");
        } //end of switch
    } //end of while
    return 0;
} //end of main

void push(stack *p, int n)
{
    if(p->top==MAX-1)
    {
        printf("\n Stack is full.");
    }
    else
    {
        p->top++;
        p->a[p->top]=n;
        printf("\n Successfully inserted.");
    }
}

void pop(stack *p)
{
    int x;
    if(p->top==-1)
    {
        printf("\n Stack is empty.");
    }
    else
    {
        x=p->a[p->top];
        p->top--;
        printf("%d is deleted.",x);
    }
}
void display(stack p)
{
    int i;
    if(p.top==-1)
    {
        printf("\n Stack is empty.");
    }
    else
    {
        for(i=p.top;i>=0;i--)
        printf("%d\t",p.a[i]);
    }
}