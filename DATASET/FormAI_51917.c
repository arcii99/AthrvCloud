//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given message contains spam words
bool contains_spam(char *message) {
    char *spam_words[] = {"buy", "sale", "discount", "free", "money"};
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            return true;
        }
    }
    return false;
}

// Main function to test the spam detection system
int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline character
    if (contains_spam(message)) {
        printf("This message contains spam words.\n");
    } else {
        printf("This message does not contain spam words.\n");
    }
    return 0;
}