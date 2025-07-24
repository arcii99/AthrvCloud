//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int numWords = 0, numChars = 0;
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Unable to open %s\n", argv[1]);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) {
            numWords++;
        } else {
            numChars++;
        }
    }
    fclose(fp);
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
    return 0;
}