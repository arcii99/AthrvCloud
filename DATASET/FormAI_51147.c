//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word
#define MAX_WORDS 1000 // Maximum number of unique words

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main() {
    struct WordFrequency words[MAX_WORDS];
    int numWords = 0;

    // Read in input from user
    char input[1000];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Split input into individual words
    char *token = strtok(input, " \n");
    while (token != NULL) {
        // Convert word to lowercase
        for (int i=0; i<strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Check if word is already in list
        int wordIndex = -1;
        for (int i=0; i<numWords; i++) {
            if (strcmp(words[i].word, token) == 0) {
                wordIndex = i;
                break;
            }
        }

        // Increment frequency or add new word
        if (wordIndex != -1) {
            words[wordIndex].frequency++;
        } else {
            strcpy(words[numWords].word, token);
            words[numWords].frequency = 1;
            numWords++;
        }

        // Get next token
        token = strtok(NULL, " \n");
    }

    // Sort words by frequency
    for (int i=0; i<numWords-1; i++) {
        for (int j=i+1; j<numWords; j++) {
            if (words[j].frequency > words[i].frequency) {
                struct WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print results
    printf("\nWord\t\tFrequency\n");
    printf("------------------------\n");
    for (int i=0; i<numWords; i++) {
        printf("%-15s %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}