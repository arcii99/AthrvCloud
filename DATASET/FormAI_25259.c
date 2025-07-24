//FormAI DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_SIZE 256
#define BLOCK_SIZE 4096

int main(int argc, char **argv) {
    char filename[MAX_FILENAME_SIZE];
    unsigned char blocks[BLOCK_SIZE];
    FILE *input_file, *output_file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    strcpy(filename, argv[1]);

    input_file = fopen(filename, "rb");

    if (input_file == NULL) {
        printf("Could not open file %s\n", filename);
        return -1;
    }

    output_file = fopen("recovered_file", "wb");

    if (output_file == NULL) {
        printf("Could not create file %s\n", "recovered_file");
        fclose(input_file);
        return -1;
    }

    while (fread(blocks, BLOCK_SIZE, 1, input_file) > 0) {
        fwrite(blocks, BLOCK_SIZE, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery successful. Please check the file recovered_file\n");

    return 0;
}