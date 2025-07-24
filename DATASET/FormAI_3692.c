//FormAI DATASET v1.0 Category: Spam Detection System ; Style: random
// This is a unique C Spam Detection System example program
#include <stdio.h>
#include <string.h>

#define MAX_MSG 128
#define SPAM_THRESHOLD 3

int main() {
    char message[MAX_MSG];
    int spam_count = 0;

    printf("Enter message: ");
    gets(message);

    // Check for keywords associated with spam
    if (strstr(message, "money") || strstr(message, "free") ||
        strstr(message, "lottery") || strstr(message, "investment")) {
        spam_count++;
    }

    // Check for excessive use of punctuation
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '!' || message[i] == '?' || message[i] == '.') {
            spam_count++;
        }
    }

    // Check for all caps messages
    int upper_case_count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            upper_case_count++;
        }
    }
    if (upper_case_count >= strlen(message) / 2) {
        spam_count++;
    }

    // Print final result
    if (spam_count >= SPAM_THRESHOLD) {
        printf("Spam detected!");
    } else {
        printf("Message is not spam.");
    }

    return 0;
}