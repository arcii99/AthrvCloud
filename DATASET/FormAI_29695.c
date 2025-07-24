//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to print the Fibonacci sequence up to the given limit
void printFibonacci(int limit)
{
    // initialize the first two terms of the Fibonacci sequence
    int a = 0, b = 1;

    // print the first two terms of the sequence
    printf("%d, %d, ", a, b);

    // initialize 'sum' to perform the addition operation
    int sum = 0;

    // loop until the sequence limit is reached
    while(sum < limit)
    {
        // calculate the next term of the sequence and print it
        sum = a + b;
        printf("%d, ", sum);

        // swap the values of 'a' and 'b' for the next iteration
        a = b;
        b = sum;
    }
}

int main()
{
    // get the user-defined limit for the sequence
    int limit;
    printf("Enter the limit of the Fibonacci sequence: ");
    scanf("%d", &limit);

    // print the Fibonacci sequence up to the given limit
    printf("\nThe Fibonacci sequence up to %d is:\n\n", limit);
    printFibonacci(limit);

    return 0;
}