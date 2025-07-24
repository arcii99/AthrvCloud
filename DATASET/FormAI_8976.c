//FormAI DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY 0x1F

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if(argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        exit(1);
    }

    // Open output file
    FILE *output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Error creating output file: %s\n", argv[2]);
        fclose(input_file);
        exit(1);
    }

    // Read input file and encrypt data
    int ch;
    while((ch = fgetc(input_file)) != EOF) {
        // Shift bits and XOR with key to encrypt
        ch = (ch << 1) ^ KEY;

        // Write encrypted data to output file
        fputc(ch, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete!\n");

    return 0;
}