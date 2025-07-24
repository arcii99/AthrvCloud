//FormAI DATASET v1.0 Category: Spam Detection System ; Style: introspective
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 0.5 // Minimum spam probability to flag a message as spam

int main() {
    // Predefined spam words and their corresponding probabilities
    char spamWords[5][20] = {"buy", "cheap", "discount", "click", "money"};
    float spamProb[5] = {0.8, 0.7, 0.6, 0.5, 0.4};

    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin); // Read the message from user input

    // Remove the newline character at the end of the message
    message[strcspn(message, "\n")] = '\0';

    float totalProb = 0;
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        // Check if the current character is the beginning of a word
        if (i == 0 || message[i-1] == ' ') {
            char currentWord[20];
            int wordLen = 0;

            // Extract the current word from the message
            for (j = i; j < strlen(message) && message[j] != ' '; j++) {
                currentWord[wordLen++] = message[j];
            }
            currentWord[wordLen] = '\0';

            // Check if the current word is a spam word and add its corresponding probability to the total probability
            for (j = 0; j < 5; j++) {
                if (strcmp(currentWord, spamWords[j]) == 0) {
                    totalProb += spamProb[j];
                }
            }
        }
    }

    // Check if the total probability exceeds the threshold to flag the message as spam
    if (totalProb >= SPAM_THRESHOLD) {
        printf("%s is spam\n", message);
    } else {
        printf("%s is not spam\n", message);
    }

    return 0;
}