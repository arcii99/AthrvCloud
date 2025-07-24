//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

// Apply low-pass filter to audio buffer
void low_pass_filter(float *buffer, int buffer_size, float cutoff_freq) {
    float dt = 1.0 / SAMPLE_RATE;
    float RC = 1.0 / (2.0 * M_PI * cutoff_freq);
    float alpha = dt / (RC + dt);
    
    float prev = 0.0;
    for (int i = 0; i < buffer_size; i++) {
        float filtered = alpha * buffer[i] + (1.0 - alpha) * prev;
        prev = filtered;
        buffer[i] = filtered;
    }
}

// Apply tremolo effect to audio buffer
void tremolo_effect(float *buffer, int buffer_size, float freq) {
    float t = 0.0;
    float dt = 1.0 / SAMPLE_RATE;
    for (int i = 0; i < buffer_size; i++) {
        float tremolo = sin(2.0 * M_PI * freq * t);
        buffer[i] *= tremolo;
        t += dt;
    }
}

int main() {
    // Generate test signal (440 Hz sine wave)
    float test_signal[BUFFER_SIZE];
    float freq = 440.0;
    float t = 0.0;
    float dt = 1.0 / SAMPLE_RATE;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        test_signal[i] = sin(2.0 * M_PI * freq * t);
        t += dt;
    }
    
    // Apply low-pass filter
    float cutoff_freq = 300.0;
    low_pass_filter(test_signal, BUFFER_SIZE, cutoff_freq);
    
    // Apply tremolo effect
    float tremolo_freq = 5.0;
    tremolo_effect(test_signal, BUFFER_SIZE, tremolo_freq);
    
    // Save output to file
    FILE *file = fopen("output.raw", "wb");
    fwrite(test_signal, sizeof(float), BUFFER_SIZE, file);
    fclose(file);
    
    return 0;
}