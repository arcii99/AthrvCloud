//FormAI DATASET v1.0 Category: Digital signal processing ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 1000
#define AMPLITUDE 0.8

double sine_wave(double frequency, double amplitude, double time) {
    return amplitude * sin(2 * M_PI * frequency * time);
}

int main() {
    int duration = 5;
    int sample_count = SAMPLE_RATE * duration;
    double *buffer = malloc(sample_count * sizeof(double));

    for(int i = 0; i < sample_count; i++) {
        double time = (double)i / SAMPLE_RATE;
        buffer[i] = sine_wave(FREQUENCY, AMPLITUDE, time);
    }

    FILE *file = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(double), sample_count, file);
    fclose(file);

    free(buffer);
    return 0;
}