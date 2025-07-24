//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void extract_metadata(char* filename, char* artist, char* album, char* year, char* genre) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, file)) {
        if(strstr(line, "ARTIST")) {
            strcpy(artist, strtok(line, ":"));
            artist[strlen(artist) - 1] = '\0';
        }
        else if(strstr(line, "ALBUM")) {
            strcpy(album, strtok(line, ":"));
            album[strlen(album) - 1] = '\0';
        }
        else if(strstr(line, "YEAR")) {
            strcpy(year, strtok(line, ":"));
            year[strlen(year) - 1] = '\0';
        }
        else if(strstr(line, "GENRE")) {
            strcpy(genre, strtok(line, ":"));
            genre[strlen(genre) - 1] = '\0';
        }
    }
    fclose(file);
}

int main() {
    char filename[] = "song.mp3";
    char artist[50] = "";
    char album[50] = "";
    char year[10] = "";
    char genre[20] = "";

    extract_metadata(filename, artist, album, year, genre);

    printf("Artist: %s\n", artist);
    printf("Album: %s\n", album);
    printf("Year: %s\n", year);
    printf("Genre: %s\n", genre);

    return 0;
}