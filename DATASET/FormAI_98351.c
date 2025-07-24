//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>

int main() {
    int n, fib[100];
    
    printf("Let's generate the Fibonacci sequence! \n");
    
    // Receive user input for n number of terms to generate
    printf("How many terms should we generate? (up to 100): ");
    scanf("%d", &n);
    
    // Error handling for invalid input
    if (n <= 0 || n > 100) {
        printf("Invalid input. Please try again with a number between 1 and 100.");
    } else {
        // Initial values for the sequence
        fib[0] = 0;
        fib[1] = 1;
        
        // Generate the sequence based on user input
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        
        // Print the sequence with visual aides
        printf("Here are your %d terms: \n\n", n);
        for (int j = 0; j < n; j++) {
            printf("%d ", fib[j]);
            for (int k = 0; k < fib[j]; k++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}