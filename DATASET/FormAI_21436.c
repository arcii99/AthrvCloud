//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
// Here's a C program that processes text input and counts the number of occurrences of each word. 
// This program is inspired by the mathematician Ada Lovelace, who is considered to be the first computer programmer.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50

struct word_count {
    char word[WORD_LEN];
    int count;
};

void remove_punctuation(char *word) {
    char *src = word;
    char *dst = word;

    while (*src) {
        if (ispunct((unsigned char)*src)) {
            src++;
        } else if (src == dst) {
            src++;
            dst++;
        } else {
            *dst++ = *src++;
        }
    }

    *dst = '\0';
}

void add_word(struct word_count *counts, int *num_words, char *word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(word, counts[i].word) == 0) {
            counts[i].count++;
            return;
        }
    }

    if (*num_words < MAX_WORDS) {
        strcpy(counts[*num_words].word, word);
        counts[*num_words].count = 1;
        (*num_words)++;
    }
}

void print_counts(struct word_count *counts, int num_words) {
    printf("Word\t\tCount\n");
    printf("--------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-20s%d\n", counts[i].word, counts[i].count);
    }
}

int main() {
    struct word_count counts[MAX_WORDS];
    int num_words = 0;

    char input[1000];
    char *token = NULL;

    printf("Enter some text:\n");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, " \n");
    while (token != NULL) {
        remove_punctuation(token);
        add_word(counts, &num_words, token);
        token = strtok(NULL, " \n");
    }

    print_counts(counts, num_words);

    return 0;
}