//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
};

int main() {
    struct Metadata song;
    char input[100];
    char *token;

    printf("Enter a song title, artist, year, and genre (separated by commas): ");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, ",");
    strcpy(song.title, token);

    token = strtok(NULL, ",");
    strcpy(song.artist, token);

    token = strtok(NULL, ",");
    song.year = atoi(token);

    token = strtok(NULL, ",");
    strcpy(song.genre, token);

    printf("\nTitle: %s", song.title);
    printf("\nArtist: %s", song.artist);
    printf("\nYear: %d", song.year);
    printf("\nGenre: %s", song.genre);

    return 0;
}