//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct metadata {
    char title[MAX_LEN];
    char artist[MAX_LEN];
    char album[MAX_LEN];
    int year;
} Metadata;

void extract_metadata(char *filename, Metadata *meta) {
    FILE *fp;
    char line[MAX_LEN];
    char *token;

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        /* Check for title */
        if (strstr(line, "Title:")) {
            token = strtok(line, ":");
            token = strtok(NULL, ":");
            strncpy(meta->title, token, sizeof(meta->title));
        }

        /* Check for artist */
        if (strstr(line, "Artist:")) {
            token = strtok(line, ":");
            token = strtok(NULL, ":");
            strncpy(meta->artist, token, sizeof(meta->artist));
        }

        /* Check for album */
        if (strstr(line, "Album:")) {
            token = strtok(line, ":");
            token = strtok(NULL, ":");
            strncpy(meta->album, token, sizeof(meta->album));
        }

        /* Check for year */
        if (strstr(line, "Year:")) {
            token = strtok(line, ":");
            token = strtok(NULL, ":");
            meta->year = atoi(token);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    Metadata meta;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    extract_metadata(argv[1], &meta);

    printf("Title: %s\n", meta.title);
    printf("Artist: %s\n", meta.artist);
    printf("Album: %s\n", meta.album);
    printf("Year: %d\n", meta.year);

    return 0;
}