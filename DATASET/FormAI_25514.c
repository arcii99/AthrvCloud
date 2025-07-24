//FormAI DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a message contains spam words
int contains_spam(char *message) {
    char spam_words[5][20] = {"buy", "discount", "free", "limited", "offer"};

    // Convert message and spam words to lowercase for case-insensitive comparison
    char lowered_message[100];
    for (int i = 0; message[i]; i++) {
        lowered_message[i] = tolower(message[i]);
    }
    char lowered_spam_words[5][20];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; spam_words[i][j]; j++) {
            lowered_spam_words[i][j] = tolower(spam_words[i][j]);
        }
    }

    // Check if message contains spam words
    for (int i = 0; i < 5; i++) {
        if (strstr(lowered_message, lowered_spam_words[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[1000];
    printf("Enter message: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline character

    if (contains_spam(message)) {
        printf("This message contains spam.\n");
    } else {
        printf("This message does not contain spam.\n");
    }

    return 0;
}