//FormAI DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BLOCK_SIZE 128

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Could not open input file %s\n", argv[1]);
        return 2;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        fclose(input_file);
        printf("Could not open output file %s\n", argv[2]);
        return 3;
    }

    int16_t input_buffer[BLOCK_SIZE];
    int16_t output_buffer[BLOCK_SIZE];

    float a1 = -1.99503571;
    float a2 = 0.995037418;
    float b0 = 0.99755633;
    float b1 = -1.99511266;
    float b2 = 0.99755633;

    float w[3] = {0.0f, 0.0f, 0.0f};

    while (!feof(input_file)) {
        int32_t bytes_read = fread(input_buffer, 1, sizeof(input_buffer), input_file);
        int32_t num_samples = bytes_read / sizeof(int16_t);

        for (int32_t i = 0; i < num_samples; i++) {
            // Filter out frequencies below 1kHz
            float input_sample = (float)input_buffer[i] / 32768.0f;
            float output_sample = b0*input_sample + b1*w[0] + b2*w[1];
            output_sample -= a1*w[2] + a2*w[1];

            // Clamp output to [-1.0, 1.0] and convert back to int16_t
            if (output_sample > 1.0f) {
                output_sample = 1.0f;
            } else if (output_sample < -1.0f) {
                output_sample = -1.0f;
            }
            output_buffer[i] = (int16_t)(output_sample * 32768.0f);

            // Shift delay line
            w[1] = w[0];
            w[0] = input_sample;
            w[2] = output_sample;
        }

        fwrite(output_buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}