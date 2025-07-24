//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 20 // maximum length of a word in characters

int main() {
    int c; // character from input
    char word[MAX_WORD_LENGTH + 1]; // current word
    int word_length = 0; // length of current word
    int num_words = 0; // number of words
    int num_chars = 0; // number of characters
    int num_lines = 1; // number of lines (start at 1 for the first line)

    printf("Enter text (press Ctrl-D to end):\n");

    while ((c = getchar()) != EOF) {
        if (isspace(c)) { // space, tab, newline
            if (word_length > 0) { // word complete
                word[word_length] = '\0'; // add null terminator
                printf("word%d: %s\n", num_words + 1, word);
                num_words++; // increment word count
                word_length = 0; // reset word length
            }
            if (c == '\n') { // newline
                num_lines++; // increment line count
            }
        } else if (isalpha(c)) { // letter
            if (word_length < MAX_WORD_LENGTH) { // word not too long
                word[word_length] = c; // add letter to word
                word_length++; // increment word length
            }
        }
        num_chars++; // increment character count
    }

    printf("Statistics:\n");
    printf("  %d words\n", num_words);
    printf("  %d characters\n", num_chars);
    printf("  %d lines\n", num_lines);

    return 0;
}