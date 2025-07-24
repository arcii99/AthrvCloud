//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Function to extract metadata from a file
 * @param filename the name of the file to extract metadata from
 */
void extract_metadata(char *filename) {
    FILE *fp;
    char metadata[100];
    int filesize, num_lines = 0, num_words = 0, num_chars = 0;

    fp = fopen(filename, "r"); // open file for reading
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // get filesize
    fseek(fp, 0, SEEK_END); // move file pointer to end of file
    filesize = ftell(fp); // get current file pointer position (since it's at the end, this is the filesize)
    fseek(fp, 0, SEEK_SET); // move file pointer back to beginning

    // count number of lines, words, and characters in file
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') num_lines++;
        if (c == ' ' || c == '\n' || c == '\t') num_words++;
        num_chars++;
    }
    num_words++; // add one to num_words since the last word will not have a space or newline after it

    // prepare metadata string
    sprintf(metadata, "Filename: %s, Filesize: %d bytes, Number of lines: %d, Number of words: %d, Number of characters: %d",
            filename, filesize, num_lines, num_words, num_chars);

    // print metadata
    printf("%s\n", metadata);

    fclose(fp); // close file
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    extract_metadata(argv[1]);

    return EXIT_SUCCESS;
}