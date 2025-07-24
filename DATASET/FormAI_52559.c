//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);
    // Initialize first two terms of the sequence
    int first = 0, second = 1;
    // Create an array to store the sequence
    int* fibseq = (int*)malloc(n * sizeof(int));
    if (fibseq == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }
    // Compute and store the Fibonacci sequence
    for (i = 0; i < n; i++) {
        fibseq[i] = first;
        int sum = first + second;
        first = second;
        second = sum;
    }
    // Visualize the Fibonacci sequence using ASCII characters
    printf("Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        int num = fibseq[i];
        if (num == 0) {
            printf("-\n");
            continue;
        }
        int j;
        for (j = 0; j < num; j++) {
            printf("*");
        }
        printf("\n");
    }
    free(fibseq);
    return 0;
}