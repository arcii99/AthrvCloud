//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 5
#define MAX_MESSAGE_LENGTH 100

char *spam_words[MAX_SPAM_WORDS] = {"lottery", "Nigerian prince", "enlarge", "money back guarantee", "click now"};

int is_spam(char *message) {
    int i;

    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    if (is_spam(message)) {
        printf("Sorry, your message contains spam words.");
    } else {
        printf("Thank you for your message!");
    }

    return 0;
}