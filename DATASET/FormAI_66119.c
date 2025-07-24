//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 500
#define MAX_WORD_LENGTH 50

int main() {
    char inputString[MAX_STRING_LENGTH]; // String input by user
    char wordList[MAX_STRING_LENGTH][MAX_WORD_LENGTH]; // List of words extracted from input string
    int sentimentScore = 0; // Variable to keep track of sentiment score
    
    printf("Enter a string to analyze: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin); // Take input from user
    
    // Extracting individual words from string and storing them in a list
    int wordCount = 0; // Counter for number of words extracted
    char *token = strtok(inputString, " "); // First call to strtok
    while (token != NULL) {
        // Remove any punctuation marks from end of word
        if (token[strlen(token)-1] == '.' || token[strlen(token)-1] == ',' || token[strlen(token)-1] == '!' || token[strlen(token)-1] == '?') {
            token[strlen(token)-1] = '\0';
        }
        strcpy(wordList[wordCount], token); // Copy word to list
        wordCount++; // Increment word count
        token = strtok(NULL, " "); // Next call to strtok
    }
    
    // Assigning sentiment values to words
    char positiveWords[5][MAX_WORD_LENGTH] = {"happy", "joy", "excitement", "love", "fun"}; // List of positive words
    char negativeWords[5][MAX_WORD_LENGTH] = {"sad", "hate", "pain", "disgust", "anger"}; // List of negative words
    int sentimentValues[5] = {2, -2, -1, -2, -1}; // Sentiment values for respective positive/negative words
    
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < 5; j++) {
            if (strcmp(wordList[i], positiveWords[j]) == 0) {
                sentimentScore += sentimentValues[j];
                break;
            }
            else if (strcmp(wordList[i], negativeWords[j]) == 0) {
                sentimentScore += sentimentValues[j];
                break;
            }
        }
    }
    
    // Analyzing sentiment score
    if (sentimentScore > 0) {
        printf("The sentiment of the input string is positive.\n");
    }
    else if (sentimentScore < 0) {
        printf("The sentiment of the input string is negative.\n");
    }
    else {
        printf("The sentiment of the input string is neutral.\n");
    }
    
    return 0;
}