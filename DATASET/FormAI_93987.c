//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>

int main() {
    printf("\n\n\t\t*** Fibonacci Sequence Visualizer ***\n\n");
    
    // Get user input for number of terms
    int num_terms;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &num_terms);
    
    // Check for valid input
    if (num_terms < 0) {
        printf("Invalid input! Number of terms must be greater than or equal to zero.\n");
        return 0;
    }
    
    // Generate sequence and print
    int prev_term = 0, curr_term = 1, next_term, i;
    
    printf("\nSequence: ");
    if (num_terms == 0) {
        printf("0\n");
    } else if (num_terms == 1) {
        printf("0, 1\n");
    } else {
        printf("0, 1, ");
        for (i = 2; i < num_terms; i++) {
            next_term = prev_term + curr_term;
            prev_term = curr_term;
            curr_term = next_term;
            
            // Print term as asterisks for visual representation
            int j;
            printf("*");
            for (j = 0; j < next_term; j++) {
                printf("*");
            }
            printf(", ");
        }
        next_term = prev_term + curr_term;
        printf("*");
        for (i = 0; i < next_term; i++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}