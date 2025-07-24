//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example of extracting metadata information from a file */

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char artist[100];
    char album[100];
    char title[100];
    Date date;
} Metadata;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        printf("Error: Failed to open file %s\n", argv[1]);
        return 1;
    }

    Metadata md;
    memset(&md, 0, sizeof(md));

    fseek(f, -sizeof(md), SEEK_END);
    fread(&md, sizeof(md), 1, f);

    printf("Artist: %s\n", md.artist);
    printf("Album: %s\n", md.album);
    printf("Title: %s\n", md.title);
    printf("Date: %04d-%02d-%02d\n", md.date.year, md.date.month, md.date.day);

    fclose(f);
    return 0;
}