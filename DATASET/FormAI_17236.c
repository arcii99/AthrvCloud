//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to hold word frequency data
typedef struct {
    char word[50];
    int freq;
} WordFreq;

int main() {
    // Initialize variables and counters
    int max_words = 1000;
    int num_words = 0;
    int i, j;

    // Allocate memory for word frequency data
    WordFreq *word_freqs = malloc(max_words * sizeof(WordFreq));

    // Prompt user for input
    printf("Enter a surreal sentence: ");
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Split input into words
    char *word = strtok(input, " ,.?!:");

    // Loop through words and count frequency
    while (word != NULL) {
        // Lowercase word for case-insensitive comparison
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word already exists in frequency data
        int found = 0;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_freqs[i].word) == 0) {
                word_freqs[i].freq++;
                found = 1;
                break;
            }
        }

        // Add new word to frequency data if not found
        if (!found) {
            if (num_words == max_words) {
                max_words *= 2;
                word_freqs = realloc(word_freqs, max_words * sizeof(WordFreq));
            }
            strcpy(word_freqs[num_words].word, word);
            word_freqs[num_words].freq = 1;
            num_words++;
        }

        // Get next word
        word = strtok(NULL, " ,.?!:");
    }

    // Sort word frequency data by frequency
    for (i = 0; i < num_words-1; i++) {
        for (j = 0; j < num_words-i-1; j++) {
            if (word_freqs[j].freq < word_freqs[j+1].freq) {
                WordFreq temp = word_freqs[j];
                word_freqs[j] = word_freqs[j+1];
                word_freqs[j+1] = temp;
            }
        }
    }

    // Print word frequency data to console
    printf("\nWord Frequencies:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_freqs[i].word, word_freqs[i].freq);
    }

    // Free memory and exit
    free(word_freqs);
    return 0;
}