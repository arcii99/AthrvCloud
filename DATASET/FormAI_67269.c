//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>

#define N 16

int main()
{
    int x[N] = {2, 7, -4, 8, 11, -3, 0, 6, -1, 9, 5, -2, -10, 3, 1, -5};
    int h[N] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8};
    int y[N] = {0};

    for (int n = 0; n < N; n++) {
        for (int k = 0; k <= n; k++) {
            y[n] += h[k] * x[n-k];
        }
    }

    printf("Input x[n]:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", x[i]);
    }
    printf("\n\n");

    printf("Impulse response h[n]:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", h[i]);
    }
    printf("\n\n");

    printf("Output y[n]:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}