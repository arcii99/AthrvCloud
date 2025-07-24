//FormAI DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>

#define N 8

int main() {
    int i, j;
    float x[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    float y[N] = {0};

    // Applying a moving average filter
    for (i = 0; i < N; i++) {
        for (j = -2; j <= 2; j++) {
            if(i+j >= 0 && i+j < N) {
                y[i] += x[i+j];
            }
        }
        y[i] /= 5;
    }

    //Printing the input and output signals
    printf("Input Signal x: \n");
    for (i = 0; i < N; i++) {
        printf("%.1f ", x[i]);
    }

    printf("\n\nOutput Signal y: \n");
    for (i = 0; i < N; i++) {
        printf("%.2f ", y[i]);
    }
    printf("\n");
    return 0;
}