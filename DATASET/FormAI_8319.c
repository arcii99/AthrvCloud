//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 1024

void fft(double* x_re, double* x_im, int n)
{
    if(n == 1)
        return;

    double* x1_re = (double*)malloc(sizeof(double) * n/2);
    double* x1_im = (double*)malloc(sizeof(double) * n/2);
    double* x2_re = (double*)malloc(sizeof(double) * n/2);
    double* x2_im = (double*)malloc(sizeof(double) * n/2);

    for(int i=0; i<n/2; i++)
    {
        x1_re[i] = x_re[2*i];
        x1_im[i] = x_im[2*i];
        x2_re[i] = x_re[2*i+1];
        x2_im[i] = x_im[2*i+1];
    }

    fft(x1_re, x1_im, n/2);
    fft(x2_re, x2_im, n/2);

    double c, s, t_re, t_im;
    for(int i=0; i<n/2; i++)
    {
        c = cos(2*M_PI*i/n);
        s = sin(2*M_PI*i/n);
        t_re = c*x2_re[i] - s*x2_im[i];
        t_im = c*x2_im[i] + s*x2_re[i];

        x_re[i] = x1_re[i] + t_re;
        x_im[i] = x1_im[i] + t_im;
        x_re[i+n/2] = x1_re[i] - t_re;
        x_im[i+n/2] = x1_im[i] - t_im;
    }

    free(x1_re);
    free(x1_im);
    free(x2_re);
    free(x2_im);
}

void ifft(double* x_re, double* x_im, int n)
{
    for(int i=0; i<n; i++)
        x_im[i] = -x_im[i];

    fft(x_re, x_im, n);

    for(int i=0; i<n; i++)
    {
        x_re[i] = x_re[i]/n;
        x_im[i] = -x_im[i]/n;
    }
}

void convolve(double* x_re, double* x_im, double* y_re, double* y_im, int n, double* z_re, double* z_im)
{
    for(int i=0; i<n; i++)
    {
        z_re[i] = x_re[i]*y_re[i] - x_im[i]*y_im[i];
        z_im[i] = x_re[i]*y_im[i] + x_im[i]*y_re[i];
    }
}

int main()
{
    double x_re[N] = {0};
    double x_im[N] = {0};
    double y_re[N] = {0};
    double y_im[N] = {0};
    double z_re[N] = {0};
    double z_im[N] = {0};

    x_re[0] = 1;
    y_re[0] = 1;
    for(int i=1; i<N; i++)
    {
        x_re[i] = sin(2*M_PI*50*i/1024) + 0.5*sin(2*M_PI*100*i/1024);
        y_re[i] = sin(2*M_PI*20*i/1024) + sin(2*M_PI*80*i/1024);
    }

    fft(x_re, x_im, N);
    fft(y_re, y_im, N);
    convolve(x_re, x_im, y_re, y_im, N, z_re, z_im);
    ifft(z_re, z_im, N);

    FILE* fp;
    fp = fopen("output.dat", "w");
    for(int i=0; i<N; i++)
    {
        fprintf(fp, "%d %lf\n", i, z_re[i]);
    }
    fclose(fp);

    return 0;
}