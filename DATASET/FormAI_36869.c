//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} word_count_t;

void add_word(word_count_t *word_counts, int *num_words, char *word);
void print_words(word_count_t *word_counts, int num_words);

int main() {
    char input[10000];
    int num_words = 0;
    word_count_t word_counts[MAX_WORDS];

    printf("Enter text:\n");
    fgets(input, sizeof(input), stdin);

    char *word = strtok(input, " \n");

    while (word != NULL && num_words < MAX_WORDS) {
        add_word(word_counts, &num_words, word);
        word = strtok(NULL, " \n");
    }

    print_words(word_counts, num_words);

    return 0;
}

void add_word(word_count_t *word_counts, int *num_words, char *word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            // Word already in list, increment count
            word_counts[i].count++;
            return;
        }
    }

    // Word not in list, add it
    strcpy(word_counts[*num_words].word, word);
    word_counts[*num_words].count = 1;
    (*num_words)++;
}

void print_words(word_count_t *word_counts, int num_words) {
    printf("\nWord count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}