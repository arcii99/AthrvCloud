//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    char title[50];
    char artist[50];
    char album[50];
    char genre[50];
    int year;
} Metadata;

Metadata extract_metadata(char *filename) {
    Metadata metadata;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fseek(file, -128, SEEK_END);
    char tag[3];
    fread(tag, sizeof(tag), 1, file);
    if (memcmp(tag, "TAG", 3) == 0) {
        fread(metadata.title, sizeof(metadata.title), 1, file);
        fread(metadata.artist, sizeof(metadata.artist), 1, file);
        fread(metadata.album, sizeof(metadata.album), 1, file);
        fread(&metadata.year, sizeof(metadata.year), 1, file);
        fread(metadata.genre, sizeof(metadata.genre), 1, file);
    }
    fclose(file);
    return metadata;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: metadata_extractor <filename>\n");
        exit(1);
    }
    Metadata metadata = extract_metadata(argv[1]);
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);
    return 0;
}