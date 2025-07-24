//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

int main(int argc, char *argv[]) {
    int word_count = 0, char_count = 0, line_count = 0;
    char current_word[MAX_WORD_LEN + 1] = {0};
    int word_len = 0;
    int c;

    if (argc != 2) {
        printf("Usage: word_count input_file\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    while ((c = fgetc(input_file)) != EOF) {
        char_count++;
        if (c == '\n') {
            line_count++;
        }
        if (isspace(c)) {
            if (word_len > 0) {
                current_word[word_len] = '\0';
                printf("%s ", current_word);
                word_count++;
                word_len = 0;
            }
        } else {
            if (word_len < MAX_WORD_LEN) {
                current_word[word_len++] = c;
            }
        }
    }

    if (word_len > 0) {
        current_word[word_len] = '\0';
        printf("%s ", current_word);
        word_count++;
    }

    fclose(input_file);

    printf("\n");
    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", char_count);
    printf("Line count: %d\n", line_count);

    return 0;
}