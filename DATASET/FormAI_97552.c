//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename, *metadata;
    long size;

    if (argc < 2) {
        printf("Usage: metadata_extractor <filename>\n");
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "rb");

    if (!file) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for metadata string
    metadata = (char*)malloc(size + 1);

    // Read file contents into metadata string
    fread(metadata, 1, size, file);

    // Add null terminator to metadata string
    metadata[size] = '\0';

    // Print metadata
    printf("Metadata for file: %s\n\n", filename);
    printf("%s\n", metadata);

    // Clean up
    free(metadata);
    fclose(file);

    return 0;
}