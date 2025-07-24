//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8
#define PI 3.14159265358979323846

int main()
{
    float x[N] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    float y[N] = { 0 };
    float c, s;
    int n, k;

    for (n = 0; n < N; n++) {
        y[n] = 0;
        for (k = 0; k < N; k++) {
            c = cos(2 * PI * n * k / N);
            s = sin(2 * PI * n * k / N);
            y[n] += x[k] * c - x[(N - k) % N] * s;
        }
    }

    printf("x[n]\ty[n]\n");
    for (n = 0; n < N; n++) {
        printf("%f\t%f\n", x[n], y[n]);
    }

    return 0;
}