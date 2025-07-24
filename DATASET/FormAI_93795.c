//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include<stdio.h>

int fibonacci(int n);

int main()
{
    int n, i, sum = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");
    for(i=0 ; i<n ; i++)
    {
        printf("%d ", fibonacci(i));
        sum += fibonacci(i);
    }

    printf("\nSum of the series: %d", sum);

    return 0;
}

int fibonacci(int n)
{
    if(n==0 || n==1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}