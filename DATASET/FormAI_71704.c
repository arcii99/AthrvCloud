//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Unable to open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int i;
    while (fscanf(file, "%s", word) == 1) {
        for (i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        if (strcmp(word, "love") == 0 || strcmp(word, "romance") == 0 || strcmp(word, "affection") == 0) {
            word_count++;
        }
    }

    printf("The words 'love', 'romance', and 'affection' appeared %d times in %s\n", word_count, filename);
    return EXIT_SUCCESS;
}