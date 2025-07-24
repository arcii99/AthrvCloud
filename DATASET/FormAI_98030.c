//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

// Function to generate the Fibonacci sequence
int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &n);

    printf("\n");

    for (i=0; i<n; i++) {
        // Generate the ith term of the sequence
        int current_fibonacci = fibonacci(i);

        // Display the visual representation of the current term
        int j, k;
        for (j=0; j<current_fibonacci; j++) {
            for (k=0; k<j; k++) {
                printf("*");
            }
            printf("\n");
        }

        printf("%d\n\n", current_fibonacci);
    }

    return 0;
}