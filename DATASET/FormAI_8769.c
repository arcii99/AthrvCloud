//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length for a metadata string */
#define MAX_METADATA_LENGTH 256

/* Define a struct to hold the metadata */
struct metadata {
    char title[MAX_METADATA_LENGTH];
    char artist[MAX_METADATA_LENGTH];
    char album[MAX_METADATA_LENGTH];
    char year[MAX_METADATA_LENGTH];
};

/* Define a function to extract the metadata from a file */
struct metadata extract_metadata(char *filename) {
    struct metadata meta;
    char buffer[MAX_METADATA_LENGTH];
    FILE *fp;

    /* Open the file for reading */
    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    /* Read the title metadata */
    fseek(fp, 0, SEEK_SET);
    fread(buffer, MAX_METADATA_LENGTH, 1, fp);
    strncpy(meta.title, buffer, MAX_METADATA_LENGTH);

    /* Read the artist metadata */
    fseek(fp, MAX_METADATA_LENGTH, SEEK_SET);
    fread(buffer, MAX_METADATA_LENGTH, 1, fp);
    strncpy(meta.artist, buffer, MAX_METADATA_LENGTH);

    /* Read the album metadata */
    fseek(fp, 2 * MAX_METADATA_LENGTH, SEEK_SET);
    fread(buffer, MAX_METADATA_LENGTH, 1, fp);
    strncpy(meta.album, buffer, MAX_METADATA_LENGTH);

    /* Read the year metadata */
    fseek(fp, 3 * MAX_METADATA_LENGTH, SEEK_SET);
    fread(buffer, MAX_METADATA_LENGTH, 1, fp);
    strncpy(meta.year, buffer, MAX_METADATA_LENGTH);

    /* Close the file */
    fclose(fp);

    /* Return the metadata */
    return meta;
}

int main(int argc, char *argv[]) {
    /* Check that the correct number of arguments have been passed */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Extract the metadata from the file */
    struct metadata meta = extract_metadata(argv[1]);

    /* Print the metadata */
    printf("Title: %s\n", meta.title);
    printf("Artist: %s\n", meta.artist);
    printf("Album: %s\n", meta.album);
    printf("Year: %s\n", meta.year);

    return 0;
}