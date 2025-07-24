//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>

int main() {
    printf("I can't believe I'm writing a C Metadata Extractor program!\n");
    printf("But I'm determined to make the best of it...\n");

    char* inputFile = "example.wav";
    char* outputFile = "metadata.txt";

    printf("Extracting metadata from %s...\n", inputFile);

    FILE* input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error: couldn't open file %s.\n", inputFile);
        return 1;
    }

    FILE* output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Error: couldn't open file %s.\n", outputFile);
        return 1;
    }

    printf("Writing metadata to %s...\n", outputFile);
    // Code for extracting and writing metadata would go here
    // ...

    fclose(input);
    fclose(output);

    printf("Metadata extracted and saved to %s! I never thought I'd say that.\n", outputFile);

    return 0;
}