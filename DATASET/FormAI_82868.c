//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>

#define N 8

void dft(float x_real[], float x_imag[], float X_real[], float X_imag[]) 
{
    int k, n;
    float arg;
    for (k = 0; k < N; k++) 
    {
        X_real[k] = 0;
        X_imag[k] = 0;
        for (n = 0; n < N; n++) 
        {
            arg = 2 * 3.14159265 * k * n / (float) N;
            X_real[k] +=  x_real[n] * cos(arg) + x_imag[n] * sin(arg);
            X_imag[k] += -x_real[n] * sin(arg) + x_imag[n] * cos(arg);
        }
    }
    return;
}

void main(void) 
{
    float x_real[N], x_imag[N], X_real[N], X_imag[N];
    int i;

    printf("Enter the time domain sequence x(n)\n");
    for(i = 0; i < N; i++) 
    {
        scanf("%f", &x_real[i]);
        x_imag[i] = 0;
    }

    dft(x_real, x_imag, X_real, X_imag);

    printf("\n\nX(k) = \n");
    for(i = 0; i < N; i++) 
    {
        printf("(%f) + j(%f)\n", X_real[i], X_imag[i]);
    }
    return;
}