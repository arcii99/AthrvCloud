//FormAI DATASET v1.0 Category: Digital signal processing ; Style: all-encompassing
#include <stdio.h>

// Example function for DFT
void DFT(float* x, float* y, int n) {
    int i, j;
    float theta = 2 * 3.14159265359 / n;
    for (i = 0; i < n; i++) {
        y[i] = 0;
        for (j = 0; j < n; j++) {
            y[i] += x[j] * cos(i * j * theta) - x[j] * sin(i * j * theta);
        }
    }
}

int main() {
    int i, n = 8;
    float x[] = {1,1,1,1,0,0,0,0};
    float y[n];

    // Compute DFT
    DFT(x, y, n);

    // Display results
    printf("Discrete Fourier Transform: \n");
    for (i = 0; i < n; i++) {
        printf("%f + %f i\n", y[i], y[i]);
    }
    return 0;
}