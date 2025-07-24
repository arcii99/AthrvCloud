//FormAI DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

float generate_sine_wave(float frequency, float duration) {
    float sample_rate = SAMPLE_RATE;
    float time = 0;
    float amplitude = 0.25;
    int num_samples = (int) (duration * sample_rate);
    float *buffer = (float*) malloc(num_samples * sizeof(float));
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = amplitude * sinf(2.0f * PI * frequency * time);
        time += 1.0f / sample_rate;
    }
    float output = buffer[num_samples - 1];
    free(buffer);
    return output;
}

float low_pass_filter(float input, float alpha, float previous_output) {
    float output = alpha * input + (1.0f - alpha) * previous_output;
    return output;
}

int main() {
    srand(time(NULL));
    float sine_wave = generate_sine_wave(440.0f, 1.0f);
    float alpha = rand() / (float)RAND_MAX; // randomize filter value
    float filtered_wave = low_pass_filter(sine_wave, alpha, 0);
    printf("Filtered wave: %f", filtered_wave);
    return 0;
}