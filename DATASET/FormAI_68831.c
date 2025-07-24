//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next, i, j;

    printf("Enter the number of terms for Fibonacci Sequence:\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", first); // print the first term
        } else if (i == 2) {
            printf("%d ", second); // print the second term
        } else {
            next = first + second;
            first = second;
            second = next;
            printf("%d ", next); // print the next term
        }
        // print the visual representation of the sequence
        for (j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}