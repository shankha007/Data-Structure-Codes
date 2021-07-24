#include<stdio.h>
#include<stdlib.h>

typedef struct pol
{
    float coeff;
    int expo;
    struct pol *link;
} pol;

void sorted_insert(pol **,float,int);
void display(pol *);
void del(pol *);
void addition(pol **,pol **,pol **);
void substraction(pol **,pol **,pol **);
void multiplication(pol **,pol **,pol **);
void division(pol **,pol **,pol **);

int main()
{
    pol *head1=NULL,*head2=NULL,*head3=NULL;
    int n1,n2,i,e,choice;
    float c;
    printf("Enter no. of elements in the 1st polynomial ");
    scanf("%d",&n1);
    printf("Enter no. of elements in the 2nd polynomial ");
    scanf("%d",&n2);
    printf("Enter elements for polynomial 1\n");
    for(i=0;i<n1;i++)
    {
        printf("Enter coefficient ");
        scanf("%f",&c);
        printf("Enter exponent ");
        scanf("%d",&e);
        sorted_insert(&head1,c,e);
    }
    display(head1);
    printf("\nEnter elements for polynomial 2\n");
    for(i=0;i<n2;i++)
    {
        printf("Enter coefficient ");
        scanf("%f",&c);
        printf("Enter exponent ");
        scanf("%d",&e);
        sorted_insert(&head2,c,e);
    }
    display(head2);
    printf("\n1.Addition ");
    printf("\n2.Subtraction ");
    printf("\n3.Multiplication ");
    printf("\n4.Division\n");
    printf("\nEnter your choice ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: addition(&head1,&head2,&head3);
        break;
        case 2: substraction(&head1,&head2,&head3);
        break;
        case 3: multiplication(&head1,&head2,&head3);
        break;
        case 4: division(&head1,&head2,&head3);
        break;
        case 5: exit(0);

        break;

        default: printf("Invalid input");
    }
    display(head3);
    return 0;
}

void sorted_insert(pol **s,float c,int e)
{
    pol *head=*s;
    if(head==NULL||head->expo<e)
    {
        pol *temp=(pol*)malloc(sizeof(pol));
        temp->coeff=c;
        temp->expo=e;
        temp->link=head;
        head=temp;
    }
    else
    {
        pol *p=head;
        while(p->link!=NULL&&p->expo>e)
        {
            p=p->link;
        }
        if(p->expo==e)
        {
            p->coeff=p->coeff+c;
        }
        else
        {
            pol *temp=(pol*)malloc(sizeof(pol));
            temp->coeff=c;
            temp->expo=e;
            temp->link=p->link;
            p->link=temp;
        }
    }
    *s=head;
}

void display(pol *head)
{
    pol *p=head;
    while(p!=NULL)
    {
        if(p->link!=NULL)
        {
            if(p->expo!=1)
                printf("%fX^%d +",p->coeff,p->expo);
            else
                printf("%fX +",p->coeff);
            p=p->link;
        }
        else
        {
            if(p->expo>1)
                printf("%fX^%d",p->coeff,p->expo);
            else if(p->expo==1)
                printf("%fX",p->coeff);
            else
                printf("%f",p->coeff);
            p=p->link;
        }
    }
}

/*pol* del(pol *head)
{
pol *p;//*head=*s;
while(head!=NULL)
{
p=head;
head=head->link;
free(p);
}
//*s=head;
return head;
}*/

void addition(pol **s1,pol **s2,pol **s3)
{
    pol *head1=*s1,*head2=*s2,*head3=*s3;
    if(head1==NULL&&head2==NULL)
    {
        printf("The result is zero ");
    }
    else
    {
        if(head1==NULL)
        {
            pol *temp=head2;
            while(temp!=NULL)
            {
                sorted_insert(s3,temp->coeff,temp->expo);
                temp=temp->link;
            }
        }
        else if(head2==NULL)
        {
            pol *temp=head1;
            while(head1!=NULL)
            {
                sorted_insert(s3,temp->coeff,temp->expo);
                temp=temp->link;
            }
        }
        else
        {
            pol *p=head1,*q=head2;
            while(p!=NULL && q!=NULL)
            {
                if(p->expo>q->expo)
                {
                    sorted_insert(s3,p->coeff,p->expo);
                    p=p->link;
                }
                else if(p->expo==q->expo)
                {
                    sorted_insert(s3,p->coeff+q->coeff,p->expo);
                    p=p->link;
                    q=q->link;
                }
                else
                {
                    sorted_insert(s3,q->coeff,q->expo);
                    q=q->link;
                }
            }
            while(p!=NULL)
            {
                sorted_insert(s3,p->coeff,p->expo);
                p=p->link;
            }
            while(q!=NULL)
            {
                sorted_insert(s3,q->coeff,q->expo);
                q=q->link;
            }
        }
    }
    *s1=head1; *s2=head2;
}

void substraction(pol **s1,pol **s2,pol **s3)
{
    pol *head1=*s1,*head2=*s2;
    if(head1==NULL&&head2==NULL)
    {
        printf("The result is zero ");
    }
    else
    {
        if(head1==NULL)
        {
            pol *temp=head2;
            while(temp!=NULL)
            {
                sorted_insert(s3,-temp->coeff,temp->expo);
                temp=temp->link;
            }
        }
        else if(head2==NULL)
        {
            pol *temp=head1;
            while(temp!=NULL)
            {
                sorted_insert(s3,temp->coeff,temp->expo);
                temp=temp->link;
            }
        }
        else
        {
            pol *p=head1,*q=head2;
            while(p!=NULL && q!=NULL)
            {
                if(p->expo>q->expo)
                {
                    sorted_insert(s3,p->coeff,p->expo);
                    p=p->link;
                }
                else if(p->expo==q->expo)
                {
                    sorted_insert(s3,p->coeff-q->coeff,p->expo);
                    p=p->link;
                    q=q->link;
                }
                else
                {
                    sorted_insert(s3,q->coeff,q->expo);
                    q=q->link;
                }
            }
            while(p!=NULL)
            {
                sorted_insert(s3,p->coeff,p->expo);
                p=p->link;
            }
            while(q!=NULL)
            {
                sorted_insert(s3,-q->coeff,q->expo);
                q=q->link;
            }
        }
    }
    *s1=head1;*s2=head2;
}

void multiplication(pol **s1,pol **s2,pol **s3)
{
    pol *head1=*s1,*head2=*s2;
    if(head1==NULL||head2==NULL)
    {
        printf("The result is zero ");
    }
    else
    {
        pol *p=head1,*q;
        while(p!=NULL)
        {
            q=head2;
            while(q!=NULL)
            {
                sorted_insert(s3,p->coeff*q->coeff,p->expo+q->expo);
                q=q->link;
            }
            p=p->link;
        }
    }
    *s1=head1;*s2=head2;
}

void division(pol **s1,pol **s2,pol **s3)
{
    pol *head1=*s1,*head2=*s2;
    if(head2==NULL)
    {
        printf("The result is undefined ");
    }
    else if(head1==NULL)
    {
        printf("The result is zero ");
    }
    else
    {
        pol *p=head1,*q;
        while(p!=NULL)
        {
            q=head2;
            while(q!=NULL)
            {
                sorted_insert(s3,p->coeff/q->coeff,p->expo-q->expo);
                q=q->link;
            }
            p=p->link;
        }
    }
    *s1=head1; *s2=head2;
}