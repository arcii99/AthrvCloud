//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next, i, j;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    printf("Surreal Fibonacci Sequence:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < first; j++) {
            if (j % 2 == 0) {
                printf("!");
            } else {
                printf("?");
            }
        }
        next = first + second;
        first = second;
        second = next;
        printf("\n");
    }
    return 0;
}