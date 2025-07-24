//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract_metadata(char* file_path) {
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("ERROR: Could not open file \"%s\".\n", file_path);
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fp) != -1) {
        if (strncmp(line, "TITLE", 5) == 0) {
            char* title = strchr(line, ' ');
            printf("Title: %s\n", title);
        } else if (strncmp(line, "ARTIST", 6) == 0) {
            char* artist = strchr(line, ' ');
            printf("Artist: %s\n", artist);
        } else if (strncmp(line, "ALBUM", 5) == 0) {
            char* album = strchr(line, ' ');
            printf("Album: %s\n", album);
        } else if (strncmp(line, "YEAR", 4) == 0) {
            char* year = strchr(line, ' ');
            printf("Year: %s\n", year);
        } else if (strncmp(line, "GENRE", 5) == 0) {
            char* genre = strchr(line, ' ');
            printf("Genre: %s\n", genre);
        }
    }

    if (line)
        free(line);

    fclose(fp);
}

int main(void) {
    char* file_path = "example.mp3";
    extract_metadata(file_path);

    return 0;
}