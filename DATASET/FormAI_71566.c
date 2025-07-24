//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

struct WordFrequency {
    char word[50];
    int frequency;
};

int compare_word(const void *a, const void *b) {
    struct WordFrequency *freq_a = (struct WordFrequency *) a;
    struct WordFrequency *freq_b = (struct WordFrequency *) b;
    return (freq_a->frequency < freq_b->frequency) - (freq_a->frequency > freq_b->frequency);
}

int main() {
    char text[1000];
    printf("Enter a document to count the frequency of words: ");
    fgets(text, 1000, stdin);

    int num_words = 0;
    struct WordFrequency word_freqs[MAX_WORDS];

    char *word = strtok(text, " ,.-\n\t");
    while (word != NULL) {
        int i;
        for (i = 0; i < num_words; ++i) {
            if (strcasecmp(word_freqs[i].word, word) == 0) {
                ++word_freqs[i].frequency;
                break;
            }
        }
        if (i == num_words) {
            if (num_words == MAX_WORDS) {
                fprintf(stderr, "Reached maximum number of words allowed.");
                return -1;
            }
            struct WordFrequency new_word_freq = { .frequency = 1 };
            strcpy(new_word_freq.word, word);
            word_freqs[num_words] = new_word_freq;
            ++num_words;
        }
        word = strtok(NULL, " ,.-\n\t");
    }

    qsort(word_freqs, num_words, sizeof(struct WordFrequency), compare_word);

    printf("Word frequency:\n\n");
    int i;
    for (i = 0; i < num_words; ++i) {
        printf("%-15s%d\n", word_freqs[i].word, word_freqs[i].frequency);
    }

    return 0;
}