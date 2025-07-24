//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
/*
 * C Word Frequency Counter
 * Author: Ken Thompson (inspired by)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct word_t {
    char *word;
    int frequency;
} word_t;

void count_words(FILE *file, word_t **words, int *count) {
    char buffer[256];
    while (fgets(buffer, 256, file)) {
        char *token = strtok(buffer, " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\n\t");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < *count; i++) {
                if (strcmp((*words)[i].word, token) == 0) {
                    (*words)[i].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                *words = realloc(*words, (*count + 1) * sizeof(word_t));
                (*words)[*count].word = strdup(token);
                (*words)[*count].frequency = 1;
                (*count)++;
            }
            token = strtok(NULL, " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~\n\t");
        }
    }
}

void print_words(word_t *words, int count) {
    for (int i = 0; i < count; i++) {
        printf("%-15s %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s FILE\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }
    word_t *words = calloc(1, sizeof(word_t));
    int count = 0;
    count_words(file, &words, &count);
    fclose(file);
    print_words(words, count);
    for (int i = 0; i < count; i++) {
        free(words[i].word);
    }
    free(words);
    return 0;
}