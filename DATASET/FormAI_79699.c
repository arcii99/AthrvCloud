//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void fibonacciSeries(int);
int fibonacciNumber(int);

int main()
{
    int numOfTerms;
    printf("Enter the number of terms: ");
    scanf("%d", &numOfTerms);

    printf("Fibonacci Series:\n");
    fibonacciSeries(numOfTerms);

    return 0;
}

/* Function to print the Fibonacci Series */
void fibonacciSeries(int num)
{
    int i;
    for (i = 1; i <= num; i++)
    {
        printf("%d ", fibonacciNumber(i));
    }
}

/* Function to return the nth Fibonacci Number recursively */
int fibonacciNumber(int num)
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
        return fibonacciNumber(num - 1) + fibonacciNumber(num - 2);
    }
}