//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

void readInput(char *input);
int countWords(char *input, char words[MAX_WORDS][MAX_WORD_LENGTH], int freq[MAX_WORDS]);
void sortWords(char words[MAX_WORDS][MAX_WORD_LENGTH], int freq[MAX_WORDS], int numWords);
void printOutput(char words[MAX_WORDS][MAX_WORD_LENGTH], int freq[MAX_WORDS], int numWords);

int main() {
    char input[10000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS] = {0};
    int numWords;

    readInput(input);
    numWords = countWords(input, words, frequency);
    sortWords(words, frequency, numWords);
    printOutput(words, frequency, numWords);

    return 0;
}

void readInput(char *input) {
    printf("Enter input text:\n");
    fgets(input, 10000, stdin);
}

int countWords(char *input, char words[MAX_WORDS][MAX_WORD_LENGTH], int freq[MAX_WORDS]) {
    int i = 0, j = 0, k = 0, wordCount = 0, len = strlen(input);
    char tempWord[MAX_WORD_LENGTH];

    for(i = 0; i <= len; i++) {
        if(*(input + i) == ' ' || *(input + i) == '\0') {
            tempWord[k] = '\0';
            k = 0;
            if(strlen(tempWord) > 0) {
                wordCount++;
                int isFound = 0;
                for(j=0; j<wordCount; j++) {
                    if(strcmp(words[j], tempWord) == 0) {
                        freq[j]++;
                        isFound = 1;
                        break;
                    }
                }
                if(isFound == 0) {
                    strcpy(words[wordCount-1], tempWord);
                    freq[wordCount-1]++;
                }
            }
        }
        else {
            if(isalpha(*(input + i))) {
                tempWord[k++] = tolower(*(input + i));
            }
        }
    }

    return wordCount;
}

void sortWords(char words[MAX_WORDS][MAX_WORD_LENGTH], int freq[MAX_WORDS], int numWords) {
    int i = 0, j = 0, tempFreq;
    char tempWord[MAX_WORD_LENGTH];

    for(i = 0; i < numWords-1; i++) {
        for(j=i+1; j<numWords; j++) {
            if(strcmp(words[i], words[j]) > 0) {
                strcpy(tempWord, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tempWord);

                tempFreq = freq[i];
                freq[i] = freq[j];
                freq[j] = tempFreq;
            }
        }
    }
}

void printOutput(char words[MAX_WORDS][MAX_WORD_LENGTH], int freq[MAX_WORDS], int numWords) {
    int i = 0;

    printf("\nWords\t\tFrequency\n\n");
    for(i=0; i<numWords; i++) {
        printf("%-15s %d\n", words[i], freq[i]);
    }
}