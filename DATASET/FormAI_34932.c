//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

// Function to print Fibonacci sequence up to given limit
void printFibonacci(int limit)
{
    int a = 0, b = 1, c;

    printf("%d, %d, ", a, b);

    for (int i = 3; i <= limit; i++) {
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;
    }
}

int main()
{
    int limit;

    printf("Enter the limit of Fibonacci sequence: ");
    scanf("%d", &limit);

    printf("Fibonacci sequence up to limit %d is: ", limit);
    printFibonacci(limit);

    return 0;
}