//FormAI DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <string.h>

// Function to check if a given string contains spam
int isSpam(char* message) {
    // List of common spam words and phrases
    char* spamWords[] = {"win", "prize", "free", "click here", "act now", "limited time"};

    // Loop through each word in the message
    char* token = strtok(message, " ");
    while (token) {
        // Loop through each word in the spamWords array
        for (int i = 0; i < sizeof(spamWords) / sizeof(char*); i++) {
            // If the word in the message matches a spam word, return true
            if (strstr(token, spamWords[i])) {
                return 1;
            }
        }
        // Get the next token in the message
        token = strtok(NULL, " ");
    }
    // If no spam words were found, return false
    return 0;
}

int main() {
    // Welcome message
    printf("Welcome to the Spam Detection System!\n");

    // Get input from the user
    printf("Please enter a message: ");
    char message[100];
    fgets(message, 100, stdin);

    // Check if the message contains spam
    if (isSpam(message)) {
        printf("This message contains spam.\n");
    }
    else {
        printf("This message does not contain spam.\n");
    }

    return 0;
}