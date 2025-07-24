//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SPAM_THRESHOLD 10

bool isSpam(char message[]) { // function to check if message is spam
    int len = strlen(message);
    int count_uppercase = 0, count_digits = 0, count_punctuation = 0;

    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (c >= 'A' && c <= 'Z') count_uppercase++; // count uppercase letters
        else if (c >= '0' && c <= '9') count_digits++; // count digits
        else if (c == '!' || c == '?' || c == '.') count_punctuation++; // count common punctuation
    }

    if (count_uppercase >= SPAM_THRESHOLD || count_digits >= SPAM_THRESHOLD || count_punctuation >= SPAM_THRESHOLD) {
        return true;
    }

    return false;
}

int main() {
    printf("Welcome to the Spam Detection System!\n\n");

    char message[200];
    printf("Please enter a message: ");
    fgets(message, sizeof(message), stdin);

    bool is_spam = isSpam(message);

    if (is_spam) {
        printf("\nWARNING: This message appears to be spam!\n\n");
    }
    else {
        printf("\nThis message is safe to send.\n\n");
    }

    return 0;
}