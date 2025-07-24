//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100000

int main()
{
    double data[SIZE];
    double amplitude = 0.5;
    double frequency = 1000.0;
    double duration = 1.0;
    double dt = 1.0 / 44100.0;
    double phase = 0.0;

    // Generate a sine wave with a given frequency, duration and amplitude
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = amplitude * sin(2 * M_PI * frequency * i * dt + phase);
        if (i * dt > duration) break;
    }

    // Normalize the signal
    double max = 0.0;
    for (int i = 0; i < SIZE; i++)
    {
        if (fabs(data[i]) > max) max = fabs(data[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        data[i] /= max;
    }

    // Add noise to the signal with given intensity
    double intensity = 0.1;
    for (int i = 0; i < SIZE; i++)
    {
        data[i] += intensity * (rand() / (RAND_MAX / 2.0) - 1.0);
    }

    // Apply a low-pass filter with a given cut-off frequency
    double fc = 500.0;
    double alpha = 2.0 * M_PI * fc * dt;
    double x = data[0];
    double y = 0.0;
    for (int i = 0; i < SIZE; i++)
    {
        y = alpha * data[i] + (1.0 - alpha) * y;
        data[i] = y;
    }

    // Write the processed signal to a WAVE file
    FILE *fp = fopen("output.wav", "wb");
    short sdata[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        sdata[i] = (short) (data[i] * 32767.0);
    }
    int numChannels = 1;
    int sampleRate = 44100;
    int byteRate = sampleRate * numChannels * sizeof(short);
    short blockAlign = numChannels * sizeof(short);
    int dataSize = SIZE * sizeof(short);
    int fileSize = 36 + dataSize;
    fwrite("RIFF", 1, 4, fp);
    fwrite(&fileSize, 4, 1, fp);
    fwrite("WAVE", 1, 4, fp);
    fwrite("fmt ", 1, 4, fp);
    fwrite("\x10\0\0\0", 1, 4, fp);
    fwrite("\1\0", 1, 2, fp);
    fwrite(&numChannels, 2, 1, fp);
    fwrite(&sampleRate, 4, 1, fp);
    fwrite(&byteRate, 4, 1, fp);
    fwrite(&blockAlign, 2, 1, fp);
    fwrite("\16\0", 1, 2, fp);
    fwrite("data", 1, 4, fp);
    fwrite(&dataSize, 4, 1, fp);
    fwrite(sdata, sizeof(short), SIZE, fp);
    fclose(fp);

    return 0;
}