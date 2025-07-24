//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Define metadata structure */
typedef struct {
    char title[BUFFER_SIZE];
    char artist[BUFFER_SIZE];
    char album[BUFFER_SIZE];
    char genre[BUFFER_SIZE];
    int year;
} Metadata;

/* Function to extract metadata */
Metadata extract_metadata(char *filename) {
    Metadata metadata;
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }
    char line[BUFFER_SIZE];
    while(fgets(line, sizeof(line), file)) {
        char *search = strstr(line, "Title: ");
        if(search != NULL) {
            strcpy(metadata.title, search + strlen("Title: "));
            continue;
        }
        search = strstr(line, "Artist: ");
        if(search != NULL) {
            strcpy(metadata.artist, search + strlen("Artist: "));
            continue;
        }
        search = strstr(line, "Album: ");
        if(search != NULL) {
            strcpy(metadata.album, search + strlen("Album: "));
            continue;
        }
        search = strstr(line, "Genre: ");
        if(search != NULL) {
            strcpy(metadata.genre, search + strlen("Genre: "));
            continue;
        }
        search = strstr(line, "Year: ");
        if(search != NULL) {
            metadata.year = atoi(search + strlen("Year: "));
            continue;
        }
    }
    fclose(file);
    return metadata;
}

/* Main function to test metadata extraction */
int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    Metadata metadata = extract_metadata(argv[1]);
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Genre: %s\n", metadata.genre);
    printf("Year: %d\n", metadata.year);
    return 0;
}