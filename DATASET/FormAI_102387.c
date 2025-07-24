//FormAI DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000

int countWords(char* sentence);

int main(void) {
    char sentence[MAX_SIZE];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SIZE, stdin);  // Get user input
    int wordCount = countWords(sentence);
    printf("Your sentence contains %d words.\n", wordCount);
    return 0;
}

int countWords(char* sentence) {
    int wordCount = 0;
    int sentenceLength = strlen(sentence);
    char lastCharIsNotWord = 0;
    for (int i = 0; i < sentenceLength; i++) {
        char currentChar = sentence[i];
        if (isspace(currentChar) || ispunct(currentChar)) {
            if(!lastCharIsNotWord) {
                wordCount++;
            }
            lastCharIsNotWord = 1;
        } else if (isalpha(currentChar)) {
            lastCharIsNotWord = 0;
        }
    }
    return wordCount;
}