//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include<stdio.h>

int fibonacci(int n)
{
    if(n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i, c=0;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Fibonacci sequence terms are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", fibonacci(c));
        c++;
    }
    return 0;
}