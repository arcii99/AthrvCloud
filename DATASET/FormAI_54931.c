//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

struct Metadata {
    int timestamp;
    char author[50];
    char description[256];
};

typedef struct Metadata Metadata;

int main(int argc, char *argv[]) {
    char metadata[MAX_METADATA_SIZE];

    // Read metadata from input file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }
    fgets(metadata, MAX_METADATA_SIZE, inputFile);
    fclose(inputFile);

    // Parse metadata
    Metadata extractedMetadata;
    char *token;
    token = strtok(metadata, ",");
    extractedMetadata.timestamp = atoi(token);
    token = strtok(NULL, ",");
    strncpy(extractedMetadata.author, token, sizeof(extractedMetadata.author) - 1);
    token = strtok(NULL, ",");
    strncpy(extractedMetadata.description, token, sizeof(extractedMetadata.description) - 1);

    // Print extracted metadata
    printf("Timestamp: %d\n", extractedMetadata.timestamp);
    printf("Author: %s\n", extractedMetadata.author);
    printf("Description: %s\n", extractedMetadata.description);

    return 0;
}