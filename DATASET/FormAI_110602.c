//FormAI DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    int i;
    double theta;
    double x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Input signal
    double y[10]; // Output signal

    // Applying a low-pass filter
    double c = 0.1; // Cut-off frequency
    double a = exp(-c * PI); // Filter coefficient
    double b = 1 - a; // Filter coefficient

    y[0] = b * x[0];
    for(i = 1; i < 10; i++)
    {
        y[i] = b * x[i] + a * y[i-1];
    }

    // Applying a window function
    double w[10];
    for(i = 0; i < 10; i++)
    {
        theta = PI * i / (10.0 - 1.0);
        w[i] = 0.5 - 0.5 * cos(theta);
        y[i] = y[i] * w[i];
    }

    // Applying a Fast Fourier Transform
    int N = 10; // Number of samples
    double re[N];
    double im[N];
    for(i = 0; i < N; i++)
    {
        re[i] = y[i];
        im[i] = 0;
    }
    fft(re, im, N);

    // Printing the results
    for(i = 0; i < N; i++)
    {
        printf("X[%d] = %.2f + j%.2f\n", i, re[i], im[i]);
    }

    return 0;
}

void fft(double* re, double* im, int N)
{
    int i, j, k, n;
    double tr, ti;

    j = 0;
    for(i = 0; i < N; i++)
    {
        if(j > i)
        {
            tr = re[j];
            ti = im[j];
            re[j] = re[i];
            im[j] = im[i];
            re[i] = tr;
            im[i] = ti;
        }
        n = N/2;
        while((n >= 1) && (j >= n))
        {
            j = j - n;
            n = n/2;
        }
        j = j + n;
    }

    double c, s;
    int l, m;
    int scale = log2(N);

    for(n = 1; n <= scale; n++)
    {
        m = pow(2, n);
        l = m/2;

        for(k = 0; k < l; k++)
        {
            c = cos(-2 * PI * k / m);
            s = sin(-2 * PI * k / m);

            for(i = k; i < N; i += m)
            {
                j = i + l;
                tr = c * re[j] - s * im[j];
                ti = c * im[j] + s * re[j];
                re[j] = re[i] - tr;
                im[j] = im[i] - ti;
                re[i] = re[i] + tr;
                im[i] = im[i] + ti;
            }
        }
    }
}