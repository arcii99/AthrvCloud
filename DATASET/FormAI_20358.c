//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);

    int fib[n]; // Declaring an array to store the Fibonacci series
    fib[0] = 0; // Initializing the first two elements of the array
    fib[1] = 1;

    // Generating the Fibonacci series and storing it in the array
    for(i=2; i<n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Printing the Fibonacci sequence visually, representing each number by asterisks(*)
    printf("Here is your Fibonacci sequence:\n");
    for(i=0; i<n; i++) {
        int j;
        for(j=0; j<fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}