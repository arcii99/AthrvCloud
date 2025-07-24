//FormAI DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define SAMPLE_RATE 44100
#define CUTOFF_FREQUENCY 5000

float high_pass_filter(float input);

int main(int argc, char** argv)
{
    float input, output;
    int sample_count = 0, samples_per_cycle;
    float wavelength, cutoff_frequency_ratio;
    
    wavelength = SAMPLE_RATE / CUTOFF_FREQUENCY;
    samples_per_cycle = floor(wavelength);
    cutoff_frequency_ratio = 1 / (2 * M_PI * wavelength);
    
    while(1)
    {
        scanf("%f", &input);
        output = high_pass_filter(input);
        printf("%f\n", output);
        sample_count++;
    }
    
    return 0;
}

float high_pass_filter(float input)
{
    static float output, input_prev, input_prev2, output_prev, output_prev2;
    float input_now, output_now;
    float a0, a1, a2, b1, b2;
    float R, C, cutoff, omega, theta;
    
    cutoff = CUTOFF_FREQUENCY;
    R = 1;
    C = 1 / (2 * M_PI * cutoff * R);
    omega = 2 * M_PI * cutoff;
    theta = omega / SAMPLE_RATE;
    
    a0 = 1 + 2 * pow(theta, 2) * R * C + pow(theta, 4) * pow(R * C, 2);
    a1 = -2 + 2 * pow(theta, 2) * pow(R * C, 2);
    a2 = 1 - 2 * pow(theta, 2) * R * C + pow(theta, 4) * pow(R * C, 2);
    b1 = 2 * (1 - pow(theta, 2) * pow(R * C, 2));
    b2 = 1 - 2 * pow(theta, 2) * R * C + pow(theta, 4) * pow(R * C, 2);
    
    input_now = input;
    output_now = a0 * input_now + a1 * input_prev + a2 * input_prev2 - b1 * output_prev - b2 * output_prev2;
    
    input_prev2 = input_prev;
    input_prev = input_now;
    output_prev2 = output_prev;
    output_prev = output_now;
    
    return output_now;
}