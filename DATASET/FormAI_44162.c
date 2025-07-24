//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>

void clearConsole() { // Function to clear the console
    printf("\033c");
}

int main() {
    clearConsole(); // Clear console before starting the program
    printf("My love,\n\n"); // Romantic opening statement

    int n; // Declare integer variable
    printf("Enter the number of terms you want to generate in the Fibonacci sequence: ");
    scanf("%d", &n); // Store user input in the integer variable

    int i; // Declare index variable
    int fib[n]; // Declare Fibonacci sequence array

    fib[0] = 0; // Initialize first two elements in array
    fib[1] = 1;

    for (i = 2; i < n; i++) { // Loop through array and calculate Fibonacci sequence
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\nHere is your Fibonacci sequence, my sweet:\n\n"); // Romantic output statement

    for (i = 0; i < n; i++) { // Loop through array and print each element
        printf("%d ", fib[i]);
    }

    printf("\n\nForever and always,\nYour devoted programmer\n"); // Romantic closing statement

    return 0;
}