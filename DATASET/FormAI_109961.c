//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata {
    char title[100];
    char artist[100];
    char album[100];
    char year[10];
};

void extract_metadata(char *filename, struct metadata *md) {
    FILE *fp;
    char line[100];

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, "Title") != NULL) {
            strcpy(md->title, strtok(line, ":"));
        }
        else if(strstr(line, "Artist") != NULL) {
            strcpy(md->artist, strtok(line, ":"));
        }
        else if(strstr(line, "Album") != NULL) {
            strcpy(md->album, strtok(line, ":"));
        }
        else if(strstr(line, "Year") != NULL) {
            strcpy(md->year, strtok(line, ":"));
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    struct metadata md;

    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    extract_metadata(argv[1], &md);

    printf("Title: %s\n", md.title);
    printf("Artist: %s\n", md.artist);
    printf("Album: %s\n", md.album);
    printf("Year: %s\n", md.year);

    return 0;
}