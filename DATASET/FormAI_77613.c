//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

// Function to print a Fibonacci Sequence Bar Chart
void printBarChart(int num, int arr[]) {
    printf("\nFibonacci Sequence Bar Chart: \n");

    for (int i = 0; i < num; i++) {
        printf("%2d | ", i);

        // Print a '*' for each unit in the sequence
        for (int j = 0; j < arr[i]; j++)
            printf("*");

        printf("\n");
    }
}

int main() {
    int n;

    // Get number of terms from user input
    printf("Enter number of terms in the sequence: ");
    scanf("%d", &n);

    // Initialize the first two terms of the sequence
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Calculate each subsequent term in the sequence
    for (int i = 2; i < n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    // Print the Fibonacci Sequence
    printf("\nFibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }

    // Print a bar chart of the sequence
    printBarChart(n, fib);

    return 0;
}