//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000 // Maximum length of a message
#define MAX_SPAM_WORDS 10   // Maximum number of spam words
#define SPAM_THRESHOLD 0.4  // Minimum ratio of spam words to total words

// Side note: The following functions can be optimized further for scalability

// Function to remove punctuation marks from a message
void removePunctuation(char* msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (ispunct(msg[i])) {
            memmove(&msg[i], &msg[i+1], strlen(msg)-i);
            i--;
        }
    }
}

// Function to convert a message to lowercase
void toLowercase(char* msg) {
    for (int i = 0; i < strlen(msg); i++) {
        msg[i] = tolower(msg[i]);
    }
}

// Function to check if a word is spam
int isSpamWord(char* word, char* spamWords[]) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a message is spam
int isSpam(char* msg, char* spamWords[]) {
    removePunctuation(msg);
    toLowercase(msg);
    char* word = strtok(msg, " ");
    int spamCount = 0;
    int totalCount = 0;
    while (word != NULL) {
        totalCount++;
        if (isSpamWord(word, spamWords)) {
            spamCount++;
        }
        word = strtok(NULL, " ");
    }
    if ((double) spamCount/totalCount >= SPAM_THRESHOLD) {
        return 1;
    }
    return 0;
}

int main() {
    // Example implementation
    char* spamWords[MAX_SPAM_WORDS] = {"free", "prize", "limited", "offer", "credit", "winner", "cash", "now", "urgent", "click"};
    char msg[MAX_MSG_LENGTH];
    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);
    if (isSpam(msg, spamWords)) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }
    return 0;
}