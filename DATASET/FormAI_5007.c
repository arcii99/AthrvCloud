//FormAI DATASET v1.0 Category: Audio processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 2048

void apply_amplitude_modulation(float mod_depth, float mod_freq, short* buffer, int buffer_size, int sample_rate){
    int i;
    float mod_phase;
    float mod_amplitude;

    float mod_angular_freq = 2 * M_PI * mod_freq;
    float mod_decay_factor = powf(0.5, (mod_angular_freq / sample_rate));

    mod_amplitude = 1.0 - mod_depth;
    mod_phase = 0.0;

    for (i = 0; i < buffer_size; i++) {
        buffer[i] *= mod_amplitude + mod_depth * sinf(mod_phase);
        mod_phase += mod_angular_freq;
        mod_amplitude *= mod_decay_factor;
    }
}

int main(int argc, char** argv){
    if (argc < 4) {
        printf("Usage: %s input.wav output.wav AMPLITUDE_MODULATION_FREQ AMPLITUDE_MODULATION_DEPTH\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file){
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if (!output_file){
        printf("Could not open file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    float mod_freq = atof(argv[3]);
    float mod_depth = atof(argv[4]);

    // Read input file header
    char header[44];
    fread(header, sizeof(char), 44, input_file);

    // Read input data
    short buffer[BUFFER_SIZE];
    int samples_read;
    while ((samples_read = fread(buffer, sizeof(short), BUFFER_SIZE, input_file)) > 0){
        apply_amplitude_modulation(mod_depth, mod_freq, buffer, samples_read, 44100);
        fwrite(buffer, sizeof(short), samples_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}