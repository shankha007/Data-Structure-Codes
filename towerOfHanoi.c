#include<stdio.h>

void move(int, char, char, char);

int main()
{
    int n;
    printf("\n Enter the no. of rings:");
    scanf("%d", &n);
    move (n,'A','B','C');
    return 0;
}

void move(int n, char source, char dest, char spare)
{
    if(n == 1)
        printf("\n Move from %c to %c", source, dest);
    else
    {
        move(n-1,source, spare, dest);
        move(1, source, dest, spare);
        move(n-1,spare, dest, source);
    }
}