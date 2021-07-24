#include<stdio.h>
#include<stdlib.h>

void scan_array(int*,int);
void print_array(int*,int);
void sort_array(int*,int);

void main()
{
    system("clear");
    int n,a[20];
    printf("\n Enter the no. of elements:");
    scanf("%d",&n);
    scan_array(a,n);
    print_array(a,n);
    sort_array(a,n);
}

/*Scanning the Array*/
void scan_array(int* a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n Enter the %dth element:",i+1);
        scanf("%d",(a+i));
    }
}

/*Printing the Array*/
void print_array(int* a, int n)
{
    int i;
    printf("\n So, the array is:\n");
    for(i=0;i<n;i++)
        printf("\t%d",*(a+i));
}

/*Sorting the array*/
void sort_array(int* a, int n)
{
    int i,j,k,pos,swap;
    for(i=0;i<n-1;i++)
    {
        printf("\n Pass %d:",i+1);
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)<=*(a+pos))
                pos=j;
            if(pos!=i)
            {
                swap=*(a+i);
                *(a+i)=*(a+pos);
                *(a+pos)=swap;
            }
            printf("\n");
            for(k=0;k<n;k++)
                printf("\t%d",*(a+k));
        }
        printf("\n");
        for(k=0;k<n;k++)
            printf("\t%d",*(a+k));
    }
    printf("\n So, the Sorted array is:\n");
    for(i=0;i<n;i++)
        printf("\t%d",*(a+i));
}