//FormAI DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to generate sinusoidal signal
void generate_signal(float f, float A, float phi, float *x, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        x[i] = A*sin(2*M_PI*f*(float)i + phi);
    }
}

// Function to apply window to signal
void apply_window(float *x, float *w, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        x[i] *= w[i];
    }
}

// Function to perform FFT
void FFT(float *x, int n)
{
    int i,j,k;
    float temp1, temp2, theta;
    int m = log(n)/log(2);

    // Bit reversal operation
    for(i=1, j=0;i<n;i++)
    {
        int bit = n >> 1;
        for(;j>=bit;bit>>=1)
        {
            j -= bit;
        }
        j += bit;
        if(i<j)
        {
            temp1 = x[i];
            x[i] = x[j];
            x[j] = temp1;
        }
    }

    // Cooley-Tuckey Algorithm for FFT
    for(i=1;i<=m;i++)
    {
        int n0 = pow(2,i-1);

        // Calculate "twiddle factor"
        for(j=0;j<n0;j++)
        {
            theta = -2*M_PI*j/n0;
            temp1 = cos(theta);
            temp2 = sin(theta);

            for(k=j;k<n;k+=(2*n0))
            {
                float x_complex_r = x[k];
                float x_complex_i = x[k+n0];
                float y_complex_r = temp1*x_complex_r - temp2*x_complex_i;
                float y_complex_i = temp1*x_complex_i + temp2*x_complex_r;
                x[k] = x_complex_r + y_complex_r;
                x[k+n0] = x_complex_i + y_complex_i;
            }
        }
    }
}

int main()
{
    int n = 64; // Number of samples
    float fs = 1000.0; // Sampling frequency
    float f = 50.0; // Signal frequency
    float A = 1.0; // Signal amplitude
    float phi = M_PI/4; // Phase shift
    float x[n]; // Input signal array
    float w[n]; // Hamming window array
    int i;

    // Generate hamming window
    for(i=0;i<n;i++)
    {
        w[i] = 0.54 - 0.46*cos(2*M_PI*i/n);
    }

    // Generate signal
    generate_signal(f, A, phi, x, n);

    // Apply window to signal
    apply_window(x, w, n);

    // Perform FFT on signal
    FFT(x, n);

    // Print results
    printf("Signal:\n");
    for(i=0;i<n;i++)
    {
        printf("%f\n", x[i]);
    }

    return 0;
}