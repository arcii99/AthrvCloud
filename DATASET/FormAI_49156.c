//FormAI DATASET v1.0 Category: Digital signal processing ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Pi 3.14159265358979323846

int main()
{
    int n = 10; 

    double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // Input signal

    double y1[n], y2[n], y3[n];  // Output signals


    /* Applying FIR filter with impulse response {1, 2, 3, 2, 1} */
    double h[] = {1, 2, 3, 2, 1};
    for (int i = 0; i < n; i++)
    {
        y1[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            if (i - j < 0)
            {
                y1[i] += h[j]*0; 
            }
            else
            {
                y1[i] += h[j]*x[i-j];
            }
        }
    }


    /* Applying FFT and IFFT to the input signal */
    double re_x[n], im_x[n], re_y[n], im_y[n];
    for (int i = 0; i < n; i++)
    {
        re_x[i] = x[i];
        im_x[i] = 0;
    }

    /* Performing FFT */
    fft(re_x, im_x, re_y, im_y, n);
    
    /* Performing IFFT */
    ifft(re_y, im_y, re_x, im_x, n);

    for (int i = 0; i < n; i++)
    {
        y2[i] = re_x[i]/n;  // Scaling the output of IFFT
    }


    /* Generating a sine wave of frequency 3 Hz */
    for (int i = 0; i < n; i++)
    {
        y3[i] = sin(2*Pi*3*i/n);
    }


    /* Printing the output signals */
    printf("FIR Filter Output:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", y1[i]);
    }

    printf("\nFFT + IFFT Output:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", y2[i]);
    }

    printf("\nSine Wave Output:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", y3[i]);
    }

    return 0;
}


/* Fast Fourier Transform */
void fft(double *re_x, double *im_x, double *re_y, double *im_y, int n)
{
    if (n == 1)  // Base case
    {
        re_y[0] = re_x[0];
        im_y[0] = im_x[0];
        return;
    }

    /* Splitting the input signal into even and odd parts */
    double re_x_even[n/2], im_x_even[n/2], re_x_odd[n/2], im_x_odd[n/2];
    for (int i = 0; i < n/2; i++)
    {
        re_x_even[i] = re_x[2*i];
        im_x_even[i] = im_x[2*i];
        re_x_odd[i] = re_x[2*i+1];
        im_x_odd[i] = im_x[2*i+1];
    }

    /* Recursively computing FFT on even and odd parts */
    double re_y_even[n/2], im_y_even[n/2], re_y_odd[n/2], im_y_odd[n/2];
    fft(re_x_even, im_x_even, re_y_even, im_y_even, n/2);
    fft(re_x_odd, im_x_odd, re_y_odd, im_y_odd, n/2);

    /* Combining the results of FFT on even and odd parts */
    for (int k = 0; k < n/2; k++)
    {
        double cos_k = cos(-2*Pi*k/n);
        double sin_k = sin(-2*Pi*k/n);
        re_y[k] = re_y_even[k] + cos_k*re_y_odd[k] - sin_k*im_y_odd[k];
        im_y[k] = im_y_even[k] + sin_k*re_y_odd[k] + cos_k*im_y_odd[k];
        re_y[k+n/2] = re_y_even[k] - cos_k*re_y_odd[k] + sin_k*im_y_odd[k];
        im_y[k+n/2] = im_y_even[k] - sin_k*re_y_odd[k] - cos_k*im_y_odd[k];
    }
}


/* Inverse Fast Fourier Transform */
void ifft(double *re_y, double *im_y, double *re_x, double *im_x, int n)
{
    if (n == 1)  // Base case
    {
        re_x[0] = re_y[0];
        im_x[0] = im_y[0];
        return;
    }

    /* Splitting the input signal into even and odd parts */
    double re_y_even[n/2], im_y_even[n/2], re_y_odd[n/2], im_y_odd[n/2];
    for (int i = 0; i < n/2; i++)
    {
        re_y_even[i] = re_y[2*i];
        im_y_even[i] = im_y[2*i];
        re_y_odd[i] = re_y[2*i+1];
        im_y_odd[i] = im_y[2*i+1];
    }

    /* Recursively computing IFFT on even and odd parts */
    double re_x_even[n/2], im_x_even[n/2], re_x_odd[n/2], im_x_odd[n/2];
    ifft(re_y_even, im_y_even, re_x_even, im_x_even, n/2);
    ifft(re_y_odd, im_y_odd, re_x_odd, im_x_odd, n/2);

    /* Combining the results of IFFT on even and odd parts */
    for (int k = 0; k < n/2; k++)
    {
        double cos_k = cos(2*Pi*k/n);
        double sin_k = sin(2*Pi*k/n);
        re_x[k] = re_x_even[k] + cos_k*re_x_odd[k] - sin_k*im_x_odd[k];
        im_x[k] = im_x_even[k] + sin_k*re_x_odd[k] + cos_k*im_x_odd[k];
        re_x[k+n/2] = re_x_even[k] - cos_k*re_x_odd[k] + sin_k*im_x_odd[k];
        im_x[k+n/2] = im_x_even[k] - sin_k*re_x_odd[k] - cos_k*im_x_odd[k];
    }
}