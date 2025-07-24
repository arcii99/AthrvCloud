//FormAI DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <string.h>

// Function to check if a message is spam or not
int isSpam(char message[]) {
    int count = 0; // Counter to count the number of spam words

    char *spamWords[] = {"free", "cash", "limited time offer", "winner", "gift card"}; // Array of spam words

    char *token = strtok(message, " "); // Get the first word of the message

    while (token != NULL) { // Loop through all words of the message
        for (int i = 0; i < 5; i++) { // Loop through all spam words
            if (strcmp(token, spamWords[i]) == 0) { // If the current word is equal to a spam word
                count++; // Increment the spam counter
            }
        }
        token = strtok(NULL, " "); // Get the next word of the message
    }

    if (count >= 2) { // If there are at least two spam words in the message
        return 1; // The message is spam
    } else {
        return 0; // The message is not spam
    }
}

int main() {
    char message[100]; // Maximum length of a message is 100 characters

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    if (isSpam(message)) {
        printf("The message is spam!\n");
    } else {
        printf("The message is not spam!\n");
    }

    return 0;
}