//FormAI DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define N 10

void filter(int *x, int *y, int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        y[i] = b[0] * x[i];
        for (int j = 1; j < N; j++) {
            if (i - j >= 0 && j < n) {
                y[i] += b[j] * x[i - j];
            }
            if (j < n && i < n) {
                y[i] -= a[j] * y[i - j];
            }
        }
    }
}

int main() {
    int x[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int y[N] = {0};
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    filter(x, y, a, b, N);

    printf("Input:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", x[i]);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", y[i]);
    }

    return 0;
}