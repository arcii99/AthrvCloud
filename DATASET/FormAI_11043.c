//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function: extract_metadata
// Parameters: char *filename
// Returns: void
// Description: Extracts metadata from a C file and prints it to the console
void extract_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    char line[MAX_STRING_LENGTH];
    int num_lines = 0, num_comments = 0;
    while (fgets(line, MAX_STRING_LENGTH, fp) != NULL) {
        num_lines++;
        if (strstr(line, "//") || strstr(line, "/*")) {
            num_comments++;
        }
    }

    printf("File name: %s\n", filename);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of comments: %d\n", num_comments);

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    extract_metadata(filename);

    return 0;
}