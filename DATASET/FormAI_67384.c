//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// metadata structure definition
typedef struct metadata {
    char* artist;
    char* title;
    char* album;
} Metadata;

// function to extract metadata from a given file path
Metadata extract_metadata(char* file_path) {
    Metadata metadata;
    metadata.artist = NULL;
    metadata.title = NULL;
    metadata.album = NULL;
    bool artist_found = false;
    bool title_found = false;
    bool album_found = false;

    // open file in read mode
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    // read file line by line
    char buffer[100];
    while (fgets(buffer, 100, file)) {
        // check if line contains artist metadata
        if (strstr(buffer, "Artist:")) {
            metadata.artist = strdup(buffer + 7);  // set artist metadata
            artist_found = true;
        }
        // check if line contains title metadata
        if (strstr(buffer, "Title:")) {
            metadata.title = strdup(buffer + 6);  // set title metadata
            title_found = true;
        }
        // check if line contains album metadata
        if (strstr(buffer, "Album:")) {
            metadata.album = strdup(buffer + 6);  // set album metadata
            album_found = true;
        }
        // break loop if all metadata found
        if (artist_found && title_found && album_found) {
            break;
        }
    }

    // close file
    fclose(file);

    // return metadata structure
    return metadata;
}

int main() {
    // test metadata extraction
    Metadata metadata = extract_metadata("example_song.txt");

    // print extracted metadata
    printf("Artist: %s", metadata.artist);
    printf("Title: %s", metadata.title);
    printf("Album: %s", metadata.album);

    // free allocated memory
    free(metadata.artist);
    free(metadata.title);
    free(metadata.album);

    return 0;
}