//FormAI DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000
#define BUFFER_SIZE 1024

// Declare global variables
float data[BUFFER_SIZE];
int position = 0;

// Function to generate random noise signal
void generateNoiseSignal(float *buffer, int size) {
    int i;
    for (i = 0; i < size; i++) {
        buffer[i] = ((float)rand()/(float)RAND_MAX)*2.0-1.0; // Normalized random number between -1 and 1
    }
}

int main(void) {
    // Initialize data buffer with noise signal
    generateNoiseSignal(data, BUFFER_SIZE);
    
    // Apply band-pass filter to the signal
    float frequency = 1000 + (float)(rand() % 2000); // Random frequency between 1000 and 3000 Hz
    float bandwidth = 500 + (float)(rand() % 1000); // Random bandwidth between 500 and 1500 Hz
    float center_frequency = frequency + (float)(rand() % 500); // Random center frequency between frequency and frequency+500 Hz
    float Q = center_frequency/bandwidth;
    float omega = 2 * M_PI * center_frequency;
    float alpha = sin(omega/SAMPLE_RATE)/(2*Q);
    float beta = (1 - cos(omega/SAMPLE_RATE))/2;
    float a0 = 1 + alpha;
    float a1 = -2 * cos(omega/SAMPLE_RATE);
    float a2 = 1 - alpha;
    float b0 = (1 - cos(omega/SAMPLE_RATE))/2;
    float b1 = 1 - cos(omega/SAMPLE_RATE);
    float b2 = (1 - cos(omega/SAMPLE_RATE))/2;
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        float x0 = data[i];
        float y0 = b0/a0*x0 + b1/a0*x1 + b2/a0*x2 - a1/a0*y1 - a2/a0*y2;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        data[i] = y0;
    }
    
    // Apply reverb effect to the signal
    int delay_lines[8] = {BUFFER_SIZE/10, BUFFER_SIZE/8, BUFFER_SIZE/6, BUFFER_SIZE/4, BUFFER_SIZE/3, BUFFER_SIZE/2, BUFFER_SIZE/1, BUFFER_SIZE};
    float gain_lines[8] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
    for (i = 0; i < 8; i++) {
        int j, k;
        for (j = delay_lines[i]; j < BUFFER_SIZE; j++) {
            float delayed_signal = data[j-delay_lines[i]];
            for (k = 0; k <= i; k++) {
                delayed_signal *= gain_lines[k];
            }
            data[j] += delayed_signal;
        }
    }
    
    // Print the signal to file
    FILE *file = fopen("signal.txt", "w");
    if (file != NULL) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            fprintf(file, "%f\n", data[i]);
        }
        fclose(file);
    }
    
    return 0;
}