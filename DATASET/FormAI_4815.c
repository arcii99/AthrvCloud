//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: You must provide a file name as an argument.\n");
        return -1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for reading.\n", filename);
        return -1;
    }

    // Placeholder code for metadata extraction
    printf("Metadata for file '%s':\n", filename);
    printf("Resolution: 1920x1080\n");
    printf("Date taken: Jan 1, 2020\n");

    fclose(file);
    return 0;
}