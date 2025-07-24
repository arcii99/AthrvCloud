//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void compress(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file != NULL && output_file != NULL) {
        char buffer[BUFFER_SIZE];
        int count = 1;
        char current_char = fgetc(input_file);
        while (!feof(input_file)) {
            char next_char = fgetc(input_file);
            if (next_char == current_char) {
                count++;
            } else {
                fprintf(output_file, "%d%c", count, current_char);
                count = 1;
                current_char = next_char;
            }
        }
        fprintf(output_file, "%d%c", count, current_char);
        fclose(input_file);
        fclose(output_file);
    } else {
        printf("Error opening files!\n");
    }
}

void decompress(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file != NULL && output_file != NULL) {
        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
            int count = atoi(strtok(buffer, " "));
            char current_char = strtok(NULL, "\n")[0];
            for (int i = 0; i < count; i++) {
                fprintf(output_file, "%c", current_char);
            }
        }
        fclose(input_file);
        fclose(output_file);
    } else {
        printf("Error opening files!\n");
    }
}

int main() {
    printf("Welcome to my custom compression algorithm!\n");
    printf("Please enter the name of the input file: ");
    char input_filename[BUFFER_SIZE];
    fgets(input_filename, BUFFER_SIZE, stdin);
    input_filename[strcspn(input_filename, "\n")] = 0; // remove newline character
    printf("Please enter the name of the output file: ");
    char output_filename[BUFFER_SIZE];
    fgets(output_filename, BUFFER_SIZE, stdin);
    output_filename[strcspn(output_filename, "\n")] = 0; // remove newline character

    // compress the file
    printf("Compressing file...\n");
    compress(input_filename, output_filename);
    printf("File successfully compressed!\n");

    // decompress the file
    printf("Decompressing file...\n");
    char decompressed_filename[BUFFER_SIZE];
    strcpy(decompressed_filename, output_filename);
    strncat(decompressed_filename, "_decompressed", BUFFER_SIZE);
    decompress(output_filename, decompressed_filename);
    printf("File successfully decompressed into %s!\n", decompressed_filename);

    return 0;
}