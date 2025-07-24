//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    int year;
} Song;

void extractMetadata(Song *song, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file, please provide a valid filename!");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // We're going to parse each line of the file that's being read
        char *token = strtok(line, ":");
        if (strcmp(token, "Title") == 0) {
            // Get the title
            token = strtok(NULL, ":");
            strncpy(song->title, token, sizeof(song->title));
        } else if (strcmp(token, "Artist") == 0) {
            // Get the artist
            token = strtok(NULL, ":");
            strncpy(song->artist, token, sizeof(song->artist));
        } else if (strcmp(token, "Year") == 0) {
            // Get the year
            token = strtok(NULL, ":");
            song->year = atoi(token);
        }
    }
    fclose(file);
}

int main() {
    Song mySong;
    char *filename = "mySong.txt";
    extractMetadata(&mySong, filename);
    printf("Successfully extracted the following metadata from %s:\n", filename);
    printf("Title: %s\n", mySong.title);
    printf("Artist: %s\n", mySong.artist);
    printf("Year: %d\n", mySong.year);
    printf("Now go sing your little heart out!\n");
    return 0;
}