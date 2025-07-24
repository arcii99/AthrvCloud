//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    FILE *input_file, *output_file;

    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(EXIT_FAILURE);
    }

    // read in audio file
    short int buffer[BUFFER_SIZE];
    while (!feof(input_file)) {
        int elements_read = fread(buffer, sizeof(short int), BUFFER_SIZE, input_file);
        for (int i = 0; i < elements_read; i++) {
            double sample = (double)buffer[i] / 32767.0; // normalize to [-1, 1]
            sample = sin(sample); // apply the sin function
            buffer[i] = (short int)(sample * 32767.0); // convert back to integer
        }
        fwrite(buffer, sizeof(short int), elements_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}