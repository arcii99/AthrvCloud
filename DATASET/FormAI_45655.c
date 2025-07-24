//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[50];
    char ch;
    int words = 0, lines = 0, characters = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
            words++;    // newline also counts as a word separator
        } else if (ch == ' ' || ch == '\t') {
            words++;
        }
    }

    fclose(fp);

    printf("Number of characters: %d\n", characters);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}