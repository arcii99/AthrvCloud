//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

char* extract_metadata(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    char* metadata = malloc(SIZE * sizeof(char));
    int metadata_len = 0;
    int c;

    // Skip over file header
    while((c = fgetc(fp)) != EOF && c != ':') {}

    // Read in metadata until newline character is encountered
    while((c = fgetc(fp)) != EOF && c != '\n') {
        // Ignore whitespace before metadata
        if(c != ' ' && c != '\t') {
            metadata[metadata_len++] = c;
        }
    }

    // Null terminate metadata string
    metadata[metadata_len] = '\0';

    fclose(fp);
    return metadata;
}

int main() {
    char* filename = "example.txt";
    char* metadata = extract_metadata(filename);

    if(metadata != NULL) {
        printf("Metadata found in %s: %s\n", filename, metadata);
    } else {
        printf("No metadata found in %s.\n", filename);
    }

    free(metadata);
    return 0;
}