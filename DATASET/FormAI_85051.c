//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>

int main() {
    int n, num1 = 0, num2 = 1, next, i, j;

    printf("Enter the number of terms:");
    scanf("%d", &n);

    printf("\nFibonacci Series up to %d terms:\n", n);

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d, ", num1);
            continue;
        }
        if (i == 2) {
            printf("%d, ", num2);
            continue;
        }
        next = num1 + num2;
        num1 = num2;
        num2 = next;
        printf("%d, ", next);
    }

    printf("\n\nFibonacci Series visualized:\n");

    for (i = 1; i <= n; i++) {
        printf("|");
        for (j = 1; j <= i; j++) {
            printf(" %d", j);
        }
        printf(" |\n");
    }

    return 0;
}