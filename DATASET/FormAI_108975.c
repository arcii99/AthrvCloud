//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#define MAX_TERMS 50 // maximum number of terms to display in the Fibonacci sequence

// function prototypes
void printFibonacci(int);

int main()
{
    int numTerms;

    printf("Enter the number of terms to display in the Fibonacci sequence (1-50): ");
    scanf("%d", &numTerms);

    if(numTerms > 0 && numTerms <= MAX_TERMS) // check if valid input
    {
        printf("Fibonacci sequence for %d terms:\n", numTerms);
        printFibonacci(numTerms);
    }
    else // invalid input
    {
        printf("Invalid input. Number of terms must be between 1 and %d.", MAX_TERMS);
    }
    return 0;
}

// function to print the Fibonacci sequence up to numTerms
void printFibonacci(int numTerms)
{
    int i, first = 0, second = 1, next;

    for(i=0; i<numTerms; i++)
    {
        if(i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}