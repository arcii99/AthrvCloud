//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char* artist;
    char* album;
    char* genre;
    int year;
} Metadata;

void getMetadata(const char* filename, Metadata* metadata) {
    // code to extract metadata goes here
    metadata->artist = "Unknown";
    metadata->album = "Unknown";
    metadata->genre = "Unknown";
    metadata->year = 0;
    printf("Metadata extracted from file %s:\n", filename);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Genre: %s\n", metadata->genre);
    printf("Year: %d\n", metadata->year);
}

int main() {
    printf("C Metadata Extractor\n");
    printf("====================\n");
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    Metadata metadata;
    getMetadata(filename, &metadata);
    return 0;
}