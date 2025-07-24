//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *artist; 
    char *album; 
    int year;
} Song;

void extract_metadata(char *file_path, Song *song) {
    printf("Surprise, surprise! We're going to extract the metadata of %s.\n", file_path);
    
    // Let's pretend we're doing some really complex metadata extraction here
    song->name = "Cool Song";
    song->artist = "Awesome Artist";
    song->album = "Incredible Album";
    song->year = 2021;
    
    // Print out the extracted metadata
    printf("Song: %s\n", song->name);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n", song->year);
}

int main() {
    char *file_path = "path/to/file.mp3";
    Song *song = malloc(sizeof(Song));
    
    extract_metadata(file_path, song);
    
    free(song);
    
    return 0;
}