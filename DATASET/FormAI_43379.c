//FormAI DATASET v1.0 Category: Word Count Tool ; Style: protected
// Unique C Word Count Tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No input file specified.\n");
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Could not open file \"%s\".\n", argv[1]);
        return EXIT_FAILURE;
    }

    int word_count = 0;
    int char_count = 0;
    int in_word = 0;
    char word[MAX_WORD_LENGTH + 1];
    memset(word, '\0', MAX_WORD_LENGTH + 1);

    int c;
    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            if (!in_word) {
                in_word = 1;
                char_count = 0;
            }
            if (char_count < MAX_WORD_LENGTH) {
                word[char_count++] = c;
            }
        } else {
            if (in_word) {
                in_word = 0;
                word_count++;
                printf("%s\n", word);
            }
        }
    }

    if (in_word) {
        word_count++;
        printf("%s\n", word);
    }

    printf("Word count: %d\n", word_count);

    fclose(input_file);
    return 0;
}