//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold metadata */
typedef struct {
    char artist[50];
    char album[50];
    char year[5];
    char genre[20];
} metadata;

/* Function to extract metadata from file */
metadata extract_metadata(char* filename) {
    metadata m;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    char line[500];
    while (fgets(line, 500, fp) != NULL) {
        /* Check for artist */
        if (strstr(line, "Artist: ")) {
            char artist[50];
            sscanf(line, "%*s %[^\n]", artist);
            strcpy(m.artist, artist);
        }
        /* Check for album */
        if (strstr(line, "Album: ")) {
            char album[50];
            sscanf(line, "%*s %[^\n]", album);
            strcpy(m.album, album);
        }
        /* Check for year */
        if (strstr(line, "Year: ")) {
            char year[5];
            sscanf(line, "%*s %[^\n]", year);
            strcpy(m.year, year);
        }
        /* Check for genre */
        if (strstr(line, "Genre: ")) {
            char genre[20];
            sscanf(line, "%*s %[^\n]", genre);
            strcpy(m.genre, genre);
        }
    }
    fclose(fp);
    return m;
}

int main() {
    metadata m = extract_metadata("example.mp3");
    printf("Artist: %s\n", m.artist);
    printf("Album: %s\n", m.album);
    printf("Year: %s\n", m.year);
    printf("Genre: %s\n", m.genre);
    return 0;
}