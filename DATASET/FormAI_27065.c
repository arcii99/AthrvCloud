//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR: No file name provided.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("ERROR: Could not open file '%s'.\n", filename);
        return 1;
    }

    int num_chars = 0;
    int num_words = 0;
    int num_lines = 0;

    int in_word = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        num_chars++;

        if (isspace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                num_words++;
                in_word = 1;
            }
        }

        if (c == '\n') {
            num_lines++;
        }
    }

    fclose(fp);

    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);

    return 0;
}