//FormAI DATASET v1.0 Category: Digital signal processing ; Style: minimalist
#include <stdio.h>

#define N 7 // Filter order
#define M 3 // Input buffer size

int main() {
    float b[N+1] = {0.0086, 0.0286, -0.0221, -0.0996, 0.0, 0.0996, 0.0221, -0.0286, -0.0086};
    float x[M] = {-0.2, 0.3, 0.8};
    float y[M] = {0.0};
    int n, m;

    for (m = 0; m < M; m++) {
        // Filter output
        y[m] = 0.0;
        for (n = 0; n <= N; n++) {
            if ((m - n) < 0) {
                break;
            }
            y[m] += b[n] * x[m - n];
        }
    }

    // Print results
    for (m = 0; m < M; m++) {
        printf("y[%d] = %f\n", m, y[m]);
    }

    return 0;
}