//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

int main() {
    int n, i;
    long long int fibonacci[50];

    printf("Enter the number of terms in the sequence (max 50): ");
    scanf("%d", &n);

    // Initializing the first two terms of the sequence
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Generating the other terms of the sequence
    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    // Printing the sequence in a visual format
    printf("Fibonacci Sequence:\n");

    for (i = 0; i < n; i++) {
        printf("%d. ", i+1);
        for (int j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }
        printf(" (%lld)\n", fibonacci[i]);
    }

    return 0;
}