#include<stdio.h>
#include<stdlib.h>

void read_array(int*,int);
void print_array(int*,int);
void sort_array(int*,int);

void main()
{
    system("clear");
    int a[20],n;
    printf("\n Enter the nmber of elements:");
    scanf("%d",&n);
    read_array(a,n);
    print_array(a,n);
    sort_array(a,n);
}

/*Reading the array*/
void read_array(int* a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n Enter the %dth element:",i+1);
        scanf("%d",(a+i));
    }
}

/*Printing the array*/
void print_array(int* a,int n)
{
    int i;
    printf("\n Now the array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}

/*Sorting the array*/
void sort_array(int* a, int n)
{
    int c,d,f,swap;
    for(c=0;c<n-1;c++)
    {
        printf("\n%dth pass:",c+1);
        for(d=0;d<n-c-1;d++)
        {
            if(a[d]>=a[d+1])
            {
                swap=a[d];
                a[d]=a[d+1];
                a[d+1]=swap;
            }
            printf("\n");
            for(f=0;f<n;f++)
                printf("\t%d",a[f]);
        }
    }
    printf("\n The sorted array is:\n");
    for(c=0;c<n;c++)
        printf("%d\t",a[c]);
}