//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 1000
#define MAX_SPAM_WORDS 10

char spam_words[MAX_SPAM_WORDS][20] = {"lottery", "free", "trial", "guaranteed", "earn", "cash", "money", "opportunity", "limited", "offer"};

int is_spam(char *msg) {
    char *token;
    char msg_copy[MAX_MSG_SIZE];
    strcpy(msg_copy, msg);

    // Tokenize the message
    token = strtok(msg_copy, " ");

    while (token != NULL) {
        // Compare each token with the spam words
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                return 1; // Found a spam word
            }
        }

        token = strtok(NULL, " ");
    }

    return 0;
}

int main() {
    char msg[MAX_MSG_SIZE];

    printf("Enter a message: ");
    fgets(msg, MAX_MSG_SIZE, stdin);

    if (is_spam(msg)) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}