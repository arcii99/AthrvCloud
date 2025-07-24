//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

// Function to generate Fibonacci sequence up to n terms
void generateFibonacci(int n)
{
    int first = 0, second = 1, next, i;

    printf("%d, %d", first, second);

    for(i = 3; i <= n; i++)
    {
        next = first + second;
        printf(", %d", next);
        first = second;
        second = next;
    }
}

int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The Fibonacci sequence up to %d terms is:\n", n);

    generateFibonacci(n);

    return 0;
}