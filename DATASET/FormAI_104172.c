//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define TWO_PI (3.14159265359 * 2)

// A struct to keep track of the generated sine wave's state
typedef struct sine_wave {
    double frequency;
    double phase;
} sine_wave_t;

// Function that generates a sine wave at a given frequency and amplitude
double generate_sine_wave(sine_wave_t* state, double amplitude) {
    double sample = amplitude * sin(state->phase);
    state->phase += TWO_PI * state->frequency / SAMPLE_RATE;
    if (state->phase > TWO_PI) {
        state->phase -= TWO_PI;
    }
    return sample;
}

int main() {
    // Create a sine wave with a frequency of 440 Hz and amplitude of 1.0
    sine_wave_t sine_wave = {440.0, 0.0};
    double amplitude = 1.0;
    
    // Open an audio file for writing
    FILE* audio_file = fopen("output.wav", "w");
    if (audio_file == NULL) {
        printf("Error opening audio file\n");
        return EXIT_FAILURE;
    }
    
    // Write the WAV file header to the audio file
    const int byte_rate = SAMPLE_RATE * 2;
    const int block_align = 2;
    const int num_samples = SAMPLE_RATE * 5; // Generate 5 seconds of audio
    const int data_size = num_samples * block_align;
    const int riff_size = 4 + (8 + 16) + (8 + data_size);
    const int fmt_size = 16;
    const int audio_format = 1; // PCM audio format
    const short num_channels = 1;
    const short bits_per_sample = 16;
    const int fmt_chunk_size = 16;
    const int io_result = fprintf(audio_file,
        "RIFF%.4sWAVEfmt %.4s%4d%c%c%c%c%c%c%c%c%c%.4s%4d%c%c%.2s%c%c%.4s%8d",
        "WAVE", "fmt ", fmt_chunk_size, 1, 0,
        num_channels, byte_rate, block_align, bits_per_sample,
        "data", data_size, 0, 0, "data", data_size);
    if (io_result < 0) {
        printf("Error writing audio file header\n");
        fclose(audio_file);
        return EXIT_FAILURE;
    }
    
    // Generate the audio samples and write them to the file
    for (int i = 0; i < num_samples; ++i) {
        const short sample = (short) round(generate_sine_wave(&sine_wave, amplitude) * 32767);
        const int io_result = fwrite(&sample, sizeof(sample), 1, audio_file);
        if (io_result != 1) {
            printf("Error writing audio file data\n");
            fclose(audio_file);
            return EXIT_FAILURE;
        }
    }
    
    // Close the audio file
    fclose(audio_file);
    
    return EXIT_SUCCESS;
}