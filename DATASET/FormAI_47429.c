//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

void countWords(char *text, Word *wordList, int *numWords) {
    char *currentWord = strtok(text, " \n\t\r\f\v");
    while (currentWord != NULL) {
        int i;
        for (i = 0; i < *numWords; i++) {
            if (strcmp(wordList[i].word, currentWord) == 0) {
                wordList[i].frequency++;
                break;
            }
        }
        if (i == *numWords) {
            if (*numWords == MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(EXIT_FAILURE);
            }
            strncpy(wordList[*numWords].word, currentWord, MAX_WORD_LENGTH - 1);
            wordList[*numWords].frequency = 1;
            (*numWords)++;
        }
        currentWord = strtok(NULL, " \n\t\r\f\v");
    }
}

int compareWordsByFrequencyDesc(const void *p1, const void *p2) {
    const Word *word1 = (Word*)p1;
    const Word *word2 = (Word*)p2;
    return word2->frequency - word1->frequency;
}

int main() {
    printf("Enter text: ");
    fflush(stdout);
    char text[10000];
    fgets(text, 10000, stdin);

    // Convert to lowercase
    int i;
    for (i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Create word list
    Word wordList[MAX_WORDS];
    int numWords = 0;
    countWords(text, wordList, &numWords);

    // Sort words by frequency
    qsort(wordList, numWords, sizeof(Word), compareWordsByFrequencyDesc);

    // Print word frequencies
    printf("Word Frequencies:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].frequency);
    }

    return 0;
}