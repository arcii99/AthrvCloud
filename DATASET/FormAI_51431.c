//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

typedef struct {
    char key[50];
    char value[50];
} Metadata;

Metadata metadataArray[MAX_METADATA_SIZE];

int main(int argc, char *argv[]) {
    char *metadataString = "{author: John Doe, year: 2021, language: C}";

    // Separate metadata key-value pairs
    char *token = strtok(metadataString, "{,}");
    int metadataCount = 0;
    while (token != NULL) {
        char copy[50];
        strcpy(copy, token);

        char *key = strtok(copy, ":");
        char *value = strtok(NULL, ":");

        // Remove trailing and leading whitespaces
        strcpy(metadataArray[metadataCount].key, key + strspn(key, " "));
        strcpy(metadataArray[metadataCount].value, value + strspn(value, " ") + 1);
        
        metadataCount++;
        token = strtok(NULL, "{,}");
    }

    // Print metadata
    for (int i = 0; i < metadataCount; i++) {
        printf("%s: %s\n", metadataArray[i].key, metadataArray[i].value);
    }

    return 0;
}