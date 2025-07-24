//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>

#define NUM_SAMPLES 1024
#define SAMPLE_RATE 44100.0f

float sine_wave[NUM_SAMPLES];
float filtered_wave[NUM_SAMPLES];
float cutoff_freq = 1000.0f;

void apply_lowpass_filter(void) {
    float RC = 1.0f / (cutoff_freq * 2.0f * 3.14f);
    float dt = 1.0f / SAMPLE_RATE;
    float alpha = dt / (RC + dt);

    filtered_wave[0] = sine_wave[0];

    for (int i = 1; i < NUM_SAMPLES; i++) {
        filtered_wave[i] = filtered_wave[i-1] + alpha * (sine_wave[i] - filtered_wave[i-1]);
    }
}

void generate_sine_wave(void) {
    float freq = 440.0f; // A4 note
    float amplitude = 1.0f;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        sine_wave[i] = amplitude * sin(2.0f * 3.14f * freq * i / SAMPLE_RATE);
    }
}

int main(void) {
    generate_sine_wave();
    apply_lowpass_filter();

    // Print the original and filtered signals
    printf("Original Signal,Filtered Signal\n");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%f,%f\n", sine_wave[i], filtered_wave[i]);
    }

    return 0;
}