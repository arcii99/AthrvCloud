//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    // Check if file path is provided.
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

    // Open file in read-mode.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return -1;
    }

    // Read file data into a buffer.
    char buffer[BUFFER_SIZE];
    size_t size = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    // Search for metadata tag in buffer.
    char *tag = "<metadata>";
    char *start = strstr(buffer, tag);
    if (start == NULL) {
        printf("Metadata tag not found in file: %s\n", argv[1]);
        return -1;
    }

    // Find end tag position.
    char *end = strstr(start, "</metadata>");
    if (end == NULL) {
        printf("Metadata end tag not found in file: %s\n", argv[1]);
        return -1;
    }

    // Calculate metadata length.
    int length = end - start + strlen("</metadata>");

    // Extract metadata string.
    char metadata[length + 1];
    strncpy(metadata, start, length);
    metadata[length] = '\0';

    // Print metadata.
    printf("Metadata in file %s: %s\n", argv[1], metadata);

    return 0;
}