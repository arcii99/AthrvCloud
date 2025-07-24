//FormAI DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512  //Number of samples
#define Fs 8000 //Sampling frequency
#define F 1000  //Input sine wave frequency

int main()
{
    float x[N], y[N];        //Input and output arrays
    float window[N];         //Window function array
    float w, hamming, hanning;
    float gain = 1;          //Filter gain
    float theta, theta_p;
    float alpha = 0.9;       //Filter parameter
    float beta = 1 - alpha;
    float peak = 0;          //Peak amplitude
    int i;

    //Calculate window function
    for (i = 0; i < N; i++)
    {
        hamming = 0.54 - 0.46 * cos(2 * M_PI * i / (N - 1));
        hanning = 0.5 - 0.5 * cos(2 * M_PI * i / (N - 1));
        window[i] = hanning;
    }

    //Generate input signal
    for (i = 0; i < N; i++)
    {
        theta = 2 * M_PI * F * i / Fs;
        theta_p = 2 * M_PI * ((F + 100) / 2 + (F - 100) / 2 * sin(2 * M_PI * 50 * i / Fs)) * i / Fs;

        //Add noise to input signal
        x[i] = 0.8 * sin(theta) + 0.2 * sin(2 * theta) + 0.1 * sin(3 * theta_p);
    }

    //Apply window function to input signal
    for (i = 0; i < N; i++)
    {
        x[i] = x[i] * window[i];
    }

    //Filter input signal
    for (i = 0; i < N; i++)
    {
        y[i] = gain * (alpha * y[i-1] + beta * x[i]);
        
        //Find peak amplitude
        if (y[i] > peak)
        {
            peak = y[i];
        }
    }

    printf("Peak Amplitude = %f\n", peak);

    return 0;
}