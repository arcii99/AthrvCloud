//FormAI DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int sample_rate = 44100;
    int num_samples = 100000;
    float frequency = 500; // in Hz
    float amplitude = 0.5;
    float duration = 2; // in seconds

    int waveform_type = 1; // 1 for sine wave, 2 for square wave
    if (waveform_type == 1)
    {
        // generating a sine wave
        float time_increment = 1.0 / sample_rate;
        float wave[num_samples];
        for (int i = 0; i < num_samples; i++)
        {
            wave[i] = amplitude * sin(2 * PI * frequency * i * time_increment);
        }

        // applying a low-pass filter to the sine wave
        float filter_frequency = 1000; // in Hz
        float filter_cutoff = 2 * PI * filter_frequency / sample_rate;
        float filter[num_samples];
        filter[0] = filter_cutoff / (1 + filter_cutoff);
        for (int i = 1; i < num_samples; i++)
        {
            filter[i] = filter_cutoff / (1 + filter_cutoff) + (1 - filter_cutoff / (1 + filter_cutoff)) * filter[i - 1];
        }

        // applying the filter to the sine wave
        for (int i = 0; i < num_samples; i++)
        {
            wave[i] *= filter[i];
        }

        // writing the audio file
        FILE *file;
        file = fopen("sine_wave_lowpass.raw", "wb");
        for (int i = 0; i < num_samples; i++)
        {
            fwrite(&wave[i], sizeof(wave[i]), 1, file);
        }
        fclose(file);
    }
    else if (waveform_type == 2)
    {
        // generating a square wave
        float time_increment = 1.0 / sample_rate;
        float wave[num_samples];
        for (int i = 0; i < num_samples; i++)
        {
            float phase = fmod(frequency * i * time_increment, 1);
            if (phase < 0.5)
            {
                wave[i] = amplitude;
            }
            else
            {
                wave[i] = -amplitude;
            }
        }

        // applying a high-pass filter to the square wave
        float filter_frequency = 1000; // in Hz
        float filter_cutoff = 2 * PI * filter_frequency / sample_rate;
        float filter[num_samples];
        filter[0] = 1 / (1 + filter_cutoff);
        for (int i = 1; i < num_samples; i++)
        {
            filter[i] = filter[i - 1] + filter_cutoff * (wave[i] - filter[i - 1]);
        }

        // applying the filter to the square wave
        for (int i = 0; i < num_samples; i++)
        {
            wave[i] -= filter[i];
        }

        // writing the audio file
        FILE *file;
        file = fopen("square_wave_highpass.raw", "wb");
        for (int i = 0; i < num_samples; i++)
        {
            fwrite(&wave[i], sizeof(wave[i]), 1, file);
        }
        fclose(file);
    }

    return 0;
}