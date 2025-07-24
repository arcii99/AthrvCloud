//FormAI DATASET v1.0 Category: Digital signal processing ; Style: random
#include <stdio.h>
#include <math.h>

#define N 256

void dft(double *input, double *output_real, double *output_imag);

int main()
{
    double input[N];
    double output_real[N];
    double output_imag[N];
    
    // Generate input signal (100 Hz sine wave)
    for(int i = 0; i < N; i++)
    {
        input[i] = sin(2*M_PI*100*i/N);
    }
    
    // Perform Discrete Fourier Transform
    dft(input, output_real, output_imag);
    
    // Print Fourier coefficients
    printf("Frequency (Hz)\tReal\tImaginary\n");
    for(int i = 1; i < N/2; i++)
    {
        double freq = i*N/2*M_PI;
        printf("%.2f\t%e\t%e\n", freq, output_real[i], output_imag[i]);
    }
    
    return 0;
}

void dft(double *input, double *output_real, double *output_imag)
{
    for(int k = 0; k < N; k++)
    {
        output_real[k] = 0;
        output_imag[k] = 0;
        for(int n = 0; n < N; n++)
        {
            output_real[k] += input[n]*cos(2*M_PI*k*n/N);
            output_imag[k] -= input[n]*sin(2*M_PI*k*n/N);
        }
    }
}