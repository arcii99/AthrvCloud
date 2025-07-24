//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
} SongMetadata;

void extractMetadata(char *filename, SongMetadata *metadata) {
    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char line[256];
        char *delimiter = " - ";

        fgets(line, sizeof(line), file);

        metadata->artist = strtok(line, delimiter);
        metadata->title = strtok(NULL, delimiter);

        fgets(line, sizeof(line), file);

        metadata->album = strtok(line, ":\n");
        metadata->year = atoi(strtok(NULL, ":\n"));

        fgets(line, sizeof(line), file);

        metadata->track = atoi(strtok(line, ":\n"));

        fclose(file);
    }
}

int main() {
    SongMetadata metadata;
    char *filename = "song.txt";

    extractMetadata(filename, &metadata);

    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\nTrack: %d\n", 
            metadata.title, metadata.artist, metadata.album, metadata.year, metadata.track);
    
    return 0;
}