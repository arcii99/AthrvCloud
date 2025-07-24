//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

int main() {
    int n, i, term1 = 0, term2 = 1, nextTerm;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    
    // Print the first two terms
    printf("%d, %d, ", term1, term2);
    
    // Loop to generate the remaining terms
    for (i = 3; i <= n; ++i) {
        // Calculate the next term
        nextTerm = term1 + term2;
        // Print the next term
        printf("%d, ", nextTerm);
        // Update the terms
        term1 = term2;
        term2 = nextTerm;
    }
    return 0;
}