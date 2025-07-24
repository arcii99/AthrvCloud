//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    // Corner case when n=0
    if (n == 0) {
        printf("Fibonacci sequence: \n");
        return 0;
    }
    
    int fib_sequence[n];
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    
    // Generate the Fibonacci sequence up to n terms
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }
    
    printf("Fibonacci sequence: \n");
    // Print the sequence in a visualizer format
    for (int i = 0; i < n; i++) {
        printf("%d: ", i+1);
        for (int j = 0; j < fib_sequence[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}