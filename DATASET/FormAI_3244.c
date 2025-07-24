//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Function that determines if a given string contains spam words
int isSpam(char* message) {
    char* spamWords[] = {"buy", "free", "click here", "limited time offer", "exclusive deal"};
    int numWords = 5; // Number of spam words in the array

    for (int i = 0; i < numWords; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return 1; // If a spam word is found, return true (1)
        }
    }

    return 0; // If no spam words are found, return false (0)
}

int main() {
    char message[256]; // Assume message is less than 256 characters
    printf("Enter message: ");
    fgets(message, 256, stdin); // Read in user input

    // Remove trailing newline character from fgets
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    if (isSpam(message)) {
        printf("SPAM DETECTED!\n");
    } else {
        printf("Clean message.\n");
    }

    return 0;
}