//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

// Function to count number of words in a string
int countWords(char *str) {
    int i, wordCount = 1;
    int strLen = strlen(str);
    for (i = 0; i < strLen; i++) {
        if (isspace(str[i])) {
            wordCount++;
        }
    }
    return wordCount;
}

// Function to convert string to lowercase
void strToLower(char *str) {
    int i, strLen = strlen(str);
    for (i = 0; i < strLen; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char inputStr[1000];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int wordCount[MAX_WORD_LENGTH];
    int i, j, k;
    int totalWords = 0;
    int uniqueWords = 0;
    
    printf("Enter a string: ");
    fgets(inputStr, 1000, stdin);
    
    // Convert input string to lowercase
    strToLower(inputStr);
    
    // Tokenize input string into individual words
    char *token = strtok(inputStr, " ,.-");
    while (token != NULL) {
        // Add word to words array if it doesn't already exist
        for (i = 0; i < uniqueWords; i++) {
            if (strcmp(token, words[i]) == 0) {
                wordCount[i]++;
                break;
            }
        }
        if (i == uniqueWords) {
            strcpy(words[uniqueWords], token);
            wordCount[uniqueWords] = 1;
            uniqueWords++;
        }
        totalWords++;
        token = strtok(NULL, " ,.-");
    }
    
    // Output word frequency table
    printf("\nWord Count Table:\n\n");
    printf("%-15s %-15s\n", "Word", "Count");
    for (i = 0; i < uniqueWords; i++) {
        printf("%-15s %-15d\n", words[i], wordCount[i]);
    }
    printf("\nNumber of words: %d\n", totalWords);
    printf("Number of unique words: %d\n", uniqueWords);
    
    return 0;
}