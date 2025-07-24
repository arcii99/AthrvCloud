//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define TRUE 1
#define FALSE 0

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int spamWordsCount = 0;
    char *spamWords[] = {"buy", "cheap", "viagra", "free", "win", "money", "limited", "offer", "click", "now"};
    int i, j, k;
    int found;

    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove newline character from input
    message[strcspn(message, "\n")] = 0;

    // Convert message to lowercase for easier comparison
    for (i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }

    // Check for spam words
    for (i = 0; i < strlen(message); i++) {
        // Reset flag for each iteration
        found = FALSE;
        for (j = i; j < strlen(message); j++) {
            // Check if next word is found
            if (message[j] == ' ' || message[j] == '\0') {
                char currentWord[j - i + 1];
                memcpy(currentWord, &message[i], j - i);
                currentWord[j - i] = '\0';
                // Check if currentWord matches any of the spam words
                for (k = 0; k < sizeof(spamWords) / sizeof(spamWords[0]); k++) {
                    if (strcmp(currentWord, spamWords[k]) == 0) {
                        found = TRUE;
                        spamWordsCount++;
                        break;
                    }
                }
                // Skip to next word to avoid counting multiple times
                i = j + 1;
                break;
            }
        }
    }

    if (spamWordsCount == 0) {
        printf("Message is not spam\n");
    } else {
        printf("Message is spam\n");
    }

    return 0;
}