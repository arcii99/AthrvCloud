//FormAI DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_SPAM_COUNT 10

// Struct to hold potential spam messages and their frequency count
struct SpamMessage {
    char message[100];
    int count;
};

// Array of potential spam messages
struct SpamMessage spamMessages[MAX_SPAM_COUNT];

// Function to check if a given message is spam
bool IsSpam(char* message) {
    int i, j;
    char* words[MAX_SPAM_COUNT];
    int wordCount = 0;
    bool isMatch;

    // Split message into words
    char* currentWord = strtok(message, " ");
    while (currentWord != NULL) {
        words[wordCount++] = currentWord;
        currentWord = strtok(NULL, " ");
    }

    // Check each word against each potential spam message
    for (i = 0; i < wordCount; i++) {
        for (j = 0; j < MAX_SPAM_COUNT; j++) {
            if (strcmp(words[i], spamMessages[j].message) == 0) {
                spamMessages[j].count++;
                return true;
            }
        }
    }

    return false;
}

// Function to add a potential spam message
void AddSpamMessage(char* spamMessage) {
    int i;

    // Check if the message already exists in the list
    for (i = 0; i < MAX_SPAM_COUNT; i++) {
        if (strcmp(spamMessage, spamMessages[i].message) == 0) {
            return;
        }
    }

    // Add the message to the list
    for (i = 0; i < MAX_SPAM_COUNT; i++) {
        if (spamMessages[i].count == 0) {
            strcpy(spamMessages[i].message, spamMessage);
            spamMessages[i].count = 1;
            return;
        }
    }
}

int main() {
    int i;
    char input[100];

    // Initialize all potential spam messages to empty strings and a count of 0
    for (i = 0; i < MAX_SPAM_COUNT; i++) {
        strcpy(spamMessages[i].message, "");
        spamMessages[i].count = 0;
    }

    // Add some initial potential spam messages
    AddSpamMessage("buy now");
    AddSpamMessage("money back guarantee");
    AddSpamMessage("limited time only");

    // Get user input and check for spam
    while (true) {
        printf("Enter a message:\n");
        fgets(input, 100, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (IsSpam(input)) {
            printf("This message is spam!\n");
        } else {
            printf("This message is not spam.\n");
        }
    }

    return 0;
}