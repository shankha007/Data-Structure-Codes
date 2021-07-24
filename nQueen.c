#include<stdio.h>
#include<conio.h>
#include<math.h>

int a[30],count=0;
//row=index and column=value

int place(int pos)
{
    int i;
    for(i=1;i<pos;i++)
    {
        if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
            return 0;
    }
    return 1;
}

void print_sol(int n)
{
    int i,j;
    count++;
    printf("\n\nSolution #%d:\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void queen(int n)
{
    int k=1; // We are taking it as 1st Queen
    a[k]=0; // we are storing the 1st queen at 0th col
    while(k!=0)
    {
        do
        {
            a[k]++;
        } while((a[k]<=n)&&!place(k));
        if(a[k]<=n)
        {
            if(k==n) // if k is equals to no of queens(n) then print the solution
                print_sol(n);
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
            k--;
    }
}

void main()
{
    int n;// n is the no of queens
    printf("Enter the number of Queens\n");
    scanf("%d",&n);
    queen(n);
    printf("\nTotalsolutions=%d",count);
}