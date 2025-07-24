//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include<stdio.h>
#include<math.h>

#define PI 3.14159265359

int main()
{
    int n, k, i;
    float x[50], real[50], imag[50], mag[50];

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    printf("Enter the values of x[n]: ");
    for(i=0; i<n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    //Perform Discrete Fourier Transform
    for(i=0; i<n; i++)
    {
        real[k] += x[i] * cos(2*PI*k*i/n); //Real part of DFT
        imag[k] -= x[i] * sin(2*PI*k*i/n); //Imaginary part of DFT
    }

    mag[k] = sqrt(real[k]*real[k] + imag[k]*imag[k]); //Magnitude of DFT

    //Display results
    printf("\nDFT of x[%d]:\n", k);
    printf("Real part = %f\n", real[k]);
    printf("Imaginary part = %f\n", imag[k]);
    printf("Magnitude = %f\n", mag[k]);

    return 0;
}