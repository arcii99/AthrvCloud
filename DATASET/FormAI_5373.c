//FormAI DATASET v1.0 Category: Digital signal processing ; Style: real-life
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100 // sample rate in Hz
#define PI 3.141592654 // pi value

int main()
{
    // define filter coefficients
    double a[3] = {1.0, -1.561018075800718, 0.6413515380575632};
    double b[3] = {0.020083365276393055, 0.04016673055278611, 0.020083365276393055};

    // define input and output signals
    double x[5000], y[5000];

    // generate input signal
    for(int i = 0; i < 5000; i++)
    {
        x[i] = sin(2 * PI * 1000 * i / SAMPLE_RATE) + sin(2 * PI * 2000 * i / SAMPLE_RATE) + sin(2 * PI * 3000 * i / SAMPLE_RATE);
    }

    // apply filter
    for(int i = 2; i < 5000; i++)
    {
        y[i] = b[0]*x[i] + b[1]*x[i-1] + b[2]*x[i-2] - a[1]*y[i-1] - a[2]*y[i-2];
    }

    // save output signal to file
    FILE *file;
    file = fopen("output_signal.txt", "w");
    for(int i = 0; i < 5000; i++)
    {
        fprintf(file, "%f\n", y[i]);
    }
    fclose(file);

    return 0;
}