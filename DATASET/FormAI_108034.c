//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <string.h>

char album[100], artist[100], genre[100], year[5], track[5];

void getMetadata(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Album:", 6) == 0) {
            strtok(line, ":");
            strcpy(album, strtok(NULL, ""));
            album[strcspn(album, "\n")] = 0;
        }

        if (strncmp(line, "Artist:", 7) == 0) {
            strtok(line, ":");
            strcpy(artist, strtok(NULL, ""));
            artist[strcspn(artist, "\n")] = 0;
        }

        if (strncmp(line, "Genre:", 6) == 0) {
            strtok(line, ":");
            strcpy(genre, strtok(NULL, ""));
            genre[strcspn(genre, "\n")] = 0;
        }

        if (strncmp(line, "Year:", 5) == 0) {
            strtok(line, ":");
            strcpy(year, strtok(NULL, ""));
            year[strcspn(year, "\n")] = 0;
        }

        if (strncmp(line, "Track:", 6) == 0) {
            strtok(line, ":");
            strcpy(track, strtok(NULL, ""));
            track[strcspn(track, "\n")] = 0;
        }
    }

    fclose(file);

    printf("Metadata for %s:\n", filename);
    printf("Album: %s\n", album);
    printf("Artist: %s\n", artist);
    printf("Genre: %s\n", genre);
    printf("Year: %s\n", year);
    printf("Track: %s\n", track);
}

int main() {
    getMetadata("my_song.mp3");
    return 0;
}