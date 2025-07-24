//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>

int main() {
    int n, prev = 0, curr = 1, next = 1;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("0\n1\n");

    for(int i=2; i<n; i++) {
        prev = curr;
        curr = next;
        next = prev + curr;
        printf("%d\n", next);
    }

    // Visualization
    printf("\nFibonacci Sequence as a pyramid:\n\n");
    prev = 0, curr = 1, next = 1;
    int rows = 1, column = 0;

    for(int i=0; i<n; i++) {
        if(column == rows) {
            printf("\n");
            rows++;
            column = 0;
        }
        printf("%d ", next);
        prev = curr;
        curr = next;
        next = prev + curr;
        column++;
    }
    return 0;
}