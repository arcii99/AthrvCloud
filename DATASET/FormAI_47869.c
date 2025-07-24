//FormAI DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Check if enough arguments are passed
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(1);
    }

    // Open the input file
    FILE *inputFile;
    inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open the output file
    FILE *outputFile;
    outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Get the key
    int key = atoi(argv[3]);

    // Read the input file
    unsigned char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(unsigned char), sizeof(buffer), inputFile)) > 0) {
        // Encrypt the buffer with XOR
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;
        }
        // Write the encrypted buffer to the output file
        fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}