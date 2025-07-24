//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char* argv[]) {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    char* word;
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        word = strtok(line, " \t\n");
        while (word != NULL) {
            num_words++;
            word = strtok(NULL, " \t\n");
        }
    }

    printf("Number of words in file %s: %d\n", argv[1], num_words);

    fclose(fp);
    return 0;
}