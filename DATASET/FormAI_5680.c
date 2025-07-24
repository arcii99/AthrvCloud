//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Check if the file name is provided
    if (argc < 2) {
        printf("Error: File name not provided\n");
        exit(EXIT_FAILURE);
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Read the metadata
    char buffer[1024];
    int lines = 0;
    int words = 0;
    int characters = 0;
    while (fgets(buffer, 1024, fp)) {
        lines++;
        characters += strlen(buffer);
        int i;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t') {
                words++;
            }
        }
    }

    // Close the file
    fclose(fp);

    // Print the metadata
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}