//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci Series: ");
    for (i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    printf("\n\nFibonacci Sequence Visualizer: \n");

    for (i = 1; i <= n; i++) {
        printf("*");
        if (i == 1)
            printf(" 1");
        else if (i == 2)
            printf(" 1");
        else {
            next = first + second;
            first = second;
            second = next;
            printf(" %d", next);
        }
        printf("\n");
    }
    return 0;
}