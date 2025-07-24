//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to calculate nth Fibonacci number
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int num;

    printf("Welcome to the Fibonacci visualizer!\n\n");
    printf("Please enter a number to generate its Fibonacci sequence: ");
    scanf("%d", &num);

    printf("\n\n");

    int prev1 = 0, prev2 = 1, current;

    for (int i = 0; i < num; i++)
    {
        current = fibonacci(i);
        printf("%d", current);

        // Adding some fun visual effects
        if (current % 3 == 0)
        {
            printf(" Grammie!");
        }
        if (current % 5 == 0)
        {
            printf(" Rock on!");
        }
        if (current % 7 == 0)
        {
            printf(" Woot woot!");
        }

        printf("\n");
    }

    return 0;
}