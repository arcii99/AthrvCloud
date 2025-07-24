//FormAI DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Define the maximum message length and the spam threshold
#define MAX_MESSAGE_LEN 500
#define SPAM_THRESHOLD 0.5

// Function to check if a message contains spam keywords
int contains_spam(char* message) {
    int count = 0;
    char* spam_keywords[] = {"buy now", "limited time offer", "free", "money back guarantee", "click here"};

    for (int i = 0; i < sizeof(spam_keywords)/sizeof(spam_keywords[0]); i++) {
        if (strstr(message, spam_keywords[i])) {
            count++;
        }
    }

    if ((double)count / sizeof(spam_keywords)/sizeof(spam_keywords[0]) > SPAM_THRESHOLD) {
        return 1; // contains spam
    } else {
        return 0; // does not contain spam
    }
}

int main() {
    char message[MAX_MESSAGE_LEN];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);

    if (contains_spam(message)) {
        printf("Warning: This message contains spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}