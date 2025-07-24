//FormAI DATASET v1.0 Category: Recursive ; Style: ephemeral
#include <stdio.h>

// This recursive function prints the fibonacci sequence backwards
void printFibonacciBackwards(int num)
{
    if (num == 0)
    {
        return;
    }
    else if (num == 1)
    {
        printf("1 ");
        return;
    }
    else
    {
        int fib = fibonacci(num);
        printf("%d ", fib);
        printFibonacciBackwards(num - 1);
    }
}

// This recursive function calculates the nth fibonacci number
int fibonacci(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main() 
{
    int num;
    printf("Enter the number of terms you want to print: ");
    scanf("%d", &num);
    printf("The fibonacci sequence backwards is: ");
    printFibonacciBackwards(num);
    printf("\n");
    return 0;
}