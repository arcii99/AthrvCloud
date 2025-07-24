//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_MSG_LEN 100

const char *SPAM_WORDS[MAX_SPAM_WORDS] = {"win", "lottery", "prize", "money", "bank account"};

int is_spam(char *msg) {
    char *word;
    int count = 0;
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        word = SPAM_WORDS[i];
        if (strstr(msg, word)) {
            count++;
        }
    }
    return count >= 2;
}

int main() {
    char msg[MAX_SPAM_MSG_LEN];
    printf("Enter a message: ");
    fgets(msg, MAX_SPAM_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = 0;
    if (is_spam(msg)) {
        printf("This message is SPAM!\n");
        // add code here to block or report the message...
    } else {
        printf("This message is not SPAM.\n");
        // add code here to validate and process the message...
    }
    return 0;
}