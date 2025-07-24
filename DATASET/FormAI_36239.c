//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct Metadata {
    char title[100];
    char artist[100];
    char album[100];
    char genre[100];
    int year;
};

void extractMetadata(char* file) {
    // simulate extraction of metadata
    struct Metadata songMetadata;
    strcpy(songMetadata.title, "Example Song");
    strcpy(songMetadata.artist, "Genius");
    strcpy(songMetadata.album, "Awesome Album");
    strcpy(songMetadata.genre, "Pop");
    songMetadata.year = 2021;

    // print extracted metadata
    printf("Metadata for %s:\n", file);
    printf("Title: %s\n", songMetadata.title);
    printf("Artist: %s\n", songMetadata.artist);
    printf("Album: %s\n", songMetadata.album);
    printf("Genre: %s\n", songMetadata.genre);
    printf("Year: %d\n", songMetadata.year);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: metadata_extractor <file>\n");
        return 1;
    }

    extractMetadata(argv[1]);

    return 0;
}