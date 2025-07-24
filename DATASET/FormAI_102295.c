//FormAI DATASET v1.0 Category: Digital signal processing ; Style: retro
/**
 * Retro-style digital signal processing example
 * Author: Chatbot
 */

#include <stdio.h>
#include <math.h>

int main() {
    const int sampleRate = 44100; // Sampling rate in Hz
    const float freq = 440.0; // Frequency to generate
    const float amplitude = 0.5; // Amplitude of the waveform
    const int duration = 5; // Duration of the waveform in seconds
    const int bufferSize = sampleRate * duration; // Buffer size for the waveform
    const float pi = 3.14159265358979323846; // Pi constant
    
    int i, j;
    float x, y;
    float buffer[bufferSize];

    // Generate waveform
    for (i = 0; i < bufferSize; i++) {
        x = 2 * pi * freq * i / sampleRate; // Calculate phase angle
        y = sin(x); // Generate sine wave
        buffer[i] = amplitude * y; // Set amplitude
    }

    // Apply filter
    for (i = 0; i < bufferSize; i++) {
        if (i % 2 == 0) { // Low pass filter
            for (j = i + 1; j < bufferSize; j++) {
                buffer[j] = 0.5 * buffer[j] + 0.5 * buffer[j - 1];
            }
        } else { // High pass filter
            for (j = i + 1; j < bufferSize; j++) {
                buffer[j] = 0.5 * buffer[j] - 0.5 * buffer[j - 1];
            }
        }
    }

    // Print waveform
    for (i = 0; i < bufferSize; i++) {
        printf("%.4f\n", buffer[i]);
    }

    return 0;
}