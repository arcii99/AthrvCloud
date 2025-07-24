//FormAI DATASET v1.0 Category: Audio processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Define variables
    int sample_rate = 44100;
    int num_channels = 1;
    int bit_depth = 16;
    int duration = 10;
    int num_samples = sample_rate * num_channels * duration;
    int max_amplitude = (int) pow(2, bit_depth - 1) - 1; // Maximum possible amplitude for given bit depth
    double frequency = 440.0; // A4 pitch frequency
    double amplitude = 0.5; // Volume of waveform
    int delay_time = 0.1 * sample_rate; // 100 millisecond delay
    
    // Allocate memory for audio buffer
    signed short *audio_buffer = (signed short *) malloc(num_samples * sizeof(signed short));
    
    // Generate sine wave
    for (int i = 0; i < num_samples; i++) {
        double sample_value = amplitude * max_amplitude * sin(2 * M_PI * frequency * i / sample_rate);
        audio_buffer[i] = (signed short) sample_value;
    }
    
    // Apply delay effect
    for (int i = delay_time; i < num_samples; i++) {
        audio_buffer[i] += audio_buffer[i - delay_time];
    }
    
    // Normalize audio
    int max_value = 0;
    for (int i = 0; i < num_samples; i++) {
        if (abs(audio_buffer[i]) > max_value) {
            max_value = abs(audio_buffer[i]);
        }
    }
    double normalize_factor = (double) max_amplitude / max_value;
    for (int i = 0; i < num_samples; i++) {
        audio_buffer[i] *= normalize_factor;
    }
    
    // Write audio data to file
    FILE *file = fopen("output.wav", "wb");
    int byte_rate = sample_rate * num_channels * bit_depth / 8;
    int block_align = num_channels * bit_depth / 8;
    fwrite("RIFF", sizeof(char), 4, file);
    int file_size = 36 + num_samples * num_channels * bit_depth / 8;
    fwrite(&file_size, sizeof(int), 1, file);
    fwrite("WAVE", sizeof(char), 4, file);
    fwrite("fmt ", sizeof(char), 4, file);
    int fmt_size = 16;
    fwrite(&fmt_size, sizeof(int), 1, file);
    short audio_format = 1; // PCM
    fwrite(&audio_format, sizeof(short), 1, file);
    fwrite(&num_channels, sizeof(short), 1, file);
    fwrite(&sample_rate, sizeof(int), 1, file);
    fwrite(&byte_rate, sizeof(int), 1, file);
    fwrite(&block_align, sizeof(short), 1, file);
    fwrite(&bit_depth, sizeof(short), 1, file);
    fwrite("data", sizeof(char), 4, file);
    fwrite(&num_samples, sizeof(int), 1, file);
    fwrite(audio_buffer, sizeof(signed short), num_samples, file);
    fclose(file);
    
    // Free memory
    free(audio_buffer);
    
    return 0;
}