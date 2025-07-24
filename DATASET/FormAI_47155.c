//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char title[50];
    int year;
    char artist[50];
    int duration;
} Metadata;

void extractMetadata(char *filename, Metadata *data) {
    FILE *fp;
    char line[100];

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), fp)) {
        if(strncmp(line, "Title=", 6) == 0) {
            char *title = strtok(line+6, "\n");
            strcpy(data->title, title);
        }

        if(strncmp(line, "Year=", 5) == 0) {
            char *strYear = strtok(line+5, "\n");
            data->year = atoi(strYear);
        }

        if(strncmp(line, "Artist=", 7) == 0) {
            char *artist = strtok(line+7, "\n");
            strcpy(data->artist, artist);
        }

        if(strncmp(line, "Duration=", 9) == 0) {
            char *strDuration = strtok(line+9, "\n");
            data->duration = atoi(strDuration);
        }
    }

    fclose(fp);
}

int main() {
    Metadata data;
    char filename[] = "song.txt";

    extractMetadata(filename, &data);

    printf("Extracted Metadata:\n");
    printf("Title: %s\n", data.title);
    printf("Year: %d\n", data.year);
    printf("Artist: %s\n", data.artist);
    printf("Duration: %d\n", data.duration);

    return 0;
}