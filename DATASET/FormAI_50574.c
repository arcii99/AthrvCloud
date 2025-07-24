//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/*
 * This function extracts metadata from a file and returns
 * it as a string.
 */
char* extract_metadata(const char* filename) {
    char* metadata = NULL;
    char* buffer = NULL;
    FILE* file = NULL;
    size_t size = 0;
    ssize_t read = 0;

    // Allocate buffer
    buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate buffer\n");
        return NULL;
    }

    // Open file
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        free(buffer);
        return NULL;
    }

    // Read metadata line by line
    while ((read = getline(&buffer, &size, file)) != -1) {
        if (strncmp(buffer, "META:", 5) == 0) {
            metadata = strdup(buffer + 5);
            break;
        }
    }

    // Close file and free buffer
    fclose(file);
    free(buffer);

    return metadata;
}

int main(int argc, char** argv) {
    char* metadata = NULL;

    // Extract metadata from file
    metadata = extract_metadata("example.txt");
    if (!metadata) {
        fprintf(stderr, "Failed to extract metadata\n");
        return EXIT_FAILURE;
    }

    // Print metadata
    printf("Metadata: %s\n", metadata);

    // Free metadata
    free(metadata);

    return EXIT_SUCCESS;
}