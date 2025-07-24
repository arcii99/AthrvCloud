//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

void displayFibonacci(int num);

int main(void)
{
    int num;
    
    printf("Enter the number of terms in Fibonacci Sequence to display: ");
    scanf("%d", &num);
    
    displayFibonacci(num);
    
    return 0;
}

void displayFibonacci(int num)
{
    int i, fib[num];
    
    fib[0] = 0;
    fib[1] = 1;
    
    for(i=2; i<num; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    printf("\n");
    printf("Fibonacci sequence for %d terms:\n\n", num);
    
    for(i=0; i<num; i++)
    {
        printf("%d, ", fib[i]);
    }
    
    printf("\n");
}