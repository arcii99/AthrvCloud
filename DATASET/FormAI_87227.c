//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata {
    char *title;
    char *artist;
    char *album;
    char *genre;
};

void extract_metadata(char *file_name, struct metadata *data) {
    // code to extract metadata from file
    // and populate data struct with extracted data
    data->title = "My Song";
    data->artist = "John Doe";
    data->album = "My Album";
    data->genre = "Rock";
}

int main() {
    char *file_name = "myfile.mp3";
    struct metadata data;
    
    extract_metadata(file_name, &data);
    
    printf("Title: %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Genre: %s\n", data.genre);
    
    return 0;
}