//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>

int main() {
    int num, first = 0, second = 1, next, i, j, k, l;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("\nFibonacci Series:\n");
    for (i = 0; i < num; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        // Visualize the sequence with asterisks
        for (j = 0; j < next; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}