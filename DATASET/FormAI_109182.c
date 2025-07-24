//FormAI DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>

#define SAMPLE_RATE 44100
#define SIGNAL_FREQ 1000
#define DURATION 5
#define AMPLITUDE 1

const float TWO_PI = 6.28318530718;

int main() {
    int samples = SAMPLE_RATE * DURATION;
    short int signal[samples];

    for(int i = 0; i < samples; i++) {
        float t = (float)i / (float)SAMPLE_RATE;
        signal[i] = AMPLITUDE * sin(TWO_PI * SIGNAL_FREQ * t);
    }

    // Apply low pass filter
    double alpha = 0.2;
    double prev = 0;
    for(int i = 0; i < samples; i++) {
        double filtered = prev + alpha * (signal[i] - prev);
        signal[i] = (short int)filtered;
        prev = filtered;
    }

    // Play the signal
    FILE* f = fopen("output.pcm", "wb");
    fwrite(signal, sizeof(short int), samples, f);
    fclose(f);
}