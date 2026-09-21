#include<stdio.h>
int fib(int n);
int main()
{
    int num,i,sum=0,element;
    printf("Enter Number of elements :");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        element=fib(i);
        printf("%d  ",element); 
        sum=sum+element;
    }
    printf("\nSum = %d",sum);
    
}
int fib(int n)
{
        if (n==0)
        return 0;
        else if (n==1)
        return 1;
        else 
        return fib(n-1)+fib(n-2);
}