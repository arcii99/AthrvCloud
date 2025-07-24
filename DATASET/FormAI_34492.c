//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>

int main() {
    int num_terms, term1 = 0, term2 = 1, next_term;
    
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &num_terms);
    
    printf("Fibonacci Sequence:\n");
    
    for (int i = 0; i < num_terms; i++) {
        if (i <= 1) {
            next_term = i;
        } else {
            next_term = term1 + term2;
            term1 = term2;
            term2 = next_term;
        }
        // Visualization code
        printf("%d:\t", next_term);
        for (int j = 0; j < next_term; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}