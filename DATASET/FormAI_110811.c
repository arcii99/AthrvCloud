//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define pi 3.141592653589

// Function to calculate complex exponential
void comp_exp(double *real, double *imag, double re, double im, double freq, double t)
{
    double w = 2 * pi * freq;
    *real = re * cos(w*t) - im * sin(w*t);
    *imag = re * sin(w*t) + im * cos(w*t);
}

// Function to simulate RC low pass filter
void sim_RC_low_pass(double r, double c, double freq, double *out_real, double *out_imag)
{
    double w = 2 * pi * freq;
    double re = 1/(r*c);
    *out_real = 1/sqrt(1 + pow(w * r * c, 2));
    *out_imag = -(w * r * c) / sqrt(1 + pow(w * r * c, 2));
}

int main()
{
    double r = 1000;
    double c = 1e-6;
    double freq = 1000;
    double t_step = 1e-5;
    double t = 0.0;

    double vin_real, vin_imag;
    comp_exp(&vin_real, &vin_imag, 1, 0, freq, t);

    double vout_real=0.0, vout_imag=0.0;

    double out_freq = 10000;
    double n_samples = ceil(1/(t_step*out_freq));

    FILE* fp;
    fp = fopen("output.txt", "w");

    int i;
    for(i=0; i<100000; i++)
    {
        sim_RC_low_pass(r, c, freq, &vout_real, &vout_imag);

        fprintf(fp, "%lf\t%lf\n", t, vout_real);

        double temp_real = vout_real*cos(freq*t) - vout_imag*sin(freq*t);
        double temp_imag = vout_real*sin(freq*t) + vout_imag*cos(freq*t);

        vout_real = temp_real;
        vout_imag = temp_imag;

        t += t_step;

        if(fmod(i, n_samples) == 0)
        {
            comp_exp(&vin_real, &vin_imag, 1, 0, freq, t);
        }
    }

    fclose(fp);

    return 0;
}