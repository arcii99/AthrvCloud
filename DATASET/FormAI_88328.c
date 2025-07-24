//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000 // Maximum message length
#define MAX_SPAM_WORDS 10 // Maximum number of spam words allowed

// Array of known spam words
char spam_words[MAX_SPAM_WORDS][20] = {"free", "money", "click here", "limited time", "offer", "cash", "make money", "guaranteed", "earn", "cash now"};

// Function to check if a word is a spam word
int is_spam(char *word) {
    int i;
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a message is spam
int is_spam_msg(char *msg) {
    char word[20];
    int i = 0, j = 0, spam_count = 0;
    while (msg[i] != '\0') {
        if (msg[i] == ' ' || msg[i] == '\n' || msg[i] == '\t' || msg[i] == '\r') {
            word[j] = '\0';
            if (is_spam(word)) {
                spam_count++;
            }
            j = 0;
        }
        else {
            word[j] = msg[i];
            j++;
        }
        i++;
    }
    word[j] = '\0';
    if (is_spam(word)) {
        spam_count++;
    }
    if (spam_count > 0) {
        return 1;
    }
    return 0;
}

int main() {
    char msg[MAX_MSG_LENGTH];
    printf("Enter a message to check for spam: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);
    if (is_spam_msg(msg)) {
        printf("This message is spam.\n");
    }
    else {
        printf("This message is not spam.\n");
    }
    return 0;
}