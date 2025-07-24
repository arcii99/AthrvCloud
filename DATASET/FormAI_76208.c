//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    char *word;
    int word_count = 0;
    int line_count = 0;
    char c;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: Failed to open file %s\n", filename);
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            word_count++;
        } else if (c == '\n') {
            line_count++;
        }
    }

    printf("File \"%s\" has %d words and %d lines.\n", filename, word_count, line_count);

    fclose(fp);

    return 0;
}