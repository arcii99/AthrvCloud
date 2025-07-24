//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct Metadata {
    char artist[MAX_LINE_LENGTH];
    char album[MAX_LINE_LENGTH];
    char year[MAX_LINE_LENGTH];
} Metadata;

int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc != 2) {
        printf("No filename provided! Please provide a filename as an argument.\n");
        return 1;
    }

    // Attempt to open the file for reading
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file '%s'!\n", argv[1]);
        return 1;
    }

    // Parse metadata from the file
    Metadata metadata;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (strncmp(line, "ARTIST=", 7) == 0) {
            strncpy(metadata.artist, line + 7, MAX_LINE_LENGTH - 7);
        } else if (strncmp(line, "ALBUM=", 6) == 0) {
            strncpy(metadata.album, line + 6, MAX_LINE_LENGTH - 6);
        } else if (strncmp(line, "YEAR=", 5) == 0) {
            strncpy(metadata.year, line + 5, MAX_LINE_LENGTH - 5);
        }
    }

    // Close the file
    fclose(file);

    // Print out the extracted metadata
    printf("Extracted Metadata:\n");
    printf("Artist: %s", metadata.artist);
    printf("Album: %s", metadata.album);
    printf("Year: %s", metadata.year);

    // Exit the program
    return 0;
}