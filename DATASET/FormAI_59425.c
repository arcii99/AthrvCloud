//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);

    int first = 0, second = 1;
    printf("Fibonacci Sequence up to %d terms:\n", n);
    if (n == 1) {
        printf("%d", first);
    } else if (n == 2) {
        printf("%d %d", first, second);
    } else {
        printf("%d %d ", first, second);
        int next;
        for (int i = 2; i < n; i++) {
            next = first + second;
            printf("%d ", next);
            first = second;
            second = next;
        }
    }
    printf("\n");

    return 0;
}