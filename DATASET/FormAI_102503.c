//FormAI DATASET v1.0 Category: Audio processing ; Style: Romeo and Juliet
// Romeo and Juliet: An Audio Processing Love Story
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

int main() {
    // Romeo's sound wave
    uint16_t* romeos_waveform = malloc(sizeof(uint16_t) * SAMPLE_RATE);
    for (int i = 0; i < SAMPLE_RATE; i++) {
        double t = (double)i / SAMPLE_RATE;
        double freq = 440 * pow(2, (i/44100.0)*10.0);
        romeos_waveform[i] = (uint16_t)(32767.0 * sin(2 * PI * freq * t));
    }

    // Juliet's sound wave
    uint16_t* juliets_waveform = malloc(sizeof(uint16_t) * SAMPLE_RATE);
    for (int i = 0; i < SAMPLE_RATE; i++) {
        double t = (double)i / SAMPLE_RATE;
        double freq = 440 * pow(2, (-i/44100.0)*10.0);
        juliets_waveform[i] = (uint16_t)(32767.0 * sin(2 * PI * freq * t));
    }

    // Combine Romeo and Juliet's sound waves
    uint16_t* combined_waveform = malloc(sizeof(uint16_t) * SAMPLE_RATE);
    for (int i = 0; i < SAMPLE_RATE; i++) {
        combined_waveform[i] = romeos_waveform[i] + juliets_waveform[i];
        if (combined_waveform[i] > 32767) {
            combined_waveform[i] = 32767;
        }
    }

    // Write combined wave to a WAVE file
    FILE* f = fopen("romeo_and_juliet.wav", "wb");
    // RIFF header
    fwrite("RIFF", 1, 4, f);
    uint32_t chunk_size = 36 + SAMPLE_RATE * 2;
    fwrite(&chunk_size, 4, 1, f);
    fwrite("WAVE", 1, 4, f);
    // Format subchunk
    fwrite("fmt ", 1, 4, f);
    uint32_t subchunk1_size = 16;
    fwrite(&subchunk1_size, 4, 1, f);
    uint16_t audio_format = 1;
    fwrite(&audio_format, 2, 1, f);
    uint16_t num_channels = 2;
    fwrite(&num_channels, 2, 1, f);
    uint32_t byte_rate = SAMPLE_RATE * num_channels * 2;
    fwrite(&byte_rate, 4, 1, f);
    uint16_t block_align = num_channels * 2;
    fwrite(&block_align, 2, 1, f);
    uint16_t bits_per_sample = 16;
    fwrite(&bits_per_sample, 2, 1, f);
    // Data subchunk
    fwrite("data", 1, 4, f);
    fwrite(&chunk_size, 4, 1, f);
    for (int i = 0; i < SAMPLE_RATE; i++) {
        fwrite(&combined_waveform[i], 2, 1, f);
        fwrite(&combined_waveform[i], 2, 1, f);
    }
    fclose(f);

    free(romeos_waveform);
    free(juliets_waveform);
    free(combined_waveform);

    printf("Their love may have been fleeting, but their combined waveform is forever immortalized in 'romeo_and_juliet.wav'.\n");
    return 0;
}