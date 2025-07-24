//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of a message
#define MAX_MSG_LENGTH 100

int main() {
    char message[MAX_MSG_LENGTH];
    int message_length, i, is_spam = 0;

    // Get the message from the user
    printf("Please enter your message:\n");
    fgets(message, MAX_MSG_LENGTH, stdin);

    // Remove newline character from the message
    message_length = strlen(message);
    if (message[message_length - 1] == '\n') {
        message[message_length - 1] = '\0';
    }

    // Check the message for spam keywords
    char *spam_keywords[] = {"buy", "discount", "sale", "offer", "money"};
    int num_spam_keywords = 5;
    for (i = 0; i < num_spam_keywords; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            is_spam = 1;
            break;
        }
    }

    // Print the result based on whether the message is spam or not
    if (is_spam) {
        printf("This message appears to be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}