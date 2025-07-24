//FormAI DATASET v1.0 Category: Recursive ; Style: interoperable
#include<stdio.h>

int fibonacci(int n);

int main()
{
    int n, i, flag = 0;

    printf("Enter the number of terms you want in the Fibonacci series:\n");
    scanf("%d", &n);

    if(n<=0)
    {
        printf("Number of terms in the Fibonacci series must be greater than zero.\n");
        flag = 1;
    }

    if(flag == 0)
    {
        printf("The first %d terms of the Fibonacci series are:\n", n);
        for(i=0; i<n; i++)
        {
            printf("%d ", fibonacci(i));
        }
    }
    return 0;
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return(fibonacci(n-1) + fibonacci(n-2));
    }
}