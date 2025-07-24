//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SAMPLES 1024

// Cyberpunk style DSP program to create a distorted audio waveform
int main()
{
    // Declare variables
    float input_signal[MAX_SAMPLES];
    float output_signal[MAX_SAMPLES];
    float gain = 0.5;
    bool distortion_enabled = true;
    int i;

    // Generate a sawtooth waveform as input signal
    for(i = 0; i < MAX_SAMPLES; i++)
    {
        input_signal[i] = ((float)i / (float)MAX_SAMPLES) * 2.0 - 1.0; 
    }

    // Apply digital distortion
    if(distortion_enabled)
    {
        for(i = 0; i < MAX_SAMPLES; i++)
        {
            float abs_input = abs(input_signal[i]);
            float distortion_factor = 1.0 - exp(-abs_input * 10.0);
            output_signal[i] = input_signal[i] * distortion_factor * gain;
        }
    }
    else
    {
        // Skip distortion
        for(i = 0; i < MAX_SAMPLES; i++)
        {
            output_signal[i] = input_signal[i] * gain;
        }
    }

    // Print output waveform
    printf("Output waveform:\n");
    for(i = 0; i < MAX_SAMPLES; i++)
    {
        printf("%f ", output_signal[i]);
    }

    return 0;
}