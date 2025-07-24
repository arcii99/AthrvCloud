//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int freq;
} WordFreq;

void bubble_sort(WordFreq *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].freq < arr[j+1].freq) {
                WordFreq tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int count_words(char *text) {
    int cnt = 0;
    char *tok = strtok(text, " ");
    while (tok != NULL) {
        cnt++;
        tok = strtok(NULL, " ");
    }
    return cnt;
}

WordFreq *get_word_freq(char *text, int n_words) {
    WordFreq *word_freq = malloc(n_words * sizeof(WordFreq));
    int idx = 0;

    char *tok = strtok(text, " ");
    while (tok != NULL) {
        int found = 0;
        for (int i = 0; i < idx; i++) {
            if (strcmp(word_freq[i].word, tok) == 0) {
                word_freq[i].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_freq[idx].word = tok;
            word_freq[idx].freq = 1;
            idx++;
        }

        tok = strtok(NULL, " ");
    }

    word_freq = realloc(word_freq, idx * sizeof(WordFreq));
    return word_freq;
}

int main() {
    char *text = "This is a sample text to test the word frequency program.";
    int n_words = count_words(text);
    WordFreq *word_freq = get_word_freq(text, n_words);
    bubble_sort(word_freq, n_words);

    printf("Word\tFrequency\n");
    printf("-----------------\n");
    for (int i = 0; i < n_words; i++) {
        printf("%s\t%d\n", word_freq[i].word, word_freq[i].freq);
    }

    free(word_freq);
    return 0;
}