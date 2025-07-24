//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_LENGTH 20


int isSpam(char *message, char *spamWords[MAX_SPAM_WORDS], int count) {
    int i, j, k;
    int isFound;

    // Convert message to lowercase
    for (i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }

    // Check if message contains spam words
    for (i = 0; i < count; i++) {  // For each spam word
        for (j = 0; message[j]; j++) {  // For each character in message
            isFound = 1;  // Assume true until proven false
            for (k = 0; spamWords[i][k]; k++) {  // For each character in spam word
                if (message[j+k] != spamWords[i][k]) {
                    isFound = 0;
                    break;
                }
            }
            if (isFound) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    // Define spam words
    char *spamWords[MAX_SPAM_WORDS] = {
        "cash",
        "prize",
        "winner",
        "offer",
        "free",
        "limited time",
        "act now",
        "buy",
        "discount",
        "sale"
    };
    int count = 10;

    printf("Welcome to the Spam Detector!\n\n");
    printf("Enter a message to check for spam (max length %d): ", MAX_SPAM_LENGTH);
    char message[MAX_SPAM_LENGTH];
    fgets(message, MAX_SPAM_LENGTH, stdin);

    if (isSpam(message, spamWords, count)) {
        printf("\nThis message contains spam!\n");
    } else {
        printf("\nThis message is clean!\n");
    }

    return 0;
}