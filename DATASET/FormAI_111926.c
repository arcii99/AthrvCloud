//FormAI DATASET v1.0 Category: Audio processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024

void configure_filter(float *filter, int filter_size, float cutoff_freq, float sampling_rate) {
    float nyquist_freq = sampling_rate / 2.0f;
    float filter_step = nyquist_freq / (filter_size - 1);
    float omega_cutoff = 2.0f * M_PI * cutoff_freq / sampling_rate;

    for (int i = 0; i < filter_size; i++) {
        if (i * filter_step <= cutoff_freq)
            filter[i] = 2.0f * sin(i * omega_cutoff) / (i * M_PI);
        else
            filter[i] = 0.0f;
    }
}

void apply_filter(float *source_buf, float *dest_buf, float *filter, int filter_size, int buf_size) {
    for (int i = 0; i < buf_size; i++) {
        dest_buf[i] = 0.0f;
        for (int j = 0; j < filter_size; j++) {
            int source_index = i - filter_size / 2 + j;
            if (source_index >= 0 && source_index < buf_size)
                dest_buf[i] += source_buf[source_index] * filter[j];
        }
    }
}

int main() {
    float source_buf[BUFFER_SIZE];
    float dest_buf[BUFFER_SIZE];
    float filter[256];

    // Generate input signal
    for (int i = 0; i < BUFFER_SIZE; i++)
        source_buf[i] = sin(2.0f * M_PI * 440.0f * i / 44100.0f); // 440 Hz sine wave

    // Configure filter
    configure_filter(filter, 256, 1000.0f, 44100.0f);

    // Apply filter
    apply_filter(source_buf, dest_buf, filter, 256, BUFFER_SIZE);

    // Output result
    for (int i = 0; i < BUFFER_SIZE; i++)
        printf("%f ", dest_buf[i]);

    return 0;
}