//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // maximum number of words to count
#define MAX_LEN 100 // maximum length of a word
#define DELIMITERS " .,!?" // characters to separate words

struct Word {
    char text[MAX_LEN];
    int count;
};

void str_tolower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_delimiter(char c) {
    const char *delimiters = DELIMITERS;
    while (*delimiters) {
        if (*delimiters == c) {
            return 1;
        }
        delimiters++;
    }
    return 0;
}

void count_words(char *text, struct Word *word_list, int *num_words) {
    char *word = strtok(text, DELIMITERS);
    while (word != NULL && *num_words < MAX_WORDS) {
        str_tolower(word);
        int found = 0;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(word_list[i].text, word) == 0) {
                word_list[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(word_list[*num_words].text, word, MAX_LEN);
            word_list[*num_words].count = 1;
            (*num_words)++;
        }
        word = strtok(NULL, DELIMITERS);
    }
}

int main() {
    struct Word word_list[MAX_WORDS];
    int num_words = 0;
    char *text = "The quick brown fox jumps over the lazy dog.";
    count_words(text, word_list, &num_words);
    printf("Word frequency count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].text, word_list[i].count);
    }
    return 0;
}