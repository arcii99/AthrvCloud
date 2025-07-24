//FormAI DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265359

float frequency(float hertz)
{
    return hertz * 2.0f * PI / SAMPLE_RATE;
}

int main()
{
    float sine_wave[44100];

    // Generate sine wave
    for (int i = 0; i < SAMPLE_RATE; i++)
    {
        float time = (float)i / SAMPLE_RATE;
        float hertz = 440.0f;
        float sample = sinf(frequency(hertz) * i);
        sine_wave[i] = sample;
    }

    // Save sine wave to file
    FILE *file = fopen("sine_wave.raw", "wb");
    fwrite(sine_wave, sizeof(float), SAMPLE_RATE, file);
    fclose(file);

    // Load sine wave from file
    float loaded_sine_wave[44100];
    file = fopen("sine_wave.raw", "rb");
    fread(loaded_sine_wave, sizeof(float), SAMPLE_RATE, file);
    fclose(file);

    // Apply reverb to sine wave
    for (int i = 0; i < SAMPLE_RATE; i++)
    {
        if (i > SAMPLE_RATE / 2 && i < SAMPLE_RATE)
        {
            float decay = (float)(i - SAMPLE_RATE / 2) / (float)(SAMPLE_RATE / 2);
            loaded_sine_wave[i] = loaded_sine_wave[i] + loaded_sine_wave[i - SAMPLE_RATE / 2] * decay * 0.5f;
        }
    }

    // Save reverb sine wave to file
    file = fopen("reverb_sine_wave.raw", "wb");
    fwrite(loaded_sine_wave, sizeof(float), SAMPLE_RATE, file);
    fclose(file);

    return 0;
}