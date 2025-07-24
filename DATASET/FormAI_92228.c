//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS_COUNT 1000

int main() {
    char text[MAX_WORD_LENGTH];
    char words[MAX_WORDS_COUNT][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS_COUNT];
    int i, j, wordsCount = 0;
    
    printf("Enter text:\n");
    
    while (scanf("%s", text) != EOF) {
        // Remove punctuation marks
        for (i = 0, j = 0; i < strlen(text); i++) {
            if (isalpha(text[i])) {
                text[j++] = tolower(text[i]);
            }
        }
        text[j] = '\0';
        
        // Check if word already exists
        for (i = 0; i < wordsCount; i++) {
            if (strcmp(words[i], text) == 0) {
                frequency[i]++;
                break;
            }
        }
        
        // Add new word to the list
        if (i == wordsCount) {
            strcpy(words[wordsCount], text);
            frequency[wordsCount] = 1;
            wordsCount++;
        }
    }
    
    // Print result
    printf("\nWord Frequency\n");
    for (i = 0; i < wordsCount; i++) {
        printf("%-15s%d\n", words[i], frequency[i]);
    }
    
    return 0;
}