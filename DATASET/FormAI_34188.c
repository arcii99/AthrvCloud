//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

/* Struct to hold metadata extracted from file */
typedef struct {
    char author[100];
    char creationDate[20];
    char description[200];
} Metadata;

/* Function to extract metadata from file */
Metadata extractMetadata(const char* filename) {
    Metadata metaData;
    FILE* file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (strstr(line, "AUTHOR:")) {
            sscanf(line, "AUTHOR: %[^\n]", metaData.author);
        }
        if (strstr(line, "CREATION DATE:")) {
            sscanf(line, "CREATION DATE: %[^\n]", metaData.creationDate);
        }
        if (strstr(line, "DESCRIPTION:")) {
            sscanf(line, "DESCRIPTION: %[^\n]", metaData.description);
        }
    }

    fclose(file);
    return metaData;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Metadata metaData = extractMetadata(argv[1]);
    printf("Author: %s\n", metaData.author);
    printf("Creation Date: %s\n", metaData.creationDate);
    printf("Description: %s\n", metaData.description);

    return 0;
}