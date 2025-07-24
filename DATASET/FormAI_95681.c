//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

#define KEYWORD_COUNT 5

// Define the keywords frequently used in spam messages
char *keywords[KEYWORD_COUNT] = {
    "free",
    "money",
    "discount",
    "offer",
    "prize"
};

// Define the count of each keyword
int counts[KEYWORD_COUNT] = {0};

// Check if a given keyword is present in a message
int keyword_present(char *message, char *keyword) {
    return strstr(message, keyword) != NULL;
}

// Count the frequency of each keyword in a message
void count_keywords(char *message) {
    for (int i = 0; i < KEYWORD_COUNT; i++) {
        if (keyword_present(message, keywords[i])) {
            counts[i]++;
        }
    }
}

// Check if a message is spam or not
int is_spam(char *message) {
    // Count the frequency of each keyword in the message
    count_keywords(message);
    // If any keyword appears more than 3 times, the message is considered spam
    for (int i = 0; i < KEYWORD_COUNT; i++) {
        if (counts[i] > 3) {
            return 1; // Spam detected!
        }
    }
    return 0; // Not spam
}

int main() {
    char message[1000];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    if (is_spam(message)) {
        printf("This is a spam message.\n");
    } else {
        printf("This is not a spam message.\n");
    }
    return 0;
}