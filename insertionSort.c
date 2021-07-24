#include<stdio.h>
#include<stdlib.h>

void read_array(int*,int);
void print_array(int*,int);
void sort_array(int*,int);

void main()
{
    system("clear");
    int a[20],n;
    printf("\n Enter the number of elements:");
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
    int i,j,k,key;
    for(i=1;i<n;i++)
    {
        printf("\n %dth Pass:",i);
        key=a[i];
        j=i-1;
        while((j>=0)&&(a[j])>=key)
        {
            a[j+1]=a[j];
            j=j-1;
            printf("\n");
            for(k=0;k<n;k++)
                printf("\t%d",a[k]);
            printf("\n");
        }
        a[j+1]=key;
        printf("\n");
        for(k=0;k<n;k++)
            printf("\t%d",a[k]);

    }
    printf("\n The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);
}