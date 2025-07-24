//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_UNIQUE_WORDS 1000

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_frequency *word1 = a;
    const struct word_frequency *word2 = b;
    return word2->count - word1->count;
}

void print_frequencies(struct word_frequency *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void update_frequency(struct word_frequency *words, char *word) {
    int i;
    for (i = 0; i < MAX_UNIQUE_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            break;
        }

        if (words[i].count == 0) {
            strcpy(words[i].word, word);
            words[i].count++;
            break;
        }
    }
}

int main() {
    char input_string[1000];
    char *token;
    struct word_frequency word_frequencies[MAX_UNIQUE_WORDS];

    printf("Enter a sentence: ");
    fgets(input_string, sizeof(input_string), stdin);

    token = strtok(input_string, " \t\n\r.,:;?!-");

    while (token != NULL) {
        update_frequency(word_frequencies, token);
        token = strtok(NULL, " \t\n\r.,:;?!-");
    }

    int num_words = sizeof(word_frequencies) / sizeof(word_frequencies[0]);

    qsort(word_frequencies, num_words, sizeof(struct word_frequency), compare_words);

    print_frequencies(word_frequencies, num_words);

    return 0;
}