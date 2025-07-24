//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_MESSAGE_LENGTH 100

//initialize an array of spam words
char spamWords[MAX_SPAM_WORDS][10] = {"money", "win", "prize", "free", "click", "offer", "discount", "cash", "urgent", "limited"};

//function to check if a word is spam
bool is_spam_word(char word[], int len) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strncmp(word, spamWords[i], len) == 0) {
            return true;
        }
    }
    return false;
}

//function to check if a message is spam
bool is_spam_message(char* message) {
    char* p = strtok(message, " ");
    while (p != NULL) {
        if (is_spam_word(p, strlen(p))) {
            return true;
        }
        p = strtok(NULL, " ");
    }
    return false;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    if (is_spam_message(message)) {
        printf("This message is spam.");
    } else {
        printf("This message is not spam.");
    }
    return 0;
}