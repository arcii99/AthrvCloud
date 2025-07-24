//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a basic struct to hold metadata information
typedef struct Metadata {
    char* title;
    char* artist;
    char* album;
    int release_year;
} Metadata;

// function to extract metadata from file path
Metadata extractMetadata(char* path) {
    // open file stream
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("ERROR: Could not open file at path %s\n", path);
        exit(1);
    }

    // initialize empty metadata struct
    Metadata metadata;
    metadata.title = NULL;
    metadata.artist = NULL;
    metadata.album = NULL;
    metadata.release_year = 0;

    // read file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // check each line for metadata tags
        if (strstr(line, "Title: ")) {
            metadata.title = strdup(line + 7);
            metadata.title[strcspn(metadata.title, "\n")] = 0; // remove new line characters
        } else if (strstr(line, "Artist: ")) {
            metadata.artist = strdup(line + 8);
            metadata.artist[strcspn(metadata.artist, "\n")] = 0;
        } else if (strstr(line, "Album: ")) {
            metadata.album = strdup(line + 7);
            metadata.album[strcspn(metadata.album, "\n")] = 0;
        } else if (strstr(line, "Release Year: ")) {
            metadata.release_year = atoi(line + 14);
        }
    }

    // close file stream
    fclose(file);

    // return extracted metadata struct
    return metadata;
}

int main(int argc, char** argv) {
    // check command line arguments
    if (argc < 2) {
        printf("ERROR: Must provide file path as command line argument\n");
        return 1;
    }

    // call metadata extraction function
    Metadata metadata = extractMetadata(argv[1]);

    // print extracted metadata
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Release Year: %d\n", metadata.release_year);

    // free dynamically allocated memory in metadata struct
    free(metadata.title);
    free(metadata.artist);
    free(metadata.album);

    return 0;
}