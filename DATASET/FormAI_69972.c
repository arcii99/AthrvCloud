//FormAI DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to detect spam in a given message
int detect_spam(char *message) {
    int i, count = 0;
    char *word;

    // List of spam words
    char *spam_words[] = {"buy", "now", "offer", "free", "subscribe"};

    // Parse the message word by word
    word = strtok(message, " ");

    while (word != NULL) {
        // Check if the word is one of the spam words
        for (i = 0; i < 5; i++) {
            if (strcmp(word, spam_words[i]) == 0) {
                count++;
                break;
            }
        }

        // Check if more than two spam words have been found
        if (count > 2) {
            return 1;
        }

        word = strtok(NULL, " ");
    }

    return 0;
}

int main() {
    char message[1000];

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    // Check if message is spam
    if (detect_spam(message) == 1) {
        printf("Warning! Your message may contain spam.\n");
    } else {
        printf("Your message is safe to send.\n");
    }

    return 0;
}