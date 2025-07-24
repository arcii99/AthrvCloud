//FormAI DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>

#define N 10
#define M 5

// Defining a protected style function
__attribute__((__always_inline__, __flatten__)) static inline 
void DSP_multiply(const int* const x, const int* const y, int* const result) {
    for(int i = 0; i < M; i++) {
        result[i] = x[i] * y[i];
    }
}

int main() {
    int a[N] = {1,2,3,4,5,6,7,8,9,10};
    int b[M] = {3,4,5,6,7};
    int c[M];

    DSP_multiply(a, b, c);

    printf("Result of DSP_multiply: \n");

    for(int i = 0; i < M; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}