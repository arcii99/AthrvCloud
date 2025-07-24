//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for metadata fields
#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 50
#define MAX_GENRE_LEN 20

// Define struct for storing metadata
typedef struct metadata {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
} metadata_t;

// Function to extract metadata from a file
metadata_t extract_metadata(const char* filename) {
    // Declare metadata struct and initialize variables to empty strings
    metadata_t data;
    memset(&data, 0, sizeof(data));

    // Open file for reading
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    // Loop through lines in file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Check for metadata fields in line and store in struct
        if (strstr(line, "Title:")) {
            strncpy(data.title, line + strlen("Title:"), MAX_TITLE_LEN);
            data.title[strcspn(data.title, "\n")] = '\0'; // Remove newline character
        }
        else if (strstr(line, "Artist:")) {
            strncpy(data.artist, line + strlen("Artist:"), MAX_ARTIST_LEN);
            data.artist[strcspn(data.artist, "\n")] = '\0';
        }
        else if (strstr(line, "Album:")) {
            strncpy(data.album, line + strlen("Album:"), MAX_ALBUM_LEN);
            data.album[strcspn(data.album, "\n")] = '\0';
        }
        else if (strstr(line, "Genre:")) {
            strncpy(data.genre, line + strlen("Genre:"), MAX_GENRE_LEN);
            data.genre[strcspn(data.genre, "\n")] = '\0';
        }
    }

    // Close file
    fclose(fp);

    // Return metadata struct
    return data;
}

// Example usage
int main() {
    // Extract metadata from file
    metadata_t data = extract_metadata("example_song.txt");

    // Print metadata
    printf("Title: %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Genre: %s\n", data.genre);

    return 0;
}