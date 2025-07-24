//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct metadata {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    char year[MAX_LENGTH];
} Metadata;

// Function to extract metadata from a file
Metadata extractMetadata(FILE* fp) {
    Metadata m;
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, fp)) {
        // Check if the line contains any metadata information
        if (strncmp(line, "Title:", 6) == 0) {
            strcpy(m.title, strchr(line, ':') + 1);
            m.title[strcspn(m.title, "\r\n")] = 0;
        }
        
        if (strncmp(line, "Artist:", 7) == 0) {
            strcpy(m.artist, strchr(line, ':') + 1);
            m.artist[strcspn(m.artist, "\r\n")] = 0;
        }
        
        if (strncmp(line, "Album:", 6) == 0) {
            strcpy(m.album, strchr(line, ':') + 1);
            m.album[strcspn(m.album, "\r\n")] = 0;
        }
        
        if (strncmp(line, "Year:", 5) == 0) {
            strcpy(m.year, strchr(line, ':') + 1);
            m.year[strcspn(m.year, "\r\n")] = 0;
        }
    }

    return m;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    Metadata m = extractMetadata(fp);

    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %s\n", m.title, m.artist, m.album, m.year);

    fclose(fp);

    return EXIT_SUCCESS;
}