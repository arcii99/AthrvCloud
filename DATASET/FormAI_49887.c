//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from file
void extract_metadata(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *metadata;
    int metadata_flag = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Extract metadata
    while ((read = getline(&line, &len, fp)) != -1) {
        if (metadata_flag == 1) {
            metadata = line;
            metadata_flag = 0;
        }
        if (strcmp(line, "metadata\n") == 0) {
            metadata_flag = 1;
        }
    }

    // Print metadata
    printf("Metadata: %s", metadata);

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    extract_metadata(argv[1]);

    return 0;
}