//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to store metadata information
typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
} Metadata;

void extractMetadata(char *filename, Metadata *metadata) {
    // open file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // read file line by line
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // extract title
        if (strncmp(line, "TITLE=", 6) == 0) {
            strcpy(metadata->title, line + 6);
            metadata->title[strcspn(metadata->title, "\n")] = '\0'; // remove trailing newline
        }
        // extract artist
        else if (strncmp(line, "ARTIST=", 7) == 0) {
            strcpy(metadata->artist, line + 7);
            metadata->artist[strcspn(metadata->artist, "\n")] = '\0'; // remove trailing newline
        }
        // extract album
        else if (strncmp(line, "ALBUM=", 6) == 0) {
            strcpy(metadata->album, line + 6);
            metadata->album[strcspn(metadata->album, "\n")] = '\0'; // remove trailing newline
        }
        // extract year
        else if (strncmp(line, "YEAR=", 5) == 0) {
            metadata->year = atoi(line + 5);
        }
    }

    // close file
    fclose(fp);
}

int main() {
    // create metadata struct
    Metadata metadata;

    // extract metadata from file
    extractMetadata("song.mp3", &metadata);

    // print metadata
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);

    return 0;
}