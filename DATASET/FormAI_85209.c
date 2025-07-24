//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[50];
} Metadata;

void extract_metadata(char* filename, Metadata* info) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Could not open file\n");
        return;
    }

    // Skip header info
    fseek(fp, 128, SEEK_SET); 

    // Read metadata
    fread(info->title, sizeof(char), 30, fp);
    fread(info->artist, sizeof(char), 30, fp);
    fread(info->album, sizeof(char), 30, fp);
    fread(&info->year, sizeof(int), 1, fp);
    fread(info->genre, sizeof(char), 30, fp);

    // Cleanup
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    Metadata info;
    memset(&info, 0, sizeof(info)); // Clear memory

    extract_metadata(argv[1], &info);

    // Print metadata
    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\nGenre: %s\n", 
            info.title, info.artist, info.album, info.year, info.genre);

    return 0;
}