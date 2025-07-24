//FormAI DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define spam detection parameters (can be easily configured)
#define MIN_MESSAGE_LENGTH 10
#define MAX_MESSAGE_LENGTH 100
#define MIN_SPAM_WORD_LENGTH 4
#define MAX_SPAM_WORD_LENGTH 10
#define MAX_SPAM_COUNT 2

// Function to check if a string contains specific spam words
int check_spam(char* message) {
    char spam_words[][MAX_SPAM_WORD_LENGTH] = {"viagra", "lottery", "free money", "nigeria"};

    int spam_count = 0;
    char* word = strtok(message, " ");

    while (word != NULL) {
        // Check if word matches any spam words
        for (int i = 0; i < sizeof(spam_words)/sizeof(spam_words[0]); i++) {
            if (strstr(word, spam_words[i]) != NULL) {
                spam_count++;
                break;
            }
        }

        word = strtok(NULL, " ");
    }

    return spam_count;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];

    // Get user input
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove trailing newline character from input
    message[strcspn(message, "\n")] = 0;

    // Check message length
    if (strlen(message) < MIN_MESSAGE_LENGTH || strlen(message) > MAX_MESSAGE_LENGTH) {
        printf("Message length invalid.\n");
        return 0;
    }

    // Check for spam words
    if (check_spam(message) > MAX_SPAM_COUNT) {
        printf("Message detected as spam.\n");
        return 0;
    }

    printf("Message is valid.\n");

    return 0;
}