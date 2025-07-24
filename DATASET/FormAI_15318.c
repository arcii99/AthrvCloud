//FormAI DATASET v1.0 Category: Audio processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 2048
#define PI 3.14159265358979323846

typedef struct {
    double frequency;
    double amplitude;
    double phase;
} Oscillator;

void generateSawtooth(Oscillator *os, double *buffer) {
    double increment = os->frequency * 2 * PI / SAMPLE_RATE;
    double current = os->phase;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] += os->amplitude * (current - PI) / PI;
        current += increment;
        if (current >= 2 * PI) current -= 2 * PI;
    }
    os->phase = current;
}

void generateSine(Oscillator *os, double *buffer) {
    double increment = os->frequency * 2 * PI / SAMPLE_RATE;
    double current = os->phase;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] += os->amplitude * sin(current);
        current += increment;
        if (current >= 2 * PI) current -= 2 * PI;
    }
    os->phase = current;
}

void mixBuffers(double *input, double *output) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        output[i] += input[i];
    }
}

int main() {
    Oscillator sawtooth;
    sawtooth.frequency = 440;
    sawtooth.amplitude = 0.5;
    sawtooth.phase = 0;
    
    Oscillator sine;
    sine.frequency = 880;
    sine.amplitude = 0.25;
    sine.phase = 0;
    
    double buffer[BUFFER_SIZE] = {0};
    for (int i = 0; i < SAMPLE_RATE; i += BUFFER_SIZE) {
        generateSawtooth(&sawtooth, buffer);
        generateSine(&sine, buffer);
        mixBuffers(buffer, buffer); // Duplicate the mixed buffer
        // Send the buffer to other players via network connection
        // Receive buffers from other players and mix them into the buffer
        // (Not implemented in this example program)
        fwrite(buffer, sizeof(double), BUFFER_SIZE, stdout); // Write to stdout for simplicity
    }
    return 0;
}