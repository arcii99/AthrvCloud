//FormAI DATASET v1.0 Category: Digital signal processing ; Style: genious
/* A Genius-style Digital Signal Processing Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define FREQUENCY 440.0
#define AMPLITUDE 0.5

int main()
{
    // Initialize variables
    double time = 0.0; // in seconds
    double increment = 1.0 / SAMPLE_RATE;
    double waveValue = 0.0;
    double envelope = 0.0;

    // Generate a digital signal with amplitude modulation
    for (int i = 0; i < SAMPLE_RATE; i++) {
        envelope = 0.5 * (1.0 - cos(2.0 * M_PI * i / SAMPLE_RATE)); // Hann window
        waveValue = AMPLITUDE * sin(2.0 * M_PI * FREQUENCY * time) * envelope;
        time += increment;
        printf("%f\n", waveValue); // Print the wave value to the console
    }

    // Apply a low-pass filter on the wave
    double cutoff = 2000.0;
    double resonance = 0.5;
    double a0 = 0.0, a1 = 0.0, a2 = 0.0, b1 = 0.0, b2 = 0.0; // Filter coefficients
    double cutoffNormalized = cutoff / (SAMPLE_RATE / 2.0);
    double omega = 2.0 * M_PI * cutoffNormalized;
    double alpha = sin(omega) / (2.0 * resonance);
    a0 = 1.0 + alpha;
    a1 = -2.0 * cos(omega);
    a2 = 1.0 - alpha;
    b1 = (1.0 - cos(omega)) / 2.0;
    b2 = 1.0 - cos(omega);
    
    double xn1 = 0.0, xn2 = 0.0, yn1 = 0.0, yn2 = 0.0; // Delayed samples
    double inputSample = 0.0, outputSample = 0.0;
    
    for (int i = 0; i < SAMPLE_RATE; i++) {
        inputSample = waveValue;
        outputSample = (a0 * inputSample + a1 * xn1 + a2 * xn2 - b1 * yn1 - b2 * yn2) / a0;
        
        xn2 = xn1;
        xn1 = inputSample;
        yn2 = yn1;
        yn1 = outputSample;
        
        printf("%f\n", outputSample); // Print the filtered wave to the console
    }

    return 0;
}