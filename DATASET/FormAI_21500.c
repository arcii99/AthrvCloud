//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <string.h>

// define constants
#define MAX_SPAM_WORDS 10
#define MAX_MESSAGE_LENGTH 1000

// function to check if word is in list of spam words
int isSpam(char* word, char spamWords[MAX_SPAM_WORDS][20], int numSpamWords) {
    int i;
    for (i = 0; i < numSpamWords; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1; // word is in spam list
        }
    }
    return 0; // word is not in spam list
}

// function to check if message is spam
int isMessageSpam(char* message, char spamWords[MAX_SPAM_WORDS][20], int numSpamWords) {
    int i, wordCount = 0;
    char word[20], c;
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\0') {
            // end of word, check if word is spam
            word[wordCount] = '\0';
            if (isSpam(word, spamWords, numSpamWords)) {
                return 1; // message is spam
            }
            wordCount = 0;
        } else {
            // add character to current word
            word[wordCount] = c;
            wordCount++;
        }
    }
    return 0; // message is not spam
}

// main function
int main() {
    char spamWords[MAX_SPAM_WORDS][20] = {"viagra", "lottery", "free", "money", "inheritance"};
    int numSpamWords = 5;
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    if (isMessageSpam(message, spamWords, numSpamWords)) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    return 0;
}