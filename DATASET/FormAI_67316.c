//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUMBER_OF_WORDS 1000

int main() {
    char text[MAX_WORD_LENGTH * MAX_NUMBER_OF_WORDS];
    char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int frequencies[MAX_NUMBER_OF_WORDS];
    int numberOfWords = 0;

    printf("Enter a text:\n");
    fgets(text, sizeof(text), stdin);

    // Split text into words
    char *word = strtok(text, " ,.?!;:\n");
    while (word != NULL) {
        int length = strlen(word);
        for (int i = 0; i < length; i++) {
            word[i] = tolower(word[i]);
        }
        strcpy(words[numberOfWords], word);
        numberOfWords++;
        word = strtok(NULL, " ,.?!;:\n");
    }

    // Count word frequencies
    for (int i = 0; i < numberOfWords; i++) {
        int frequency = 1;
        for (int j = i + 1; j < numberOfWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency++;
                // Remove duplicate word
                for (int k = j; k < numberOfWords - 1; k++) {
                    strcpy(words[k], words[k + 1]);
                }
                numberOfWords--;
            }
        }
        frequencies[i] = frequency;
    }

    // Print word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < numberOfWords; i++) {
        printf("%s\t%d\n", words[i], frequencies[i]);
    }

    return 0;
}