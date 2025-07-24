//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 5

int is_spam(char *message) {
    char *spam_words[MAX_SPAM_WORDS] = {"buy", "discount", "cheap", "money", "promotion"};
    int i, j, word_len;
    char *word_start, *word_end;

    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ' || message[i] == '\n' || message[i] == '\r' || message[i] == '\0') {
            if (word_start != NULL) {
                word_end = &message[i];
                word_len = word_end - word_start;

                for (j = 0; j < MAX_SPAM_WORDS; j++) {
                    if (strncmp(spam_words[j], word_start, word_len) == 0) {
                        return 1;
                    }
                }

                word_start = NULL;
            }
        } else {
            if (word_start == NULL) {
                word_start = &message[i];
            }
        }
    }

    return 0;
}

int main() {
    char *message = "Get a discount on your purchase today!";
    if (is_spam(message)) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }
    return 0;
}