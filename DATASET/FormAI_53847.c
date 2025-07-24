//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum length of line supported
#define MAX_LINE_LENGTH 1024

// function to extract metadata from a given file
void extract_metadata(char* filename) {
    // open the file in read mode
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    // define variables to store metadata
    char* title = NULL;
    char* artist = NULL;
    char* album = NULL;

    // loop through lines in the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // check if the line contains metadata information
        if (strstr(line, "Title:") != NULL) {
            title = strdup(line + strlen("Title:"));
            title[strcspn(title, "\n\r")] = 0; // remove newline characters
        } else if (strstr(line, "Artist:") != NULL) {
            artist = strdup(line + strlen("Artist:"));
            artist[strcspn(artist, "\n\r")] = 0; // remove newline characters
        } else if (strstr(line, "Album:") != NULL) {
            album = strdup(line + strlen("Album:"));
            album[strcspn(album, "\n\r")] = 0; // remove newline characters
        }
    }

    // close the file
    fclose(fp);

    // print out the extracted metadata
    printf("Metadata for file '%s':\n", filename);
    printf("Title: %s\n", (title != NULL) ? title : "N/A");
    printf("Artist: %s\n", (artist != NULL) ? artist : "N/A");
    printf("Album: %s\n", (album != NULL) ? album : "N/A");

    // free memory used by metadata strings
    free(title);
    free(artist);
    free(album);
}

int main() {
    // test the metadata extractor on a sample file
    extract_metadata("sample_music_file.txt");

    return 0;
}