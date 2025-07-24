//FormAI DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLES 256
#define PI 3.141592653589793

int main()
{
    double signal[SAMPLES];
    double frequency = 1000;
    double phase = 0;
    double sampleRate = 44100;
    double timeStep = 1/sampleRate;
    double amplitude = 1;
    int i;

    /* Generate a sine wave with frequency 1000 Hz and amplitude 1 */
    for (i = 0; i < SAMPLES; ++i)
    {
        signal[i] = amplitude*sin(2*PI*frequency*i*timeStep + phase);
    }

    /* Apply a low-pass filter */
    double cutoffFrequency = 500;
    double RC = 1/(2*PI*cutoffFrequency);
    double alpha = timeStep/(RC+timeStep);
    double filteredSignal[SAMPLES];
    double prevOutput = 0;
    for (i = 0; i < SAMPLES; ++i)
    {
        filteredSignal[i] = alpha*signal[i] + (1-alpha)*prevOutput;
        prevOutput = filteredSignal[i];
    }

    /* Apply a gain */
    double gain = 3;
    for (i = 0; i < SAMPLES; ++i)
    {
        filteredSignal[i] *= gain;
    }

    /* Output the signal */
    FILE *fp;
    fp = fopen("output.txt", "w");
    for (i = 0; i < SAMPLES; ++i)
    {
        fprintf(fp, "%lf\n", filteredSignal[i]);
    }
    fclose(fp);

    return 0;
}