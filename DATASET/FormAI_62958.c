//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <string.h>

// Struct to store metadata information
typedef struct {
    char artist[100];
    char album[100];
    int year;
    char genre[100];
} metadata;

// Function to extract metadata
metadata extractMetadata(char* file) {
    metadata data;
    // Let's assume the file has the metadata in the format "Artist:Album:Year:Genre"
    char* token = strtok(file, ":");
    strcpy(data.artist, token);
    token = strtok(NULL, ":");
    strcpy(data.album, token);
    token = strtok(NULL, ":");
    data.year = atoi(token);
    token = strtok(NULL, ":");
    strcpy(data.genre, token);
    return data;
}

int main() {
    // Let's assume we have a file called "song1.wav" with the metadata "Queen:A Night at the Opera:1975:Rock"
    char* file = "Queen:A Night at the Opera:1975:Rock";
    metadata data = extractMetadata(file);

    // Let's print out the extracted metadata
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Year: %d\n", data.year);
    printf("Genre: %s\n", data.genre);

    return 0;
}