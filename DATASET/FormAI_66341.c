//FormAI DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979

int main()
{
    int n = 8; //number of input samples
    float x[8] = {1, 2, 2, 1, -1, -2, -2, -1}; //input sequence
    float y[8]; //output sequence

    //apply discrete Fourier transform (DFT)
    for(int k = 0; k < n; k++)
    {
        float re = 0, im = 0; //real and imaginary parts
        for(int j = 0; j < n; j++)
        {
            float theta = 2 * PI * k * j / n;
            re += x[j] * cos(theta);
            im -= x[j] * sin(theta);
        }
        y[k] = sqrt(re * re + im * im); //magnitude spectrum
    }

    //print input and output sequences
    printf("x(n) = ");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f ", x[i]);
    }
    printf("\n");

    printf("y(n) = ");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f ", y[i]);
    }
    printf("\n");

    return 0;
}