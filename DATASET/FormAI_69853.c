//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to generate the Fibonacci Sequence
void fibonacci_sequence_visualizer(int n)
{
    int a = 0, b = 1, c, i;

    // Print the first two numbers of the sequence
    printf("%d %d ", a, b);

    // Generate and print the remaining numbers of the sequence
    for (i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main()
{
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of terms you would like to visualize: ");
    scanf("%d", &n);

    // Check for valid input
    if (n < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("\nHere is the Fibonacci Sequence up to the %dth term:\n", n);
    fibonacci_sequence_visualizer(n);

    printf("\n\nThank you for using the Fibonacci Sequence Visualizer!\n");

    return 0;
}