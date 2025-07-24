//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

void multiply(int *a, int *b, int *c, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i * n + j] = a[i * n + j] * b[i * n + j];
        }
    }
}

int main() {
    int *a, *b, *c;
    int i, n;

    a = (int *)malloc(SIZE * SIZE * sizeof(int));
    b = (int *)malloc(SIZE * SIZE * sizeof(int));
    c = (int *)malloc(SIZE * SIZE * sizeof(int));

    n = SIZE;

    // initialize matrices
    for (i = 0; i < n * n; i++) {
        a[i] = i % n;
        b[i] = (i + 1) % n;
    }

    multiply(a, b, c, n);

    // print matrix
    for (i = 0; i < n * n; i++) {
        if (i % n == 0) {
            printf("\n");
        }
        printf("%d ", c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}