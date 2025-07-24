//FormAI DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 5
#define MAX_SPAM_MSG_LENGTH 100

int main(void) {
    int num_spam_words = 0;
    int is_spam = 0;

    char spam_words[MAX_SPAM_WORDS][20] = {"money", "lottery", "free", "win", "prize"};
    char message[MAX_SPAM_MSG_LENGTH];
    char *token;

    printf("Enter your message:\n");
    fgets(message, sizeof(message), stdin);

    token = strtok(message, " ");

    while (token != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                num_spam_words++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (num_spam_words > 0) {
        is_spam = 1;
    }

    if (is_spam) {
        printf("Your message is spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }

    return 0;
}