//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from file
void extractMetadata(const char* filename, char* metadata[], int metadataSize) {
    FILE* file = fopen(filename, "r");
    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "//@", 3) == 0) { // Check for metadata
            strtok(line, " \t\n"); // Discard the //@ part
            metadata[i] = (char*)malloc(strlen(line) + 1);
            strcpy(metadata[i], line);
            i++;
        }

        if (i == metadataSize) {
            break;
        }
    }

    fclose(file);
}

int main() {
    char* metadata[10] = {0}; // Array to hold metadata
    extractMetadata("file.c", metadata, 10);

    // Print metadata
    for (int i = 0; i < 10; i++) {
        if (metadata[i] != NULL) {
            printf("%s\n", metadata[i]);
            free(metadata[i]);
        }
    }

    return 0;
}