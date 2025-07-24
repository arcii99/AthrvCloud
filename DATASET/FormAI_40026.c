//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#define LEN 1000000
#define ITER 10

float rand_float() {
    return (float)rand() / RAND_MAX;
}

void perform_computation(float *A, int *B, float *C, int n) {
    int i, j, idx1, idx2;
    float val;
    for (i = 0; i < n; i++) {
        idx1 = (int)(rand_float() * LEN);
        idx2 = (int)(rand_float() * LEN);
        for (j = 0; j < ITER; j++) {
            val = A[idx1] + A[idx2];
            B[i] |= (int)(val > C[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    srand(42);
    int i, n = LEN;
    float *A, *C;
    int *B;
    A = (float*)malloc(n * sizeof(float));
    C = (float*)malloc(n * sizeof(float));
    B = (int*)calloc(n, sizeof(int));
    
    for (i = 0; i < n; i++) {
        A[i] = rand_float() * 10;
        C[i] = rand_float() * 5 + 10;
    }
    for (i = 0; i < ITER; i++) {
        perform_computation(A, B, C, n);
    }
    for (i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}