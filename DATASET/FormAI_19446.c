//FormAI DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_WORD_LENGTH 20
#define MAX_MESSAGE_LENGTH 1000

char spam_words[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {"buy", "sale", "discount", "money", "offer", "free", "cash", "wealth", "investment", "opportunity"};

int check_spam(char* message) {
    char* word = strtok(message, " ");
    int count_spam = 0;
    while (word != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(spam_words[i], word) == 0) {
                count_spam++;
            }
        }
        word = strtok(NULL, " ");
    }
    return count_spam;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    int num_spam = check_spam(message);

    if (num_spam > 0) {
        printf("Warning: This message contains %d potential spam word(s).\n", num_spam);
    } else {
        printf("This is not spam.\n");
    }

    return 0;
}