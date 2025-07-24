//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>
#define MAX_MESSAGE_LENGTH 500

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int spam_count = 0;

    // Loop to keep taking input until the user decides to quit
    while (1) {
        // Taking user input
        printf("Enter a message: ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0; // Removing newline character from input

        // Terminating loop if user enters exit
        if (strcmp(message, "exit") == 0) {
            printf("Ending program...\n");
            break;
        }

        int length = strlen(message);
        int uppercase_count = 0;
        int exclamation_count = 0;
        int digit_count = 0;
        int dollar_count = 0;

        // Counting number of uppercase letters, exclamation marks, digits and '$' symbols in the message
        for (int i = 0; i < length; i++) {
            if (message[i] >= 65 && message[i] <= 90) {
                uppercase_count++;
            }
            if (message[i] == '!') {
                exclamation_count++;
            }
            if (message[i] >= 48 && message[i] <= 57) {
                digit_count++;
            }
            if (message[i] == '$') {
                dollar_count++;
            }
        }

        // Checking if message is spam or not based on number of uppercase letters, exclamation marks, digits and '$' symbols
        if (uppercase_count >= 2 && exclamation_count >= 1 && digit_count >= 2 && dollar_count == 0) {
            printf("Message is not spam.\n\n");
        } else {
            printf("Message is spam!\n\n");
            spam_count++;
        }
    }

    printf("Total number of spam detected: %d\n", spam_count);
    return 0;
}