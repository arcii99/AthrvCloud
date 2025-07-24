//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 100

void extract_metadata(char *file_path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    extract_metadata(argv[1]);

    printf("Metadata extracted successfully!\n");

    return 0;
}

void extract_metadata(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        exit(EXIT_FAILURE);
    }

    char metadata[MAX_METADATA_SIZE];
    char line[MAX_METADATA_SIZE];
    int metadata_length = 0;

    while (fgets(line, MAX_METADATA_SIZE, file) != NULL) {
        if (strcmp(line, "/*METADATA*/\n") == 0) {
            while (fgets(line, MAX_METADATA_SIZE, file) != NULL) {
                if (strcmp(line, "/*END_METADATA*/\n") == 0) {
                    break;
                }
                strcat(metadata, line);
                metadata_length += strlen(line);
            }
            break;
        }
    }

    fclose(file);

    // Do something with the metadata
    // ...

    printf("Metadata extracted (%d bytes):\n%s\n", metadata_length, metadata);
}