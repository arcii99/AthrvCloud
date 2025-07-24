//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_freq_t;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    FILE *fp = fopen(input_file, "r");

    if (!fp) {
        fprintf(stderr, "Could not open file: %s\n", input_file);
        return 1;
    }

    word_freq_t word_freqs[MAX_WORD_LENGTH];
    int num_word_freqs = 0;

    char current_word[MAX_WORD_LENGTH];
    memset(current_word, '\0', MAX_WORD_LENGTH);

    char current_char = fgetc(fp);
    int current_word_length = 0;

    while (current_char != EOF) {
        if (isspace(current_char) || !isalpha(current_char)) {
            if (current_word_length > 0) {
                int i = 0;
                while (i < num_word_freqs && strcmp(word_freqs[i].word, current_word) != 0) {
                    i++;
                }

                if (i == num_word_freqs) {
                    strcpy(word_freqs[i].word, current_word);
                    word_freqs[i].frequency = 1;
                    num_word_freqs++;
                } else {
                    word_freqs[i].frequency++;
                }

                memset(current_word, '\0', MAX_WORD_LENGTH);
                current_word_length = 0;
            }
        } else {
            current_word[current_word_length++] = tolower(current_char);
        }

        current_char = fgetc(fp);
    }

    fclose(fp);

    // Sort the word frequencies by frequency in decreasing order
    for (int i = 0; i < num_word_freqs - 1; i++) {
        for (int j = i + 1; j < num_word_freqs; j++) {
            if (word_freqs[i].frequency < word_freqs[j].frequency) {
                word_freq_t temp = word_freqs[i];
                word_freqs[i] = word_freqs[j];
                word_freqs[j] = temp;
            }
        }
    }

    // Print the word frequencies
    printf("Word Frequencies\n");
    printf("----------------------------\n");
    printf("%-20s %-10s\n", "Word", "Frequency");
    printf("----------------------------\n");

    for (int i = 0; i < num_word_freqs; i++) {
        printf("%-20s %-10d\n", word_freqs[i].word, word_freqs[i].frequency);
    }

    return 0;
}