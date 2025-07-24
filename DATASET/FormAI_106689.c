//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // maximum number of spam words to check against
#define MAX_SPAM_LENGTH 20 // maximum length of spam words
#define MAX_MESSAGE_LENGTH 200 // maximum length of message to check

char spamList[MAX_SPAM_WORDS][MAX_SPAM_LENGTH] = {"buy", "cheap", "free", "money", "offer", "viagra", "win", "winner", "work from home", "xxx"}; // list of known spam words

int isSpam(char *message) {
    char *token;
    int spamCount = 0;

    char copyMessage[MAX_MESSAGE_LENGTH];
    strcpy(copyMessage, message);

    // split the message into words and check for spam words
    token = strtok(copyMessage, " ");
    while (token != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spamList[i]) == 0) {
                spamCount++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (spamCount > 1) {
        return 1; // if two or more spam words are found in the message, it is considered spam
    } else {
        return 0;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message to check for spam: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin); // get user input

    // convert user input to lowercase for case-insensitive spam checking
    for (int i = 0; i < strlen(message); i++) {
        message[i] = tolower(message[i]);
    }

    if (isSpam(message)) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}