//FormAI DATASET v1.0 Category: Audio processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining some constants
#define SAMPLE_RATE 44100     // Samples/sec
#define BIT_DEPTH   16        // Bits/sample
#define MAX_AMPLITUDE 32767   // Maximum amplitude value

// Struct to hold audio data
typedef struct {
    int16_t *audio_data;    // Array of audio samples
    int num_samples;        // Number of audio samples
} AudioBuffer;

// Function to create a new AudioBuffer with given size and fill with silence
AudioBuffer new_buffer(int num_samples) {
    AudioBuffer buffer;
    buffer.audio_data = (int16_t *)malloc(num_samples * sizeof(int16_t));
    buffer.num_samples = num_samples;
    for (int i = 0; i < num_samples; i++) {
        buffer.audio_data[i] = 0;
    }
    return buffer;
}

// Function to add two AudioBuffers and return a new AudioBuffer
AudioBuffer add_audio(AudioBuffer buffer1, AudioBuffer buffer2) {
    AudioBuffer result = new_buffer(buffer1.num_samples);
    for (int i = 0; i < buffer1.num_samples; i++) {
        result.audio_data[i] = buffer1.audio_data[i] + buffer2.audio_data[i];
        if(result.audio_data[i] > MAX_AMPLITUDE) {
            result.audio_data[i] = MAX_AMPLITUDE;   // Ensure amplitude stays within limits
        }
    }
    return result;
}

// Function that applies a low-pass filter on an AudioBuffer
AudioBuffer apply_low_pass_filter(AudioBuffer buffer, float cutoff_frequency) {
    AudioBuffer filtered_buffer = new_buffer(buffer.num_samples);
    float RC = 1.0 / (2.0 * M_PI * cutoff_frequency);
    float dt = 1.0 / (float)SAMPLE_RATE;   // Time interval
    float alpha = dt / (RC + dt);
    float y_prev = 0.0;
    for (int i = 0; i < buffer.num_samples; i++) {
        float sample = buffer.audio_data[i] / (float)MAX_AMPLITUDE;
        float y = alpha * sample + (1 - alpha) * y_prev;
        filtered_buffer.audio_data[i] = (int16_t) (y * MAX_AMPLITUDE);
        y_prev = y;
    }
    return filtered_buffer;
}

// Entry point
int main() {
    AudioBuffer sine_wave = new_buffer(SAMPLE_RATE);
    float frequency = 440.0;
    for (int i = 0; i < SAMPLE_RATE; i++) {
        float sample_value = sin(2 * M_PI * i * frequency / SAMPLE_RATE);
        sine_wave.audio_data[i] = (int16_t)(sample_value * MAX_AMPLITUDE);
    }

    AudioBuffer low_passed = apply_low_pass_filter(sine_wave, 2000.0);

    AudioBuffer result = add_audio(sine_wave, low_passed);

    FILE *outfile = fopen("out.raw", "wb");
    fwrite(result.audio_data, sizeof(int16_t), result.num_samples, outfile);
    fclose(outfile);
    return 0;
}