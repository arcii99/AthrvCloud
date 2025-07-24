//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

// Function to generate Fibonacci sequence and print in a visual format
void fibonacci(int n) {
    int i, j, k, seq[n];
    
    seq[0] = 0; // Initialize first two numbers of sequence
    seq[1] = 1;
    
    // Generate Fibonacci sequence
    for(i=2; i<n; i++) {
        seq[i] = seq[i-1] + seq[i-2];
    }
    
    printf("\n-----------------------------------------\n");
    printf("FIBONACCI SEQUENCE VISUALIZER\n");
    printf("-----------------------------------------\n");
    
    // Print sequence in a visual format
    for(i=n-1; i>=0; i--) {
        for(j=1; j<=n-i; j++) {
            printf(" ");
        }
        for(k=i; k<n-1; k++) {
            printf("%d ", seq[k]);
        }
        printf("%d\n", seq[k]); // Print last number in sequence
    }
}

int main() {
    int n;
    printf("Enter number of terms in sequence: ");
    scanf("%d", &n);
    
    fibonacci(n); // Call fibonacci function to generate and print sequence
    
    return 0;
}