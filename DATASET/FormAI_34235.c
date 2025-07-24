//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50  // Maximum word length
#define MAX_WORDS 1000      // Maximum number of unique words

typedef struct {
    char word[MAX_WORD_LENGTH + 1]; // +1 for null character
    int count;
} WordFreq;

int main() {
    char input[1000];
    char word[MAX_WORD_LENGTH + 1]; // +1 for null character
    int i, j, k, found, num_words = 0;
    WordFreq freq[MAX_WORDS];

    // Take input from user
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Convert input to lowercase
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        input[i] = tolower(input[i]);
    }

    // Loop through each word in input
    i = 0;
    while (input[i] != '\0') {
        // Extract word
        j = 0;
        while (input[i] != ' ' && input[i] != '\n' && input[i] != '\0') {
            word[j++] = input[i++];
        }
        word[j] = '\0';

        // Check if word is already in frequency array
        found = 0;
        for (k = 0; k < num_words; k++) {
            if (strcmp(word, freq[k].word) == 0) {
                found = 1;
                freq[k].count++;
                break;
            }
        }

        // If word is not in frequency array, add it
        if (!found) {
            strncpy(freq[num_words].word, word, MAX_WORD_LENGTH);
            freq[num_words].count = 1;
            num_words++;
        }

        // Move to next word
        i++;
    }

    // Sort frequency array in descending order
    WordFreq temp;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (freq[i].count < freq[j].count) {
                temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }

    // Print frequency table
    printf("Word\t\tFrequency\n");
    printf("============================\n");
    for (i = 0; i < num_words; i++) {
        printf("%-15s\t%d\n", freq[i].word, freq[i].count);
    }

    return 0;
}