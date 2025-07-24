//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    char title[50];
    char artist[50];
    char album[50];
    int track;
    int year;
} Metadata;

// Function to extract metadata from file
Metadata extract_metadata(char *filename) {
    FILE *fp;
    char buffer[1024];
    char *token;
    Metadata metadata;

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check for errors while opening file
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(buffer, 1024, fp)) {
        // Extract title
        if (strstr(buffer, "title=")) {
            token = strtok(buffer, "=");
            strcpy(metadata.title, strtok(NULL, "\n"));
        }
        // Extract artist
        if (strstr(buffer, "artist=")) {
            token = strtok(buffer, "=");
            strcpy(metadata.artist, strtok(NULL, "\n"));
        }
        // Extract album
        if (strstr(buffer, "album=")) {
            token = strtok(buffer, "=");
            strcpy(metadata.album, strtok(NULL, "\n"));
        }
        // Extract track number
        if (strstr(buffer, "track=")) {
            token = strtok(buffer, "=");
            metadata.track = atoi(strtok(NULL, "\n"));
        }
        // Extract year
        if (strstr(buffer, "year=")) {
            token = strtok(buffer, "=");
            metadata.year = atoi(strtok(NULL, "\n"));
        }
    }

    // Close file
    fclose(fp);

    // Return metadata extracted from file
    return metadata;
}

int main() {
    // Declare metadata variable
    Metadata metadata;

    // Call extract_metadata function to extract metadata from file
    metadata = extract_metadata("my_heart.txt");

    // Print metadata
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Track number: %d\n", metadata.track);
    printf("Year: %d\n", metadata.year);

    return 0;
}