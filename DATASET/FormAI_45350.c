//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>

int fibonacci(int num)
{
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        return fibonacci(num-1) + fibonacci(num-2);
}

void printFibonacci(int n)
{
    printf("Fibonacci sequence for %d terms:\n", n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
}

int main()
{
    int n;
    printf("Enter the number of terms to display: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}