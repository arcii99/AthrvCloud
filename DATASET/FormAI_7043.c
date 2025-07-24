//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include<stdio.h>

int fib(int n);

int main()
{
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibonacci Series: ");
    for(int i=0; i<num; i++)
    {
        printf("%d ", fib(i));
    }
    return 0;
}

int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-1) + fib(n-2);
}