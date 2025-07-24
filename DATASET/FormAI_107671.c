//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Please provide a file name.\n");
        return 1;
    }
    FILE *fp;
    char ch;
    unsigned long word_count = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s.\n", argv[1]);
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch) || ch == '\'' || ch == '-') {
            continue;
        }
        word_count++;
    }
    printf("There are %lu words in the file %s.\n", word_count, argv[1]);
    fclose(fp);
    return 0;
}