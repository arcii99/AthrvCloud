//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTIMENT 5
#define MAX_LETTERS 500

// Function prototypes
int getSentiment(char*);
int countWords(char*);
char* removePunctuations(char*);

char *sentiments[MAX_SENTIMENT] = {"Positive", "Somewhat Positive", "Neutral", "Somewhat Negative", "Negative"};

int main() {
    char text[MAX_LETTERS];
    int sentiment;
    printf("Enter a text to analyze sentiment:\n");
    fgets(text, MAX_LETTERS, stdin);
    // remove newline character
    text[strcspn(text, "\n")] = 0;

    // Remove punctuations from text
    char* textWithoutPunctuations = removePunctuations(text);

    // Count the number of words in the text
    int wordsCount = countWords(textWithoutPunctuations);

    // get the sentiment value
    sentiment = getSentiment(textWithoutPunctuations);

    printf("\nAnalysis:\n");
    printf("Number of words: %d\n", wordsCount);
    printf("Sentiment: %s\n", sentiments[sentiment]);

    return 0;
}

// Function to count the number of words in a given string
int countWords(char *str) {
    int words = 0;
    int in_word = 0;

    while (*str != '\0') {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str == '-' && in_word)) {
            in_word = 1;
        } else {
            if (in_word) {
                words++;
            }
            in_word = 0;
        }
        str++;
    }

    if (in_word) {
        words++;
    }

    return words;
}

// Function to remove punctuations from the given string
char* removePunctuations(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (ispunct(str[i]) && str[i] != '-') {
            for (int j = i; j < strlen(str); j++) {
                str[j] = str[j + 1];
            }
        }
    }
    return str;
}

// Function to get the sentiment value of the given text
int getSentiment(char *text) {
    int sentiment = 2; // Neutral by default
    int positiveCount = 0;
    int negativeCount = 0;

    char* word = strtok(text, " ");

    while (word != NULL) {
        // Check if the word is a positive or negative word
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0 || strcmp(word, "excellent") == 0 || strcmp(word, "fantastic") == 0) {
            positiveCount++;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0 || strcmp(word, "awful") == 0 || strcmp(word, "poor") == 0) {
            negativeCount++;
        }

        word = strtok(NULL, " ");
    }

    // Calculate the sentiment value based on the positive and negative count
    if (positiveCount >= 2) {
        sentiment = 0; // Positive
    } else if (positiveCount == 1) {
        sentiment = 1; // Somewhat positive
    } else if (negativeCount >= 2) {
        sentiment = 4; // Negative
    } else if (negativeCount == 1) {
        sentiment = 3; // Somewhat negative
    }

    return sentiment;
}