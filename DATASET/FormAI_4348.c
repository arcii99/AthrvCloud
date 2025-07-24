//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

int count_words(FILE* file) {
    char c, last_c = '\n';
    int word_count = 0, in_word = 0;

    while ((c = getc(file)) != EOF) {
        if (!isspace(c)) {
            in_word = 1;
        }
        if (in_word && (isspace(c) || c == EOF || c == '\n')) {
            word_count++;
            in_word = 0;
        }
        last_c = c;
    }

    // Check if last character is not '\n'
    if (!isspace(last_c)) {
        word_count++;
    }

    return word_count;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: wordcount [file]\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    int word_count = count_words(file);
    printf("Word count: %d\n", word_count);

    fclose(file);
    return 0;
}