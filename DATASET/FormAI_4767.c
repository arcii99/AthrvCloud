//FormAI DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000 // Maximum length of a message
#define MAX_SPAM_WORDS 10 // Maximum number of spam words to detect
#define MAX_SPAM_SCORE 5 // Maximum spam score before a message is marked as spam

// Declare function to check if a message contains spam words
int checkSpam(char message[], char spamWords[][50], int spamWordsCount);

int main() {
    // Initialize spam words
    char spamWords[MAX_SPAM_WORDS][50] = {"buy now", "limited time offer", "make money fast"};

    // Declare variables
    char message[MAX_MESSAGE_LENGTH];
    int spamWordsCount = 3, spamScore = 0;

    // Prompt user for input message
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove trailing newline character from message
    message[strcspn(message, "\n")] = '\0';

    // Check if message contains spam words
    spamScore = checkSpam(message, spamWords, spamWordsCount);

    // Display spam score and message classification
    printf("Spam Score: %d\n", spamScore);
    if (spamScore >= MAX_SPAM_SCORE) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}

int checkSpam(char message[], char spamWords[][50], int spamWordsCount) {
    int spamScore = 0;

    // Convert message to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(message); i++) {
        message[i] = tolower(message[i]);
    }

    // Loop through spam words and check if they appear in message
    for (int i = 0; i < spamWordsCount; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            spamScore++;
        }
    }

    return spamScore;
}