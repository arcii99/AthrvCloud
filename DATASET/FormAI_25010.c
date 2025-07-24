//FormAI DATASET v1.0 Category: Digital signal processing ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// function for digital signal processing transformation
void DSP_Transform(int N, double *x, double *Xr, double *Xi){
    double T[N];
    double theta;

    // calculate the transformation coefficients
    for(int k = 0; k < N; k++){
        for(int n = 0; n < N; n++){
            theta = (-2 * PI * n * k) / N;
            T[k] += x[n] * cos(theta);
            T[k] -= x[n] * sin(theta);
        }
        Xr[k] = T[k] / N;
        Xi[k] = T[k] / N;
    }
}

int main(){

    // prepare the input signal
    int N = 32;
    double x[N];
    for(int n = 0; n < N; n++){
        x[n] = cos((2 * PI * 10 * n) / N) + cos((2 * PI * 20 * n) / N) + cos((2 * PI * 30 * n) / N);
    }

    // allocate memory for the result
    double Xr[N], Xi[N];

    // perform the DSP transformation
    DSP_Transform(N, x, Xr, Xi);

    // print the result
    printf("DSP transformation result:\n");
    for(int k = 0; k < N; k++){
        printf("X[%d] = %.2f + %.2fi\n", k, Xr[k], Xi[k]);
    }

    return 0;
}