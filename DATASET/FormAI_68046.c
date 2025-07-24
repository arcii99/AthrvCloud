//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1024 // Maximum message length

// List of words that are commonly found in spam messages
const char *spam_keywords[] = {
    "buy",
    "free",
    "click",
    "discount",
    "offer",
    "limited time",
    "act now",
    "earn money",
    "make money",
    "guaranteed",
    "cash",
    "prize",
    "winner",
    "opportunity",
    "investment",
    "profits",
    "credit",
    "mortgage",
    "refinance",
    "viagra",
    "cialis",
    "weight loss",
    "diet",
    "online pharmacy",
    "enlarge",
    "lose weight",
    "lowest price",
    "lowest rates",
    "earn extra cash",
    "mlm",
    "multi-level marketing"
};

// Returns true if the given word is found in the spam_keywords array
bool is_spam_keyword(char *word) {
    for (int i = 0; i < sizeof(spam_keywords) / sizeof(char*); i++) {
        if (strcasecmp(spam_keywords[i], word) == 0) {
            return true;
        }
    }
    return false;
}

// Returns true if the given message is classified as spam
bool is_spam(char *message) {
    char *word = strtok(message, " ");
    while (word != NULL) {
        if (is_spam_keyword(word)) {
            return true;
        }
        word = strtok(NULL, " ");
    }
    return false;
}

int main() {
    char message[MAX_MSG_LENGTH];
    printf("Enter a message to check for spam: ");
    fgets(message, MAX_MSG_LENGTH, stdin);

    if (is_spam(message)) {
        printf("This message is classified as spam.\n");
    } else {
        printf("This message is NOT classified as spam.\n");
    }
    
    return 0;
}