//FormAI DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE     44100
#define SAMPLE_SIZE     16
#define NUM_CHANNELS    2

/* Function to generate a sine wave with the designated frequency and duration */
void generate_sine_wave(double frequency, double duration, short *buffer) {
    int num_samples = duration * SAMPLE_RATE;
    double amplitude = (pow(2, SAMPLE_SIZE - 1) - 1);

    for (int i = 0; i < num_samples * NUM_CHANNELS; i += NUM_CHANNELS) {
        double time = (double)i / (double)SAMPLE_RATE;
        double value = sin(2 * M_PI * frequency * time);
        
        buffer[i] = (short)(value * amplitude);
        buffer[i + 1] = (short)(value * amplitude);
    }
}

/* Function to write the audio data to a wave file */
void write_wave_file(char *filename, short *buffer, int num_samples) {
    FILE *file = fopen(filename, "wb");
    
    /* Write the RIFF header */
    char riff_header[4] = {'R', 'I', 'F', 'F'};
    fwrite(riff_header, sizeof(char), 4, file);
    
    int chunk_size = 36 + (num_samples * NUM_CHANNELS * SAMPLE_SIZE / 8);
    fwrite(&chunk_size, sizeof(int), 1, file);
    
    char wave_header[4] = {'W', 'A', 'V', 'E'};
    fwrite(wave_header, sizeof(char), 4, file);

    /* Write the format subchunk */
    char format_header[4] = {'f', 'm', 't', ' '};
    fwrite(format_header, sizeof(char), 4, file);

    int subchunk_size = 16;
    fwrite(&subchunk_size, sizeof(int), 1, file);

    short audio_format = 1;
    fwrite(&audio_format, sizeof(short), 1, file);
    
    short num_channels = NUM_CHANNELS;
    fwrite(&num_channels, sizeof(short), 1, file);
    
    int sample_rate = SAMPLE_RATE;
    fwrite(&sample_rate, sizeof(int), 1, file);
    
    int byte_rate = SAMPLE_RATE * NUM_CHANNELS * SAMPLE_SIZE / 8;
    fwrite(&byte_rate, sizeof(int), 1, file);
    
    short block_align = NUM_CHANNELS * SAMPLE_SIZE / 8;
    fwrite(&block_align, sizeof(short), 1, file);
    
    short bits_per_sample = SAMPLE_SIZE;
    fwrite(&bits_per_sample, sizeof(short), 1, file);

    /* Write the data subchunk */
    char data_header[4] = {'d', 'a', 't', 'a'};
    fwrite(data_header, sizeof(char), 4, file);
    
    int data_size = num_samples * NUM_CHANNELS * SAMPLE_SIZE / 8;
    fwrite(&data_size, sizeof(int), 1, file);
    
    fwrite(buffer, sizeof(short), num_samples * NUM_CHANNELS, file);

    fclose(file);
}

int main() {
    int duration = 5; /* 5 seconds */
    short *buffer = malloc(duration * SAMPLE_RATE * NUM_CHANNELS * sizeof(short));
  
    generate_sine_wave(440 /* Hz */, duration, buffer);
    write_wave_file("output.wav", buffer, duration * SAMPLE_RATE * NUM_CHANNELS);
  
    free(buffer);
    return 0;
}