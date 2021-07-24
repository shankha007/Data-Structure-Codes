#include<stdio.h>
#include<stdlib.h>

void scan_array(int*,int);
void print_array(int*,int);
void search_array(int*,int);

void main()
{
    int n,a[20];
    printf("\n Enter the no. of terms in the array:");
    scanf("%d",&n);
    scan_array(&a,n);
    print_array(&a,n);
    search_array(&a,n);
}

/*Scanning The Array*/
void scan_array(int* a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n Enter the %dth element:",(i+1));
        scanf("%d",(a+i));
    }
}

/*Printing The Array*/
void print_array(int* a, int n)
{
    int i;
    printf("\n So the Array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(a+i));
}

/*Linear Search Starts*/
void search_array(int* a, int n)
{
    int i,search,flag=0;
    printf("\n Enter the element to Search:");
    scanf("%d",&search);
    for(i=0;i<n;i++)
    {
        if(*(a+i)==search)
        {
            printf("\n %d Found at Position: %d",search,(i+1));
            flag=1;
        }
    }
    if(flag==0)
        printf("\n %d is not in the array.",search);
}