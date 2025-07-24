//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program generates the first n Fibonacci numbers and then visualizes them in a paranoid style.

int main(void) {
    int n; // Number of Fibonacci numbers to generate
    printf("How many Fibonacci numbers would you like to generate?\n");
    scanf("%d", &n);

    // Check if n is within range and not suspiciously large
    if (n <= 0) {
        printf("Sorry, that's not a valid input. Please enter a positive integer.\n");
        return 1;
    } else if (n > 10000) {
        printf("Your input is suspiciously large. Terminating program.\n");
        return 2;
    }

    // Generate Fibonacci sequence
    unsigned long long int fib[n]; // Use unsigned long long int to avoid overflow for large n
    fib[0] = 0; // First two Fibonacci numbers are always 0 and 1
    fib[1] = 1;

    printf("Generating Fibonacci sequence...\n");
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Visualize Fibonacci sequence in paranoid style
    printf("Visualizing Fibonacci sequence in a paranoid style...\n");
    for (int i = 0; i < n; i++) {
        char asterisks[100]; // Use a max length of 100 for asterisks
        memset(asterisks, '*', fib[i] % 100); // Modulo to avoid extremely long asterisk strings
        printf("%d: %s\n", i+1, asterisks);
    }

    return 0;
}