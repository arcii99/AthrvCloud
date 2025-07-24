//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    char title[100];
    char author[50];
    int year;
    char genre[20];
} Metadata;

Metadata extract_metadata(char *filename);

int main(int argc, char *argv[]) {
    if(argc == 2) {
        Metadata metadata = extract_metadata(argv[1]);
        printf("Title: %s\n", metadata.title);
        printf("Author: %s\n", metadata.author);
        printf("Year: %d\n", metadata.year);
        printf("Genre: %s\n", metadata.genre);
    } else {
        printf("Usage: ./metadata_extractor filename\n");
    }
    return 0;
}

Metadata extract_metadata(char *filename) {
    Metadata metadata;
    memset(&metadata, 0, sizeof(metadata));
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return metadata;
    }
    char line[100];
    while(fgets(line, sizeof(line), file)) {
        if(strstr(line, "Title:") != NULL) {
            sscanf(line, "Title: %s", metadata.title);
        } else if(strstr(line, "Author:") != NULL) {
            sscanf(line, "Author: %s", metadata.author);
        } else if(strstr(line, "Year:") != NULL) {
            sscanf(line, "Year: %d", &metadata.year);
        } else if(strstr(line, "Genre:") != NULL) {
            sscanf(line, "Genre: %s", metadata.genre);
        }
    }
    fclose(file);
    return metadata;
}