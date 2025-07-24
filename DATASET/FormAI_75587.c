//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from file
void extractMetadata(char* fileName) {
    int metadataSize;
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }

    // Read metadata size from file header
    fseek(file, 16, SEEK_SET);
    fread(&metadataSize, sizeof(int), 1, file);

    // Read metadata from file
    fseek(file, 20, SEEK_SET);
    char* metadata = (char*)malloc(metadataSize + 1);
    fread(metadata, metadataSize, 1, file);
    metadata[metadataSize] = '\0';

    // Print metadata
    printf("Metadata: %s\n", metadata);

    // Free memory and close file
    free(metadata);
    fclose(file);
}

int main() {
    char* fileName = "example.txt";
    extractMetadata(fileName);
    return 0;
}