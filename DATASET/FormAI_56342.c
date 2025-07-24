//FormAI DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 /* Sampling rate in Hz */
#define BUFFER_SIZE 1024 /* Number of samples per buffer */
#define PI 3.14159265358979323846 /* Value of Pi */

/* Function to create a sine wave */
void createSineWave(float frequency, float* buffer)
{
    int i;
    float phaseIncrement = 2 * PI * frequency / (float)SAMPLE_RATE;
    float phase = 0.0f;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = sin(phase);
        phase += phaseIncrement;
    }
}

/* Function to create white noise */
void createWhiteNoise(float* buffer)
{
    int i;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = ((float)rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
}

/* Function to apply a gain to a signal */
void applyGain(float gain, float* buffer)
{
    int i;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] *= gain;
    }
}

/* Function to apply a low-pass filter to a signal */
void applyLowPassFilter(float cutoffFrequency, float resonance, float* buffer)
{
    static float x1 = 0.0f, x2 = 0.0f, y1 = 0.0f, y2 = 0.0f;
    float a, b, c, d, e;
    int i;

    a = cos(2.0f * PI * cutoffFrequency / (float)SAMPLE_RATE);
    b = 2.0f * resonance * sin(2.0f * PI * cutoffFrequency / (float)SAMPLE_RATE);
    c = 1.0f + b - a;
    d = 2.0f * (a - 1.0f);
    e = 1.0f - b - a;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = (1.0f / c) * (buffer[i] * d - x1 * b - x2 * a + y1 * b + y2 * a);
        x2 = x1;
        x1 = buffer[i];
        y2 = y1;
        y1 = buffer[i];
    }
}

/* Function to apply a high-pass filter to a signal */
void applyHighPassFilter(float cutoffFrequency, float resonance, float* buffer)
{
    static float x1 = 0.0f, x2 = 0.0f, y1 = 0.0f, y2 = 0.0f;
    float a, b, c, d, e;
    int i;

    a = cos(2.0f * PI * cutoffFrequency / (float)SAMPLE_RATE);
    b = 2.0f * resonance * sin(2.0f * PI * cutoffFrequency / (float)SAMPLE_RATE);
    c = 1.0f + b - a;
    d = 2.0f * (1.0f - a);
    e = 1.0f - b - a;

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = (1.0f / c) * (buffer[i] * d - x1 * b - x2 * a + y1 * b + y2 * a);
        x2 = x1;
        x1 = buffer[i];
        y2 = y1;
        y1 = buffer[i];
    }
}

/* Main function */
int main()
{
    float sineWave[BUFFER_SIZE];
    float whiteNoise[BUFFER_SIZE];
    float output[BUFFER_SIZE];

    /* Create a sine wave with a frequency of 440Hz */
    createSineWave(440.0f, sineWave);

    /* Create white noise */
    createWhiteNoise(whiteNoise);

    /* Apply gain of 0.5 to sine wave */
    applyGain(0.5f, sineWave);

    /* Apply low-pass filter to white noise */
    applyLowPassFilter(1000.0f, 0.7f, whiteNoise);

    /* Apply high-pass filter to output */
    applyHighPassFilter(5000.0f, 0.5f, output);

    /* Print out the first 10 samples of each buffer */
    printf("Sine wave:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.3f\n", sineWave[i]);
    }

    printf("White noise:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.3f\n", whiteNoise[i]);
    }

    printf("Output:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.3f\n", output[i]);
    }

    return 0;
}