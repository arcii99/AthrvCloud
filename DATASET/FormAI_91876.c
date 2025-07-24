//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
// The Case of the Spam Messages
// A C program to detect spam messages

#include <stdio.h>
#include <string.h>

int main() {

    // Declare variables for user input and spam detection
    char message[200];
    int i, word_count = 0, spam_count = 0;

    printf("Welcome to the Spam Detection System! \n");

    // Ask for user input
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    // Count the number of words in the message
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            word_count++;
        }
    }

    // Check for common spam words
    char *spam[] = {"free", "win", "money", "click", "limited time offer"};

    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            char current_word[20];
            int j, word_length = 0;
            for (j = i + 1; j < strlen(message); j++) {
                if (message[j] == ' ') {
                    break;
                }
                current_word[word_length++] = message[j];
            }
            current_word[word_length] = '\0';

            // Check if current word is spam
            for (j = 0; j < sizeof(spam)/sizeof(*spam); j++) {
                if (strcmp(current_word, spam[j]) == 0) {
                    spam_count++;
                    break;
                }
            }
        }
    }

    // Determine message status
    if (word_count == 0) {
        printf("Error: No message entered. \n");
    } else if (spam_count > 0) {
        printf("This message appears to be spam. \n");
    } else {
        printf("This message is not spam. \n");
    }

    printf("Thank you for using the Spam Detection System. \n");

    return 0;
}