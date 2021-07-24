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

/*Scanning the array*/
void scan_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n Enter the %dth element:",(i+1));
        scanf("%d",(a+i));
    }
}

/*Printing The Array*/
void print_array(int* a,int n)
{
    int i;
    printf("\n So the Array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",*(a+i));
}

/*Binary Search Starts*/
void search_array(int* a,int n)
{
    int i,search,low,mid,high,flag=0;
    printf("\n Enter the Element to Search:");
    scanf("%d",&search);
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(search == *(a+mid))
        {
            printf("\n %d found at Position: %d",search,(mid+1));
            flag=1;
            break;
            }
        else if(search>*(a+mid))
        {
            low=mid+1;
            mid=(low+high)/2;
        }
        else
        {
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    if(flag==0)
    {
        printf("\n %d is not in the array",search);
    }
}