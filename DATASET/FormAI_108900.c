//FormAI DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct word_frequency {
    char *word;
    int frequency;
};

void remove_punctuation(char *word) {
    int i, j = 0;
    for(i = 0; word[i] != '\0'; i++) {
        if(isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
    }
    word[j] = '\0';
}

void print_frequencies(struct word_frequency *frequencies, int count) {
    int i;
    printf("Word Frequencies:\n");
    for(i = 0; i < count; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].frequency);
    }
}

const char *SHERLOCK = "It is a capital mistake to theorize before one has data. Insensibly one begins to twist facts to suit theories, instead of theories to suit facts.";

int main() {
    char *text = strdup(SHERLOCK);
    char *word = strtok(text, " ");
    struct word_frequency *frequencies = NULL;
    int count = 0;
    while(word) {
        remove_punctuation(word);
        int i;
        for(i = 0; i < count; i++) {
            if(strcmp(frequencies[i].word, word) == 0) {
                frequencies[i].frequency++;
                break;
            }
        }
        if(i == count) {
            count++;
            frequencies = realloc(frequencies, count * sizeof(struct word_frequency));
            frequencies[count-1].word = strdup(word);
            frequencies[count-1].frequency = 1;
        }
        word = strtok(NULL, " ");
    }
    print_frequencies(frequencies, count);
    free(text);
    int i;
    for(i = 0; i < count; i++) {
        free(frequencies[i].word);
    }
    free(frequencies);
    return 0;
}