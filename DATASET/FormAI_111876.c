//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complete
#include <stdio.h>

#define N 10

void convolve(int x[], int h[], int y[], int n, int m);

int main(void) {
    int x[N] = {2, 3, 5, 7, 1, 4, 1, 3, 5, 7};
    int h[N] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1};
    int y[N+N-1];
    int i;
    
    printf("Input Signal (x[n]):\n");
    for(i = 0; i < N; i++) {
        printf("%d ", x[i]);
    }
    
    printf("\n\nImpulse Response (h[n]):\n");
    for(i = 0; i < N; i++) {
        printf("%d ", h[i]);
    }
    
    convolve(x, h, y, N, N);
    
    printf("\n\nConvolved Output (y[n]):\n");
    for(i = 0; i < N+N-1; i++) {
        printf("%d ", y[i]);
    }
    
    return 0;
}

void convolve(int x[], int h[], int y[], int n, int m) {
    int i, j;
    
    for(i = 0; i < n+m-1; i++) {
        y[i] = 0;
        for(j = 0; j < n; j++) {
            if(i-j >= 0 && i-j < m) {
                y[i] += x[j] * h[i-j];
            }
        }
    }
}