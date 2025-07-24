//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SPAM_WORDS 20
#define MAX_MSG_LENGTH 200

// Spam words that will trigger the spam detector
char spamWords[MAX_SPAM_WORDS][20] = {"buy", "now", "free", "money", "offer", "limited", "opportunity", "click", "here", "guarantee", "prize", "discount", "cash", "earn", "extra", "income", "investment", "refund", "save", "unlimited"};

// Function to check if a word is a spam word
int isSpamWord(char *word) {
    int i;
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a message is spam
int isSpamMessage(char *msg) {
    char *word;
    int count = 0;

    // Tokenize message into separate words
    word = strtok(msg, " ");
    while (word != NULL) {
        if (isSpamWord(word)) {
            count++;
        }
        word = strtok(NULL, " ");
    }

    // If more than 2 spam words, message is considered spam
    if (count >= 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char message[MAX_MSG_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_MSG_LENGTH, stdin);

    if (isSpamMessage(message)) {
        printf("This message is spam.\n");
    }
    else {
        printf("This message is not spam.\n");
    }

    return 0;
}