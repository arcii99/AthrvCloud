//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declare the maximum size of the metadata */
#define MAX_METADATA_SIZE 100

/* Declare a structure to store the extracted metadata */
typedef struct {
    char artist[MAX_METADATA_SIZE];
    char title[MAX_METADATA_SIZE];
    char album[MAX_METADATA_SIZE];
    char year[MAX_METADATA_SIZE];
} metadata_t;

/* Declare a function to extract metadata from a given file */
metadata_t extract_metadata(const char* filename) {
    /* Open the file for reading */
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: failed to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Declare a buffer to temporarily store each line of the file */
    char buffer[MAX_METADATA_SIZE];

    /* Declare a metadata struct to store the extracted metadata */
    metadata_t metadata;
    
    /* Initialize the metadata fields to empty strings */
    memset(metadata.artist, 0, MAX_METADATA_SIZE);
    memset(metadata.title, 0, MAX_METADATA_SIZE);
    memset(metadata.album, 0, MAX_METADATA_SIZE);
    memset(metadata.year, 0, MAX_METADATA_SIZE);

    /* Iterate through each line of the file */
    while (fgets(buffer, MAX_METADATA_SIZE, fp) != NULL) {
        /* Remove the newline character from the end of the line */
        buffer[strcspn(buffer, "\n")] = '\0';

        /* Extract the artist name from the line if it contains 'artist' */
        if (strstr(buffer, "artist") != NULL) {
            char* value = strstr(buffer, "=");
            strncpy(metadata.artist, value + 1, MAX_METADATA_SIZE - 1);
        }

        /* Extract the title from the line if it contains 'title' */
        if (strstr(buffer, "title") != NULL) {
            char* value = strstr(buffer, "=");
            strncpy(metadata.title, value + 1, MAX_METADATA_SIZE - 1);
        }

        /* Extract the album name from the line if it contains 'album' */
        if (strstr(buffer, "album") != NULL) {
            char* value = strstr(buffer, "=");
            strncpy(metadata.album, value + 1, MAX_METADATA_SIZE - 1);
        }

        /* Extract the year from the line if it contains 'year' */
        if (strstr(buffer, "year") != NULL) {
            char* value = strstr(buffer, "=");
            strncpy(metadata.year, value + 1, MAX_METADATA_SIZE - 1);
        }
    }

    /* Close the file */
    fclose(fp);

    /* Return the extracted metadata */
    return metadata;
}

/* Example usage of the metadata extractor */
int main() {
    /* Call the metadata extractor function on the given file */
    metadata_t metadata = extract_metadata("example.txt");

    /* Print the extracted metadata */
    printf("Artist: %s\n", metadata.artist);
    printf("Title: %s\n", metadata.title);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);

    /* Exit the program successfully */
    return EXIT_SUCCESS;
}