#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define noofoperator 5

//global declaration of precedence
char operator[noofoperator][3]={{'+','1','l'},{'-','1','l'},{'*','2','l'},{'/','2','l'},{'^','3','r'}};

//Structure declaration
typedef struct stack_array
{
    char a[MAX];
    int top;
} stack;

//prototype declaration
void push(stack *p,char n);
char pop(stack *p);
char peek(stack *p);
void infixToPostfix(char *in,char *post);
int isOperand(char ch);
char hasHigherPrecedence(char ch1,char ch2);

//main function
int main()
{
    char infix[30],postfix[30];
    printf("\nEnter the Expression:");
    gets(infix);
    infixToPostfix(infix,postfix);
    return 0;
}

void push(stack *p, char n)
{
    if(p->top==MAX-1)
        printf("\nStack Overflow.");
    else
    {
        p->top++;
        p->a[p->top]=n;
    }
}

char pop(stack *p)
{
    char c;
    if(p->top==-1)
        printf("\nStack Underflow.");
    else
    {
        c=p->a[p->top];
        p->top--;
    }
    return c;
}

char peek(stack *p)
{
    char c;
    c=p->a[p->top];
    return c;
}

//infix to postfix conversion
void infixToPostfix(char *in,char *post)
{
    stack s;
    s.top=-1;
    char *p,*q;
    char ch,temp;
    int length;
    length= strlen(in);
    in[length]=')';
    in[length+1]='\0';
    push(&s,'(');
    p=in;
    q=post;
    while(*p!='\0')
    {
        ch=*p;
        if(isOperand(ch)==1)
        {
            *q=ch;
            q++;
        }
        else if(ch=='(')
        {
            push(&s,ch);
        }
        else if(ch==')')
        {
            temp=pop(&s);
            while(temp!='(')
            {
                *q=temp;
                q++;
                temp=pop(&s);
            }
        }
        else
        {
            temp=peek(&s);
            while((hasHigherPrecedence(temp,ch)==1)&&(temp!='('))
            {
                temp=pop(&s);
                *q=temp;
                q++;
                temp=peek(&s);
            }
            push(&s,ch);
        }
        p++;
    }
    q++;
    *q='\0';
    puts(post);
}

//operand checking function
int isOperand(char ch)
{
    if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        return 1;
    else
        return 0;
}

char hasHigherPrecedence(char ch1,char ch2)
{
    int i,j;
    for(i=0;i<noofoperator;i++)
    {
        if(operator[i][0]==ch1)
        break;
    }
    for(j=0;j<noofoperator;j++)
    {
        if(operator[j][0]==ch2)
        break;
    }
    if((operator[i][1])>(operator[j][1]))
        return 1;
    else if((operator[i][1])==(operator[j][1]))
    {
        if(operator[i][2]=='l')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}