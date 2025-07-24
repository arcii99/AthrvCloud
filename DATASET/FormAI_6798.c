//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Max length of metadata values
#define MAX_LEN 200

// Struct to store metadata
typedef struct Metadata {
    char* name;
    char* value;
} Metadata;

// Function to extract metadata from a file
bool extractMetadata(const char* filename, Metadata* metadata, int* numMetadata) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    char line[MAX_LEN];
    int lineNumber = 0;
    int metadataCount = 0;

    while (fgets(line, MAX_LEN, file) != NULL) {
        lineNumber++;

        // Check if line starts with "META:"
        if (strncmp(line, "META:", 5) == 0) {
            // Parse metadata name and value
            char* name = strtok(line + 5, ":");
            char* value = strtok(NULL, "");

            if (name != NULL && value != NULL) {
                // Remove leading/trailing whitespace from value
                value = strtok(value, "\n");
                value = strtok(value, "\r");
                value = strtok(value, " ");
                value = strtok(value, "\t");

                // Allocate space for metadata name/value
                char* nameCopy = (char*) malloc(strlen(name) + 1);
                char* valueCopy = (char*) malloc(strlen(value) + 1);

                strcpy(nameCopy, name);
                strcpy(valueCopy, value);

                metadata[metadataCount].name = nameCopy;
                metadata[metadataCount].value = valueCopy;
                metadataCount++;
            } else {
                printf("Error in metadata parsing at line %d\n", lineNumber);
            }
        }
    }

    *numMetadata = metadataCount;
    fclose(file);
    return true;
}

int main() {
    const char* filename = "example.txt";
    Metadata metadata[MAX_LEN];
    int numMetadata = 0;

    bool success = extractMetadata(filename, metadata, &numMetadata);

    if (success) {
        printf("%d metadata values extracted:\n", numMetadata);
        for (int i = 0; i < numMetadata; i++) {
            printf("%s: %s\n", metadata[i].name, metadata[i].value);
        }
    } else {
        printf("Failed to extract metadata from file\n");
    }

    // Free metadata memory
    for (int i = 0; i < numMetadata; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }

    return 0;
}