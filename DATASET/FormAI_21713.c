//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold metadata information
typedef struct {
    char artist[50];
    char album[50];
    char title[50];
    int year;
} Metadata;

// Function to extract metadata
Metadata* extract_metadata(char* file) {
    Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));
    // Code to extract metadata goes here
    // ...
    // Assume metadata is extracted with the following values
    strcpy(metadata->artist, "Pink Floyd");
    strcpy(metadata->album, "The Wall");
    strcpy(metadata->title, "Comfortably Numb");
    metadata->year = 1979;
    return metadata;
}

int main() {
    char* file = "ComfortablyNumb.mp3";
    Metadata* metadata = extract_metadata(file);
    printf("Artist: %s\nAlbum: %s\nTitle: %s\nYear: %d\n", metadata->artist, metadata->album, metadata->title, metadata->year);
    free(metadata);
    return 0;
}