//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 500

struct word_freq {
    char *word;
    int freq;
};

void add_word(struct word_freq list[], char *word);
void print_freq(struct word_freq list[]);

int main(void) {
    char *current_word = malloc(MAX_WORD_LENGTH * sizeof(char));
    int curr_word_len = 0;
    int num_words = 0;

    // create list of MAX_WORDS word_freq structs
    struct word_freq list[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        list[i].word = malloc(MAX_WORD_LENGTH * sizeof(char));
        list[i].freq = 0;
    }

    // read words from stdin until EOF
    char c = getchar();
    while (c != EOF) {
        if (isalpha(c)) {  // add character to current_word
            current_word[curr_word_len] = tolower(c);
            curr_word_len++;

            // if current_word is too long, ignore the rest of the word
            if (curr_word_len >= MAX_WORD_LENGTH) {
                while (isalpha(getchar())) {}
                curr_word_len = 0;
            }
        } else if (curr_word_len > 0) {  // word has ended, add to frequency list
            current_word[curr_word_len] = '\0';  // null-terminate string
            add_word(list, current_word);
            num_words++;
            curr_word_len = 0;
        }

        c = getchar();
    }

    // print word frequencies
    printf("Word frequency count:\n");
    print_freq(list);
    printf("\nTotal words: %d\n", num_words);

    // free malloc'd memory
    for (int i = 0; i < MAX_WORDS; i++) {
        free(list[i].word);
    }
    free(current_word);

    return 0;
}

// add word to list (increment frequency if already exists, otherwise add new entry)
void add_word(struct word_freq list[], char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(list[i].word, word) == 0) {
            list[i].freq++;
            return;
        } else if (strlen(list[i].word) == 0) {
            strcpy(list[i].word, word);
            list[i].freq++;
            return;
        }
    }
}

// print list of word frequencies in descending order of frequency
void print_freq(struct word_freq list[]) {
    int num_words = 0;
    for (int i = 0; i < MAX_WORDS && strlen(list[i].word) > 0; i++) {
        num_words++;
    }

    struct word_freq temp;
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (list[j].freq > list[i].freq) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        printf("%s: %d\n", list[i].word, list[i].freq);
    }
}