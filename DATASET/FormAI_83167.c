//FormAI DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 200
#define MAX_SPAM_WORDS 10
#define SPAM_PROB_THRESH 0.75

int main() {
    // Initialize variables
    char message[MAX_MSG_LEN];
    int num_spam_words = 0;
    char spam_words[MAX_SPAM_WORDS][20] = {"free", "money", "earn", "cash", "offer", "limited", "sale", "discount", "buy", "now"};
    float spam_prob = 0.0;

    // Get user input
    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    // Remove newline character from input
    message[strcspn(message, "\n")] = 0;

    // Check message for spam words
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            num_spam_words++;
        }
    }

    // Calculate spam probability
    spam_prob = (float) num_spam_words / MAX_SPAM_WORDS;

    // Determine if message is spam
    if (spam_prob >= SPAM_PROB_THRESH) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}