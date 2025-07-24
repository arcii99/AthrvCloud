//FormAI DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>

#define BUFFER_SIZE 256
#define SAMPLING_RATE 44100
#define PI 3.14159265358979323846

// Generate a sine wave signal
void generateSineWave(int frequency, float amplitude, float signalBuffer[], float timeBuffer[]) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        signalBuffer[i] = amplitude * sin(2 * PI * frequency * timeBuffer[i]);
    }
}

// Apply low-pass filter to the signal
void applyLowPassFilter(float signalBuffer[], float timeBuffer[]) {
    // Set the cut-off frequency to 4000 Hz
    float cutOffFrequency = 4000;
    float RC = 1 / (2 * PI * cutOffFrequency);
    float dt = 1 / (float) SAMPLING_RATE;
    float alpha = dt / (RC + dt);
    float previousOutput = 0;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        float output = alpha * signalBuffer[i] + (1 - alpha) * previousOutput;
        signalBuffer[i] = output;
        previousOutput = output;
    }
}

int main() {
    float timeBuffer[BUFFER_SIZE];
    float signalBuffer[BUFFER_SIZE];

    // Generate time buffer for 1 second with 44100 samples
    for (int i = 0; i < BUFFER_SIZE; i++) {
        timeBuffer[i] = (float) i / (float) SAMPLING_RATE;
    }

    // Generate a 1000 Hz sine wave signal with amplitude 1
    generateSineWave(1000, 1, signalBuffer, timeBuffer);

    // Apply a low-pass filter to the signal
    applyLowPassFilter(signalBuffer, timeBuffer);

    // Print the filtered signal values
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", signalBuffer[i]);
    }

    return 0;
}