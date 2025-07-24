//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define SPAM_KEYWORDS_COUNT 5

char *spam_keywords[SPAM_KEYWORDS_COUNT] = {"buy", "discount", "sale", "offer", "promotion"};

int is_spam(char *message) {
    int i, j;
    int message_length = strlen(message);

    for(i = 0; i < message_length; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] += 'a' - 'A'; // Change uppercase letters to lowercase
        }
    }

    for(i = 0; i < SPAM_KEYWORDS_COUNT; i++) {
        if(strstr(message, spam_keywords[i]) != NULL) {
            return 1; // Message contains spam keyword
        }
    }

    return 0; // Message is not spam
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int is_spam_flag;

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character from message

    is_spam_flag = is_spam(message);

    if(is_spam_flag) {
        printf("Warning: Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}