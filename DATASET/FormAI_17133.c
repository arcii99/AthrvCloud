//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265
#define SAMPLE_RATE 48000
#define FREQUENCY 440.0
#define DURATION 5.0

int main() {
    srand(time(NULL));
    
    double *samples = calloc(DURATION * SAMPLE_RATE, sizeof(double));
    double time_step = 1.0 / SAMPLE_RATE;
    
    for (int i = 0; i < DURATION * SAMPLE_RATE; i++) {
        samples[i] = sin(2 * PI * FREQUENCY * i * time_step);
    }
    
    printf("Playing sound...\n");
    
    for (int i = 0; i < DURATION * SAMPLE_RATE; i++) {
        int random_sample = rand() % (SAMPLE_RATE / 100); // Add some noise
        double amplitude = sin(i * PI / (DURATION * SAMPLE_RATE)) + ((double) random_sample / (SAMPLE_RATE / 100));
        samples[i] *= amplitude;
        printf("%f\n", samples[i]);
        // Sleep to simulate sound playback
        struct timespec sleep_time;
        sleep_time.tv_sec = 0;
        sleep_time.tv_nsec = 1000000000 / SAMPLE_RATE;
        nanosleep(&sleep_time, NULL);
    }
    
    free(samples);
    return 0;
}