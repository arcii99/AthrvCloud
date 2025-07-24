//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 3  // a message will be marked as spam if it contains at least 3 spam words

int main() {
    char message[100];
    int spamCount = 0;
    char *spamWords[5] = {"buy", "free", "discount", "limited", "offer"};

    printf("Enter your message:\n");
    fgets(message, 100, stdin);

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] += 32;  // convert uppercase letters to lowercase letters
        }
    }

    char *word = strtok(message, " ");  // split the message into words
    
    while (word != NULL) {
        for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
            if (strcmp(word, spamWords[i]) == 0) {
                spamCount++;
                break;  // stop checking once we find a spam word
            }
        }
        word = strtok(NULL, " ");
    }

    if (spamCount >= SPAM_THRESHOLD) {
        printf("WARNING: This message may contain spam.\n");
    } else {
        printf("This message looks clean.\n");
    }

    return 0;
}