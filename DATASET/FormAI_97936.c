//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
} metadata;

void extract_metadata(char *filename, metadata *data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: cannot open file %s.\n", filename);
        exit(1);
    }

    char line[256];
    while (fgets(line, 256, file)) {
        if (strncmp(line, "Title:", 6) == 0) {
            data->title = strdup(line + 7);
        } else if (strncmp(line, "Artist:", 7) == 0) {
            data->artist = strdup(line + 8);
        } else if (strncmp(line, "Album:", 6) == 0) {
            data->album = strdup(line + 7);
        } else if (strncmp(line, "Year:", 5) == 0) {
            data->year = atoi(line + 6);
        }
    }

    fclose(file);
}

int main() {
    metadata data = {NULL, NULL, NULL, 0};

    extract_metadata("song.mp3", &data);

    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\n",
        data.title ? data.title : "Unknown",
        data.artist ? data.artist : "Unknown",
        data.album ? data.album : "Unknown",
        data.year);

    free(data.title);
    free(data.artist);
    free(data.album);

    return 0;
}