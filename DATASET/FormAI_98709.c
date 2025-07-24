//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    // Check if file name provided
    if (argc < 2) {
        printf("Please provide file name\n");
        return 1;
    }

    // Open input file        
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Unable to open input file\n");
        return 1;
    }

    // Create output file
    char *output_file_name = malloc(strlen(argv[1]) + 8);
    strcpy(output_file_name, argv[1]);
    strcat(output_file_name, ".encrypted");
    FILE *output_file = fopen(output_file_name, "wb");
    if (!output_file) {
        printf("Unable to create output file\n");
        return 1;
    }

    // Create encryption key
    unsigned char key = 0x3F;

    // Synchronous encryption
    unsigned char buffer[1024];
    while(fread(buffer, sizeof(char), sizeof(buffer), input_file)) {
        for (int i = 0; i < sizeof(buffer); i++) {
            buffer[i] ^= key; // XOR with encryption key
        }
        fwrite(buffer, sizeof(char), sizeof(buffer), output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete\n");

    return 0;
}