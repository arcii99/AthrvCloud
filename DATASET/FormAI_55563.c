//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include<stdio.h>
#include<math.h>

#define PI 3.14159265358979323846

void fft(double* complex, unsigned int n) {
    if(n == 1) return;

    unsigned int half_n = n / 2;

    // Odd and Even number assignments
    double* odd = malloc(half_n * sizeof(double) * 2);
    double* even = malloc(half_n * sizeof(double) * 2);

    for(unsigned int i = 0; i < half_n; i++) 
    {
        even[i*2] = complex[i*2];
        even[i*2+1] = complex[i*2+1];
        odd[i*2] = complex[i*2+1];
        odd[i*2+1] = complex[i*2];
    }

    // Now we recurse on odd and even
    fft(even, half_n);
    fft(odd, half_n);

    // Summation of obtained results to get the output
    for(unsigned int i = 0; i < n; i++) 
    {
        // twiddle factor
        double* twiddle = malloc(sizeof(double) * 2);
        twiddle[0] = cos(-2 * PI * i / n);
        twiddle[1] = sin(-2 * PI * i / n);

        if(i < half_n)
        {
            complex[i*2] = even[i*2] + twiddle[0] * odd[i*2] - twiddle[1] * odd[i*2+1];
            complex[i*2+1] = even[i*2+1] + twiddle[0] * odd[i*2+1] + twiddle[1] * odd[i*2];
        }
        else
        {
            complex[i*2] = even[(i - half_n)*2] - twiddle[0] * odd[(i - half_n)*2 + 1] - twiddle[1] * odd[(i - half_n)*2];
            complex[i*2+1] = even[(i - half_n)*2+1] - twiddle[0] * odd[(i - half_n)*2] + twiddle[1] * odd[(i - half_n)*2 + 1];
        }

        free(twiddle);
    }

    free(even);
    free(odd);
}

int main() 
{
    unsigned int n = 8;
    double complex[n * 2];

    // Set up an input signal
    for(unsigned int i = 0; i < n; i++) 
    {
        complex[i*2] = sin(2 * PI * i / n);
        complex[i*2+1] = 0;
    }

    // Do the Fourier Transform
    fft(complex, n);

    printf("Results of Fourier Transform:\n");

    // print results
    for(unsigned int i = 0; i < n; i++) 
    {
        printf("%f + %f i\n", complex[i*2], complex[i*2+1]);
    }

    return 0;
}