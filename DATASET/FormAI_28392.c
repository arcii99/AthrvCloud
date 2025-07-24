//FormAI DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>

#define N 8 

int main() {
    int x[N], y[N], z[N], i, j, k;

    printf("Enter values for x[]: \n");
    for (i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter values for y[]: \n");
    for (i = 0; i < N; i++) {
        scanf("%d", &y[i]);
    }

    // Convolution of x[] and y[] to obtain z[]
    for (i = 0; i < N; i++) {
        z[i] = 0;
        for (j = 0; j < N; j++) {
            k = i - j;
            if (k < 0) {
                k += N;
            }
            z[i] += x[j] * y[k];
        }
    }

    printf("The output z[] is: \n");
    for (i = 0; i < N; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");

    return 0;
}