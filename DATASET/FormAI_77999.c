//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

// Struct to store word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordFreq;

// Function to read words from input file
void readWords(FILE *inputFile, WordFreq *wordFrequency, int *numWords) {
    char currentLine[MAX_LINE_LENGTH + 1];
    char *currentWord;

    // Read each line from the input file
    while (fgets(currentLine, MAX_LINE_LENGTH, inputFile)) {
        // Split line into words
        currentWord = strtok(currentLine, " \t\n");

        while (currentWord != NULL) {
            // Convert word to lowercase
            for (int i = 0; currentWord[i] != '\0'; i++) {
                currentWord[i] = tolower(currentWord[i]);
            }

            // Add word to frequency counter
            int wordFound = 0;
            for (int i = 0; i < *numWords; i++) {
                if (strcmp(wordFrequency[i].word, currentWord) == 0) {
                    wordFrequency[i].count++;
                    wordFound = 1;
                    break;
                }
            }

            // If word is not found, add it to the frequency counter
            if (!wordFound) {
                if (*numWords == 0) {
                    strcpy(wordFrequency[0].word, currentWord);
                    wordFrequency[0].count = 1;
                    (*numWords)++;
                } else if (*numWords < MAX_WORD_LENGTH) {
                    strcpy(wordFrequency[*numWords].word, currentWord);
                    wordFrequency[*numWords].count = 1;
                    (*numWords)++;
                }
            }

            currentWord = strtok(NULL, " \t\n");
        }
    }
}

// Function to sort word frequency table in descending order
void sortWords(WordFreq *wordFrequency, int numWords) {
    WordFreq tempWordFreq;

    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (wordFrequency[i].count < wordFrequency[j].count) {
                tempWordFreq = wordFrequency[i];
                wordFrequency[i] = wordFrequency[j];
                wordFrequency[j] = tempWordFreq;
            }
        }
    }
}

// Function to print word frequency table
void printWords(WordFreq *wordFrequency, int numWords) {
    printf("Word Frequency\n");
    printf("-----------------------\n");
    printf("%-20s | %s\n", "Word", "Frequency");
    printf("-----------------------\n");

    for (int i = 0; i < numWords; i++) {
        printf("%-20s | %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }
}

int main() {
    FILE *inputFile;
    WordFreq wordFrequency[MAX_WORD_LENGTH];
    int numWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return EXIT_FAILURE;
    }

    // Read words from input file
    readWords(inputFile, wordFrequency, &numWords);

    // Close input file
    fclose(inputFile);

    // Sort word frequency table in descending order
    sortWords(wordFrequency, numWords);

    // Print word frequency table
    printWords(wordFrequency, numWords);

    return EXIT_SUCCESS;
}