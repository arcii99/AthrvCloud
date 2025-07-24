//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

void compress(char *inputFile, char *outputFile) {
    // Open input file
    FILE *in = fopen(inputFile, "r");
    if (in == NULL) {
        printf("Error: Cannot open input file!\n");
        exit(1);
    }

    // Open output file
    FILE *out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Error: Cannot open output file!\n");
        exit(1);
    }

    // Allocate memory
    char *buffer = (char *)malloc(MAX_LEN * sizeof(char));
    char *compressed = (char *)calloc(MAX_LEN, sizeof(char));
    if (buffer == NULL || compressed == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    // Read input file
    int len = fread(buffer, sizeof(char), MAX_LEN, in);

    // Compress string
    int compressedLen = 0;
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == buffer[i+1]) {
            count++;
        } else {
            compressed[compressedLen++] = buffer[i];
            compressed[compressedLen++] = count + '0';
            count = 1;
        }
    }

    // Write to output file
    fwrite(compressed, sizeof(char), compressedLen, out);

    // Close files
    fclose(in);
    fclose(out);

    // Free memory
    free(buffer);
    free(compressed);

    printf("Compression completed successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: compress <inputFile> <outputFile>\n");
        exit(1);
    }

    // Get input and output files
    char *inputFile = argv[1];
    char *outputFile = argv[2];

    // Compress file
    compress(inputFile, outputFile);

    return 0;
}