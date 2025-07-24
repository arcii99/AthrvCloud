//FormAI DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define PI 3.1415926535897932384626433832795

// function to generate a sine wave at a given frequency and sample rate
void generate_sine(float *waveform, float frequency, int sample_rate, int length) {
    for (int i = 0; i < length; i++) {
        waveform[i] = sin(2 * PI * frequency * i / sample_rate);
    }
}

// function to apply a low-pass filter to an audio signal
void apply_low_pass_filter(float *audio_signal, int sample_rate, int length, float cutoff_frequency) {
    float RC = 1.0 / (2 * PI * cutoff_frequency);
    float dt = 1.0 / sample_rate;
    float alpha = dt / (RC + dt);
    float prev_output = 0.0;

    for (int i = 0; i < length; i++) {
        float current_input = audio_signal[i];
        float current_output = alpha * current_input + (1 - alpha) * prev_output;
        prev_output = current_output;
        audio_signal[i] = current_output;
    }
}

int main() {
    // generate a 1 second sine wave at 440Hz with sample rate 44100Hz
    int sample_rate = 44100;
    int length = sample_rate;
    float frequency = 440.0;
    float waveform[length];
    generate_sine(waveform, frequency, sample_rate, length);

    // apply a low-pass filter with cutoff frequency 400Hz
    float cutoff_frequency = 400.0;
    apply_low_pass_filter(waveform, sample_rate, length, cutoff_frequency);

    // print out the filtered waveform
    for (int i = 0; i < length; i++) {
        printf("%f\n", waveform[i]);
    }

    return 0;
}