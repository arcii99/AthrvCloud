//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int get_word_count(char *line);

int main() {
    char line[MAX_LINE_LENGTH];
    int word_count;

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        word_count = get_word_count(line);
        printf("The number of words in the line is: %d\n", word_count);
    }

    return 0;
}

int get_word_count(char *line) {
    int i, count, is_on_word, line_length;

    count = 0;
    is_on_word = 0;
    line_length = strlen(line);

    for (i = 0; i < line_length; i++) {
        if (!is_on_word && (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')) {
            // The first character of a word is found
            is_on_word = 1;
            count++;
        } else if (is_on_word && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')) {
            // Skip consecutive white spaces
            is_on_word = 0;
        }
    }

    return count;
}