//FormAI DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

void normalize_word(char *word) {
    // Convert word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

void insert_word_to_list(char *word, WordFreq *list, int *num_words) {
    // Check if word already exists in list
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(list[i].word, word) == 0) {
            list[i].freq++;
            return;
        }
    }
    // Add new word to list if it doesn't already exist
    strncpy(list[*num_words].word, word, MAX_WORD_LEN);
    list[*num_words].freq = 1;
    (*num_words)++;
}

void print_word_freq(WordFreq *list, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", list[i].word, list[i].freq);
    }
}

int main() {
    char text[MAX_WORDS * MAX_WORD_LEN];
    WordFreq list[MAX_WORDS];
    int num_words = 0;

    // Read input text
    printf("Enter text (max %d words): ", MAX_WORDS);
    fgets(text, sizeof(text), stdin);

    // Parse words from input text
    char *word = strtok(text, " \t\n"); // Split text into words
    while (word) {
        normalize_word(word);
        insert_word_to_list(word, list, &num_words);
        word = strtok(NULL, " \t\n"); // Get next word
    }

    // Print list of word frequencies
    print_word_freq(list, num_words);

    return 0;
}