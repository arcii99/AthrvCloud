//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct word_freq {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFreq;

int main(void) {
    char text[MAX_WORDS][MAX_WORD_LENGTH] = { {0} };
    WordFreq word_freq[MAX_WORDS] = { {0} };
    int num_words = 0;

    // Get text input
    printf("Enter text: ");
    fgets(text[0], MAX_WORDS * MAX_WORD_LENGTH, stdin);

    // Parse words and count frequency
    char *pch = strtok(text[0], " \n");
    while (pch != NULL) {
        // Convert to lowercase
        for (int i = 0; i < strlen(pch); i++) {
            pch[i] = tolower(pch[i]);
        }

        // Check if word already exists in array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(pch, word_freq[i].word) == 0) {
                found = 1;
                word_freq[i].frequency++;
                break;
            }
        }

        // Add new word to array if not found
        if (!found) {
            strcpy(word_freq[num_words].word, pch);
            word_freq[num_words].frequency++;
            num_words++;
        }

        // Get next word
        pch = strtok(NULL, " \n");
    }

    // Print frequency table
    printf("\nWord Frequency Table:\n");
    printf("----------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s %d\n", word_freq[i].word, word_freq[i].frequency);
    }

    return 0;
}