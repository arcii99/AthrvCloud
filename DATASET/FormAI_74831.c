//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

int main() {
    int limit, i, fibo = 0, first = 0, second = 1;

    printf("Enter the limit to generate fibonacci sequence:\n");
    scanf("%d", &limit);

    printf("Fibonacci Sequence: ");

    if (limit == 1) {
        printf("%d", first);
    }
    else if (limit >= 2) {
        printf("%d %d ", first, second);
        for (i = 2; i < limit; i++) {
            fibo = first + second;
            first = second;
            second = fibo;

            // Visualizing Fibonacci Sequence
            int j;
            for (j = 0; j < fibo; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}