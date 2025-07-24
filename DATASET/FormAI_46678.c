//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata
char* extract_metadata(char* filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s", filename);
        return NULL;
    }

    // Read the first line
    char buffer[256];
    fgets(buffer, 256, file);

    // Find the length of the metadata string
    int length = 0;
    while (buffer[length] != '\n') {
        length++;
    }

    // Create a new string to hold the metadata
    char* metadata = malloc((length + 1) * sizeof(char));

    // Copy the metadata from the buffer to the new string
    strncpy(metadata, buffer, length);
    metadata[length] = '\0';

    // Close the file and return the metadata
    fclose(file);
    return metadata;
}

int main() {
    // Test the metadata extractor
    char* filename = "example.txt";
    char* metadata = extract_metadata(filename);

    if (metadata != NULL) {
        printf("Metadata: %s\n", metadata);
        free(metadata);
    }

    return 0;
}