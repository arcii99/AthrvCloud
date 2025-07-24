//FormAI DATASET v1.0 Category: Data recovery tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please provide the name of the input and output files\n");
        return 1;
    }

    char *input_file_name = argv[1];
    char *output_file_name = argv[2];

    FILE *input_file = fopen(input_file_name, "rb");
    if (!input_file) {
        printf("Failed to open input file\n");
        return 1;
    }

    FILE *output_file = fopen(output_file_name, "wb");
    if (!output_file) {
        printf("Failed to open output file\n");
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    int count = 0;
    int byte_count = 0;
    while ((count = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        byte_count += count;
        fwrite(buffer, 1, count, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Successfully recovered %d bytes of data from %s to %s\n", byte_count, input_file_name, output_file_name);

    return 0;
}