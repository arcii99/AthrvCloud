//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
/*
 * C Spam Detection System
 *
 * Author: Linus Torvalds <linus@kernel.org>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000
#define MAX_SPAM_WORDS 50

char spamWords[MAX_SPAM_WORDS][MAX_MSG_LEN]; // An array to store spam words
int numSpamWords = 0; // Number of spam words in the array

// A function to add a new spam word to the array
void addSpamWord(char word[MAX_MSG_LEN]) {
    if (numSpamWords >= MAX_SPAM_WORDS) {
        printf("Error: Too many spam words!\n");
        return;
    }
    
    strcpy(spamWords[numSpamWords], word);
    numSpamWords++;
}

// A function to check if a message contains any spam words
int isSpam(char msg[MAX_MSG_LEN]) {
    char *word;
    int i, isSpam = 0;
    
    // Tokenize message and check if each word is a spam word
    word = strtok(msg, " ,.!?");
    while (word != NULL) {
        for (i = 0; i < numSpamWords; i++) {
            if (strcmp(spamWords[i], word) == 0) {
                isSpam = 1;
                break;
            }
        }
        if (isSpam) {
            break;
        }
        word = strtok(NULL, " ,.!?");
    }
    return isSpam;
}

int main() {
    char msg[MAX_MSG_LEN];
    int i;
    
    printf("== C Spam Detection System ==\n\n");
    
    // Prompt user to enter spam words
    printf("Enter up to %d spam words, one per line:\n", MAX_SPAM_WORDS);
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        fgets(spamWords[i], MAX_MSG_LEN, stdin);
        if (strcmp(spamWords[i], "\n") == 0) {
            break;
        }
        spamWords[i][strcspn(spamWords[i], "\n")] = 0; // Remove newline character
        numSpamWords++;
    }
    printf("%d spam words added.\n\n", numSpamWords);
    
    // Prompt user to enter messages to check for spam
    while (1) {
        printf("Enter a message to check for spam (or type 'exit' to quit):\n");
        fgets(msg, MAX_MSG_LEN, stdin);
        if (strcmp(msg, "exit\n") == 0) {
            break;
        }
        if (isSpam(msg)) {
            printf("SPAM detected!\n\n");
        } else {
            printf("Message is NOT spam.\n\n");
        }
    }
    
    return 0;
}