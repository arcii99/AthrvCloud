//FormAI DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

char spamWords[MAX_SPAM_WORDS][MAX_SPAM_LENGTH] = {"free", "money", "offer", "limited", "discount", "amazing", "win", "cash", "urgent", "act now"};

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int spamCount = 0;
    int i, j;
    
    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove trailing newline character after fgets()
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }
    
    // Convert message to lowercase
    for (i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }

    // Check for spam words in message
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strstr(message, spamWords[i])) {
            spamCount++;
        }
    }

    // Output results
    if (spamCount > 0) {
        printf("This message is likely spam.");
    } else {
        printf("This message is not spam.");
    }

    return 0;
}