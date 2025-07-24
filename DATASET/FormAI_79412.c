//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
/*
* Digital Signal Processing Example Program
* By: AI Chatbot
* Description: Perform a Fast Fourier Transform (FFT) on a signal and apply a band-pass filter
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define LOW_CUTOFF_FREQ 1000.0
#define HIGH_CUTOFF_FREQ 5000.0

void apply_hanning_window(float* buffer, int buffer_size)
{
    for (int i = 0; i < buffer_size; i++)
    {
        buffer[i] *= (0.5 - 0.5*cos(2.0*M_PI*i/(buffer_size-1)));
    }
}

void perform_fft(float* input_buffer, float* output_buffer, int buffer_size)
{
    for (int k = 0; k < buffer_size; k++)
    {
        float real_part = 0.0;
        float imaginary_part = 0.0;

        for (int n = 0; n < buffer_size; n++)
        {
            real_part += input_buffer[n] * cos(2.0*M_PI*k*n/buffer_size);
            imaginary_part -= input_buffer[n] * sin(2.0*M_PI*k*n/buffer_size);
        }

        output_buffer[k] = sqrt(real_part*real_part + imaginary_part*imaginary_part);
    }
}

void apply_band_pass_filter(float* spectrum_buffer, int buffer_size, float sample_rate, float low_cutoff_freq, float high_cutoff_freq)
{
    float bin_width = sample_rate / buffer_size;
    int low_cutoff_bin = round(low_cutoff_freq / bin_width);
    int high_cutoff_bin = round(high_cutoff_freq / bin_width);

    for (int i = 0; i < buffer_size; i++)
    {
        if (i < low_cutoff_bin || i > high_cutoff_bin)
        {
            spectrum_buffer[i] = 0.0;
        }
    }
}

int main()
{
    float input_buffer[BUFFER_SIZE];
    float output_buffer[BUFFER_SIZE];
    float spectrum_buffer[BUFFER_SIZE];

    // Generate Test Signal
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        input_buffer[i] = sin(2.0*M_PI*1000.0*i/SAMPLE_RATE) + sin(2.0*M_PI*5000.0*i/SAMPLE_RATE);
    }

    // Apply Hanning Window
    apply_hanning_window(input_buffer, BUFFER_SIZE);

    // Perform FFT
    perform_fft(input_buffer, spectrum_buffer, BUFFER_SIZE);

    // Apply Band-Pass Filter
    apply_band_pass_filter(spectrum_buffer, BUFFER_SIZE, SAMPLE_RATE, LOW_CUTOFF_FREQ, HIGH_CUTOFF_FREQ);

    // Inverse FFT
    for (int k = 0; k < BUFFER_SIZE; k++)
    {
        float real_part = 0.0;
        float imaginary_part = 0.0;

        for (int n = 0; n < BUFFER_SIZE; n++)
        {
            real_part += spectrum_buffer[n] * cos(2.0*M_PI*k*n/BUFFER_SIZE);
            imaginary_part += spectrum_buffer[n] * sin(2.0*M_PI*k*n/BUFFER_SIZE);
        }

        output_buffer[k] = (real_part + imaginary_part) / BUFFER_SIZE;
    }

    // Write Output to File
    FILE* output_file = fopen("output.txt", "w");

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        fprintf(output_file, "%f\n", output_buffer[i]);
    }

    fclose(output_file);

    return 0;
}