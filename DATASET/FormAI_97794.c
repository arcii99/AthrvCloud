//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_METADATA_COUNT 100

int main(int argc, char* argv[]) {
    FILE* file_ptr;
    char* file_data[MAX_LINES];
    char* metadata[MAX_METADATA_COUNT];
    int i = 0, j = 0, k = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }

    while (i < MAX_LINES && fgets(file_data[i], MAX_LINES-1, file_ptr) != NULL) {
        // Check for metadata in the current line
        if (strstr(file_data[i], "//") != NULL || strstr(file_data[i], "/*") != NULL) {
            metadata[k] = strdup(file_data[i]);
            k++;
        }
        i++;
    }

    // Print out all extracted metadata
    printf("Metadata found in %s:\n", argv[1]);
    for (j = 0; j < k; j++) {
        printf("%s\n", metadata[j]);
    }

    fclose(file_ptr);
    return 0;
}