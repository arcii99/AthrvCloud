//FormAI DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>

/*
 * This program takes an input audio file and performs a recursive echo effect,
 * where the sound repeats with a lower volume each time.
 */

typedef struct {
    short left;
    short right;
} Sample;

void recursive_echo(FILE *input_file, FILE *output_file, float volume, int depth) {
    const int BUFFER_SIZE = 1024;
    Sample buffer[BUFFER_SIZE];
    int read_count = fread(buffer, sizeof(Sample), BUFFER_SIZE, input_file);
    if (read_count == 0) {
        // base case: end of file
        return;
    }
    for (int i = 0; i < read_count; i++) {
        // apply the echo effect to each sample in the buffer
        buffer[i].left += (short) (volume * buffer[i].left);
        buffer[i].right += (short) (volume * buffer[i].right);
    }
    fwrite(buffer, sizeof(Sample), read_count, output_file);
    if (depth > 0) {
        // recursive case: perform another echo with lower volume
        recursive_echo(input_file, output_file, volume / 2, depth - 1);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file \"%s\"\n", argv[1]);
        return 1;
    }
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file \"%s\"\n", argv[2]);
        fclose(input_file);
        return 1;
    }
    recursive_echo(input_file, output_file, 1.0f, 10);
    fclose(input_file);
    fclose(output_file);
    return 0;
}