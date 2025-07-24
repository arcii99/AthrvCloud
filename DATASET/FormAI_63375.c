//FormAI DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_frequencies {
    char* word;
    int frequency;
} WordFreq;

// Function to remove punctuations from a word
void remove_punctuations(char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (ispunct(word[i])) {
            memmove(&word[i], &word[i + 1], len - i);
            len--;
            i--;
        }
    }
}

// Function to count the frequency of each word in the text
WordFreq* count_word_frequencies(char* text, int* num_words) {
    // Allocate memory for the array of WordFreq structs
    WordFreq* word_frequencies = (WordFreq*) malloc(sizeof(WordFreq) * strlen(text));
    char* word;
    *num_words = 0;

    // Tokenize the text and count the frequency of each word
    word = strtok(text, " ");
    while (word != NULL) {
        remove_punctuations(word);
        int i;
        for (i = 0; i < *num_words; i++) {
            if (strcmp(word_frequencies[i].word, word) == 0) {
                word_frequencies[i].frequency++;
                break;
            }
        }
        if (i == *num_words) {
            word_frequencies[*num_words].word = (char*) malloc(sizeof(char) * strlen(word));
            strcpy(word_frequencies[*num_words].word, word);
            word_frequencies[*num_words].frequency = 1;
            (*num_words)++;
        }
        word = strtok(NULL, " ");
    }

    // Return the array of WordFreq structs
    return word_frequencies;
}

// Function to sort the array of WordFreq structs in descending order by frequency
void sort_word_frequencies(WordFreq* word_frequencies, int num_words) {
    int i, j;
    WordFreq temp;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (word_frequencies[j].frequency > word_frequencies[i].frequency) {
                temp = word_frequencies[i];
                word_frequencies[i] = word_frequencies[j];
                word_frequencies[j] = temp;
            }
        }
    }
}

// Main function to summarize a given text
int main() {
    char* text = "The quick brown fox jumped over the lazy dog. The dog, feeling insulted, woke up and chased after the fox. The fox, being quick and cunning, managed to escape. The dog, feeling defeated, went back to sleep.";
    int num_words;
    WordFreq* word_frequencies = count_word_frequencies(text, &num_words);
    sort_word_frequencies(word_frequencies, num_words);

    // Print the top 3 most frequent words
    printf("The top 3 most frequent words in the text are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s (%d occurrences)\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }

    // Free memory used by the array of WordFreq structs
    for (int i = 0; i < num_words; i++) {
        free(word_frequencies[i].word);
    }
    free(word_frequencies);

    return 0;
}