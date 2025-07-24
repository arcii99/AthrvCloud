//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>

int main() {
    int n, f1 = 0, f2 = 1, f3, i, j, k;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < f1; j++) {
            printf(" ");
        }

        for (k = 0; k < f2; k++) {
            printf("*");
        }

        printf("\n");
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    return 0;
}