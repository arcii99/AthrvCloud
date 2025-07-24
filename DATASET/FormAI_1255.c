//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for holding the metadata information
struct Metadata {
    char *key;
    char *value;
};

int main() {
    char *input = "Metaname=Metadata Extractor\nKey1=Value1\nKey2=This is a very long value that goes over multiple lines\nKey3=Value3\n";

    // Splitting the input string into individual lines
    char *line = strtok(input, "\n");
    char **lines = malloc(sizeof(char *));
    int lineCount = 0;
    while(line != NULL) {
        lines[lineCount] = line;
        lineCount++;
        lines = realloc(lines, sizeof(char *) * (lineCount + 1));
        line = strtok(NULL, "\n");
    }

    // Parsing the metadata information from the lines
    struct Metadata *metadata = malloc(sizeof(struct Metadata));
    int metadataCount = 0;
    for(int i=0; i<lineCount; i++) {
        char *key = strtok(lines[i], "=");
        char *value = strtok(NULL, "=");

        // If a key and value has been found, store it in the metadata array
        if(key != NULL && value != NULL) {
            metadata[metadataCount].key = malloc(strlen(key) + 1);
            metadata[metadataCount].value = malloc(strlen(value) + 1);
            strcpy(metadata[metadataCount].key, key);
            strcpy(metadata[metadataCount].value, value);
            metadataCount++;

            metadata = realloc(metadata, sizeof(struct Metadata) * (metadataCount + 1));
        }
    }

    // Printing out the metadata information
    for(int i=0; i<metadataCount; i++) {
        printf("Key: %s\nValue: %s\n", metadata[i].key, metadata[i].value);
    }

    // Clean up the memory
    for(int i=0; i<metadataCount; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }
    free(metadata);
    free(lines);
    return 0;
}