//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return -1;
    }

    FILE *fp;
    char buffer[BUFFER_SIZE];
    int line_number = 0;
    int metadata_count = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return -1;
    }

    printf("Metadata found in file:\n");

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        line_number++;

        if (buffer[0] == '#' && buffer[1] == ' ') {
            metadata_count++;
            printf("Metadata line #%d: %s", line_number, buffer);
        }
    }

    printf("Total metadata lines found: %d\n", metadata_count);
    fclose(fp);

    return 0;
}