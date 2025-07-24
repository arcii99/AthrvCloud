//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 200
#define SPAM_WORDS_COUNT 5

char spamWords[SPAM_WORDS_COUNT][20] = {"buy now", "limited time offer", "make money fast", "work from home", "long lost relative"};

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int i, j;
    int spamScore = 0;

    printf("Welcome to the Spam Detector System! Please enter a message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    for (i = 0; i < SPAM_WORDS_COUNT; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            spamScore++;
        }
    }

    if (spamScore > 2) {
        printf("The message you entered has been flagged as SPAM!\n");
    } else {
        printf("The message you entered is NOT spam.\n");
    }

    return 0;
}