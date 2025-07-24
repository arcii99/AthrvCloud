//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
// Welcome to the Spam Detection System!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Declare and initialize a list of spam words/phrases to look out for
char *spamWords[] = {"make money fast", "earn money quickly", "lose weight fast", "amazing diet pill", "hot singles in your area"};

// Function to determine if a message is spam or not
bool isSpam(char *message) {
    // Check if message contains any of the spam words/phrases
    for (int i = 0; i < sizeof(spamWords)/sizeof(spamWords[0]); i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return true;    // Message is spam
        }
    }
    return false;   // Message is not spam
}

// Main program function
int main() {
    char message[256];  // Declare a character array to hold the message

    printf("Welcome to the Spam Detection System!\n\n");

    while (true) {
        printf("Enter your message (or type \"exit\" to quit): ");
        fgets(message, sizeof(message), stdin);   // Read in the message from the user

        if (strcmp(message, "exit\n") == 0) {
            break;  // Exit the program loop
        }

        if (isSpam(message)) {
            printf("SPAM DETECTED!\n");  // Alert the user that the message is spam
        } else {
            printf("Message passed spam filter.\n"); // Let the user know that their message is okay
        }
    }

    printf("\nThank you for using the Spam Detection System!\n");
    return 0;   // Exit the program
}