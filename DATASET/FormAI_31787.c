//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERM 50

void fibonacciSequence(int n)
{
    int firstTerm = 0, secondTerm = 1, nextTerm;

    printf("Fibonacci Sequence for %d terms:\n", n);

    /* Prints the first two terms */
    printf("%d %d ", firstTerm, secondTerm);

    /* Prints the remaining terms */
    for(int i = 2; i < n; i++)
    {
        nextTerm = firstTerm + secondTerm;
        printf("%d ", nextTerm);
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}

int main(void)
{
    int n;

    printf("Welcome to Fibonacci Sequence Visualizer!\n\n");

    printf("Please enter the number of terms that you want to display (must be less than or equal to %d): ", MAX_TERM);
    scanf("%d", &n);

    while (n < 1 || n > MAX_TERM)
    {
        printf("Invalid input! Please enter the number of terms that you want to display (must be less than or equal to %d): ", MAX_TERM);
        scanf("%d", &n);
    }

    printf("\n");

    fibonacciSequence(n);

    printf("\n\nThank you for using Fibonacci Sequence Visualizer!");

    return 0;
}