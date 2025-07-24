//FormAI DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SPAM_KEYWORDS 5
#define MAX_SPAM_LENGTH 50

char spamKeywords[MAX_SPAM_KEYWORDS][MAX_SPAM_LENGTH] = {"buy", "sale", "discount", "click here", "limited time offer"};

bool checkForSpam(char *message) {
    char *lowercaseMessage = strdup(message);
    int i;

    // Convert message to lowercase
    for (i = 0; lowercaseMessage[i]; i++) {
        lowercaseMessage[i] = tolower(lowercaseMessage[i]);
    }

    // Check for the presence of spam keywords
    for (i = 0; i < MAX_SPAM_KEYWORDS; i++) {
        if (strstr(lowercaseMessage, spamKeywords[i]) != NULL) {
            return true;
        }
    }

    return false;
}

int main() {
    char inputMessage[MAX_SPAM_LENGTH];
    printf("Enter a message: ");
    fgets(inputMessage, MAX_SPAM_LENGTH, stdin);

    bool isSpam = checkForSpam(inputMessage);

    if (isSpam) {
        printf("This message contains spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}