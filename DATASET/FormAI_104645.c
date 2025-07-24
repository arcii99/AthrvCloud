//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(FILE* input, FILE* output, const char* key) {
    int key_len = strlen(key);
    int i = 0, j = 0;
    char input_char;

    while ((input_char = fgetc(input)) != EOF) {
        char output_char = input_char ^ key[j % key_len];
        fputc(output_char, output);
        i++;
        j = (j + 1) % key_len;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* input = fopen(argv[1], "rb");
    if (!input) {
        printf("Error: Couldn't open input file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE* output = fopen(argv[2], "wb");
    if (!output) {
        printf("Error: Couldn't open output file %s\n", argv[2]);
        fclose(input);
        return EXIT_FAILURE;
    }

    const char* key = argv[3];

    encrypt(input, output, key);

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}