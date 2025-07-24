//FormAI DATASET v1.0 Category: Audio processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 32000
#define PI 3.14159265358979323846

int main() {
    // Variables for square wave generation
    double square_frequency = 440.0;
    double square_wave_duration = 1.0;
    int num_samples = (int)(SAMPLE_RATE * square_wave_duration);
    int half_period_samples = (int)(SAMPLE_RATE / (2 * square_frequency));
    int square_wave[half_period_samples*2];
    for (int i = 0; i < half_period_samples; i++) {
        square_wave[i] = AMPLITUDE;
    }
    for (int i = half_period_samples; i < half_period_samples*2; i++) {
        square_wave[i] = -AMPLITUDE;
    }

    // Create buffer to hold audio data
    int* audio_buffer = (int*)malloc(num_samples * sizeof(int));
    for (int i = 0; i < num_samples; i++) {
        audio_buffer[i] = 0;
    }

    // Generate square wave by looping through the square wave buffer
    int buffer_position = 0;
    for (int i = 0; i < num_samples; i++) {
        audio_buffer[i] = square_wave[buffer_position];
        buffer_position++;
        if (buffer_position == half_period_samples*2) {
            buffer_position = 0;
        }
    }

    // Write audio data to a WAV file
    FILE* output_file = fopen("square_wave.wav", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }
    // Write the WAV file header
    char chunk_id[4] = {'R', 'I', 'F', 'F'};
    int32_t chunk_size = 36 + num_samples*sizeof(int);
    char format[4] = {'W', 'A', 'V', 'E'};
    char subchunk1_id[4] = {'f', 'm', 't', ' '};
    int32_t subchunk1_size = 16;
    int16_t audio_format = 1;
    int16_t num_channels = 1;
    int32_t sample_rate = SAMPLE_RATE;
    int32_t byte_rate = SAMPLE_RATE*sizeof(int);
    int16_t block_align = sizeof(int);
    int16_t bits_per_sample = sizeof(int)*8;
    char subchunk2_id[4] = {'d', 'a', 't', 'a'};
    int32_t subchunk2_size = num_samples*sizeof(int);
    fwrite(chunk_id, sizeof(char), 4, output_file);
    fwrite(&chunk_size, sizeof(int32_t), 1, output_file);
    fwrite(format, sizeof(char), 4, output_file);
    fwrite(subchunk1_id, sizeof(char), 4, output_file);
    fwrite(&subchunk1_size, sizeof(int32_t), 1, output_file);
    fwrite(&audio_format, sizeof(int16_t), 1, output_file);
    fwrite(&num_channels, sizeof(int16_t), 1, output_file);
    fwrite(&sample_rate, sizeof(int32_t), 1, output_file);
    fwrite(&byte_rate, sizeof(int32_t), 1, output_file);
    fwrite(&block_align, sizeof(int16_t), 1, output_file);
    fwrite(&bits_per_sample, sizeof(int16_t), 1, output_file);
    fwrite(subchunk2_id, sizeof(char), 4, output_file);
    fwrite(&subchunk2_size, sizeof(int32_t), 1, output_file);
    // Write the audio data
    fwrite(audio_buffer, sizeof(int), num_samples, output_file);
    fclose(output_file);

    // Free memory
    free(audio_buffer);

    return 0;
}