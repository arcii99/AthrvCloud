//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
// This C program implements a spam detection system using AI
// The system analyses the chat messages and predicts if the message is spam or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256

int main(void) {
    char input[MAX_STR_LEN];
    int spamCount = 0;
    int notSpamCount = 0;

    printf("Welcome to the Spam Detection System\n");

    while (1) {
        printf("Please enter a message: ");
        fgets(input, MAX_STR_LEN, stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // identify if message is spam or not
        int isSpam = detectSpam(input);

        if (isSpam) {
            printf("Warning: Message is spam\n");
            spamCount++;
        } else {
            printf("Message is not spam\n");
            notSpamCount++;
        }

        // display statistics
        printf("Spam count: %d\n", spamCount);
        printf("Not-spam count: %d\n", notSpamCount);
    }

    return 0;
}

/**
 * This function predicts if a given message is spam or not
 */
int detectSpam(char *message) {
    // AI algorithm to be implemented here

    // for demonstration purposes, all messages containing the word "free"
    // are considered as spam
    if (strstr(message, "free") != NULL) {
        return 1;
    }

    return 0;
}