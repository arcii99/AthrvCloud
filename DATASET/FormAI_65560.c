//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>

// Function to calculate Fibonacci numbers recursively and print the sequence

void fibonacci(int n) {
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b); // Print the first two numbers of the sequence
    
    for (i = 2; i < n; i++) {
        c = a + b; // Calculate the next number in the sequence
        printf("%d ", c);
        a = b;
        b = c;
    }
}

// Function to print the sequence visually using circles and connecting lines

void fibonacci_visual(int n) {
    int i, a = 0, b = 1, c;
    printf("Sequence: %d %d ", a, b);
    printf("\n\n"); // Add spacing for better visualization
    
    for (i = 2; i < n; i++) {
        c = a + b; // Calculate the next number in the sequence
        
        // Draw the new circle
        printf("         ");
        for (int j = 0; j < c; j++) {
            printf("o");
        }
        printf("\n");
        
        // Connect the circles with lines
        for (int j = 0; j < c; j++) {
            printf("         ");
            if (j == 0) {
                printf("|");
            } else if (j == c-1) {
                printf("\\");
            } else {
                printf("-");
            }
            printf("\n");
        }
        
        // Update the Fibonacci variables
        a = b;
        b = c;
    }
}

// Main function to test the program

int main() {
    int n = 10; // Set the number of terms to print in the sequence
    
    printf("Printing Fibonacci sequence up to %d terms:\n", n);
    fibonacci(n); // Call the standard Fibonacci sequence function
    
    printf("\n\n");
    
    printf("Visualizing Fibonacci sequence up to %d terms:\n", n);
    fibonacci_visual(n); // Call the visual Fibonacci sequence function
    
    return 0;
}