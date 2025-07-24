//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Define the sampling rate
#define SAMPLE_RATE 8000

// Define the number of samples
#define NUM_SAMPLES 800

// Define the frequency of the sine wave
#define FREQ 1000

// Define the amplitude of the sine wave
#define AMP 20000

// Define the cutoff frequency for the low-pass filter
#define CUTOFF_FREQ 500

int main()
{
    // Define variables for the current time and the sample value
    double t = 0;
    double sample = 0;
    
    // Define variables for the filter coefficients
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    double e = 0;
    
    // Loop through each sample
    for (int i = 0; i < NUM_SAMPLES; i++) {
        
        // Generate a sine wave at the specified frequency and amplitude
        sample = AMP * sin(2 * M_PI * FREQ * t);
        
        // Apply a low-pass filter to the sample
        a = 1 - exp(-2 * M_PI * CUTOFF_FREQ / SAMPLE_RATE);
        b = exp(-2 * M_PI * CUTOFF_FREQ / SAMPLE_RATE);
        c = (1 - b) / 2;
        d = c;
        e = -b;
        sample = a * (c * sample + d * sample + e * sample);
        
        // Print the sample value to the console
        printf("%f\n", sample);
        
        // Increment the current time by the sampling interval
        t += 1.0 / SAMPLE_RATE;
    }
    
    return 0;
}