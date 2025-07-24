//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* artist;
    char* album;
    char* title;
    int year;
} Metadata;

// Function to extract metadata from a given file path
Metadata extract_metadata(char* filepath) {
    // Let's assume that the metadata is stored in a text file with the same name and path as the music file
    char* metadata_path = malloc(sizeof(char) * (strlen(filepath) + 5));
    strcpy(metadata_path, filepath);
    strcat(metadata_path, ".txt");

    // Open the metadata file
    FILE* metadata_file = fopen(metadata_path, "r");

    // If the file does not exist, return an empty metadata struct
    if (metadata_file == NULL) {
        printf("No metadata found for '%s'\n", filepath);
        Metadata empty_metadata = {"", "", "", 0};
        return empty_metadata;
    }

    // Read in the metadata
    char line[100];
    Metadata metadata;
    while (fgets(line, sizeof(line), metadata_file) != NULL) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, "\n");

        if (strcmp(key, "Artist") == 0) {
            metadata.artist = malloc(sizeof(char) * strlen(value) + 1);
            strcpy(metadata.artist, value);
        } else if (strcmp(key, "Album") == 0) {
            metadata.album = malloc(sizeof(char) * strlen(value) + 1);
            strcpy(metadata.album, value);
        } else if (strcmp(key, "Title") == 0) {
            metadata.title = malloc(sizeof(char) * strlen(value) + 1);
            strcpy(metadata.title, value);
        } else if (strcmp(key, "Year") == 0) {
            metadata.year = atoi(value);
        } else {
            printf("Invalid metadata key: '%s'\n", key);
        }
    }

    // Close the metadata file
    fclose(metadata_file);

    return metadata;
}

int main() {
    // Example usage
    char* filepath = "music/beatles/blackbird.mp3";

    Metadata metadata = extract_metadata(filepath);

    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Title: %s\n", metadata.title);
    printf("Year: %d\n", metadata.year);

    return 0;
}