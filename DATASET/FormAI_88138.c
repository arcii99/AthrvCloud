//FormAI DATASET v1.0 Category: Digital signal processing ; Style: real-life
/* This program applies a high-pass filter to a series of audio data to remove low frequency noise */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define CUTOFF_FREQ 1000.0
#define NUM_SAMPLES 1024

double input_buffer[NUM_SAMPLES];
double output_buffer[NUM_SAMPLES];

double sin_table[NUM_SAMPLES];
double cos_table[NUM_SAMPLES];

/* Generate a lookup table for sin and cos values */
void generate_lut(float *table, int size, int is_cos)
{
    double step = 2.0 * M_PI / (double)size;
    int i;
    
    for (i = 0; i < size; ++i) {
        table[i] = (is_cos) ? cos(step * (double)i) : sin(step * (double)i);
    }
}

/* Apply a high-pass filter to the input signal */
void apply_high_pass_filter(double *input, double *output, int num_samples, double cutoff_freq)
{
    int i, j;
    double acc_real, acc_imag;
    double temp_real, temp_imag;
    double cos_val, sin_val;
    double diff_freq = SAMPLE_RATE / (double)num_samples;
    double freq = 0.0;
    
    /* Generate sin/cos tables for FFT */
    generate_lut(sin_table, num_samples, 0);
    generate_lut(cos_table, num_samples, 1);
    
    /* Perform FFT of input signal */
    for (i = 0; i < num_samples; ++i) {
        acc_real = 0.0;
        acc_imag = 0.0;
        for (j = 0; j < num_samples; ++j) {
            cos_val = cos_table[(i * j) % num_samples];
            sin_val = sin_table[(i * j) % num_samples];
            acc_real += input[j] * cos_val;
            acc_imag += input[j] * sin_val;
        }
        output[i] = sqrt(acc_real * acc_real + acc_imag * acc_imag);
    }
    
    /* Apply high-pass filter */
    for (i = 0; i < num_samples; ++i) {
        freq = diff_freq * (double)i;
        if (freq < cutoff_freq) {
            output[i] = 0.0;
        }
    }
    
    /* Inverse FFT to get filtered signal */
    for (i = 0; i < num_samples; ++i) {
        acc_real = 0.0;
        acc_imag = 0.0;
        for (j = 0; j < num_samples; ++j) {
            cos_val = cos_table[(i * j) % num_samples];
            sin_val = sin_table[(i * j) % num_samples];
            temp_real = output[j] * cos_val - acc_imag * sin_val;
            temp_imag = output[j] * sin_val + acc_imag * cos_val;
            acc_real += temp_real;
            acc_imag += temp_imag;
        }
        output[i] = acc_real / (double)num_samples;
    }
}

int main()
{
    int i;
    
    /* Generate random input data */
    for (i = 0; i < NUM_SAMPLES; ++i) {
        input_buffer[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // [-1, 1)
    }
    
    /* Apply high-pass filter */
    apply_high_pass_filter(input_buffer, output_buffer, NUM_SAMPLES, CUTOFF_FREQ);
    
    /* Output filtered data */
    for (i = 0; i < NUM_SAMPLES; ++i) {
        printf("%f\n", output_buffer[i]);
    }
    
    return 0;
}