//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 50000

void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char line[MAX_WORD_LENGTH];
        while (fgets(line, sizeof(line), file)) {
            strtok(line, "\r\n");
            strcpy(dictionary[*num_words], line);
            (*num_words)++;
        }
        fclose(file);
    }
}

bool is_word_misspelled(const char *word, char dictionary[][MAX_WORD_LENGTH], int num_words) {
    int left = 0, right = num_words - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp_res = strcmp(word, dictionary[mid]);
        if (cmp_res < 0) {
            right = mid - 1;
        } else if (cmp_res > 0) {
            left = mid + 1;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;
    load_dictionary("dictionary.txt", dictionary, &num_words);

    char sentence[1000];
    printf("Enter a sentence to check spelling (max 1000 characters):\n");
    fgets(sentence, sizeof(sentence), stdin);

    char *word = strtok(sentence, " ,.!?\"();:\r\n");
    while (word) {
        if (is_word_misspelled(word, dictionary, num_words)) {
            printf("Misspelled word: %s\n", word);
        }
        word = strtok(NULL, " ,.!?\"();:\r\n");
    }

    return 0;
}