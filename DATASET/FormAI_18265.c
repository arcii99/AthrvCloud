//FormAI DATASET v1.0 Category: Spam Detection System ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 1000
#define MAX_LENGTH 200

// Constants for spam detection
#define MAX_FREQUENCY 5
#define MIN_LENGTH 10

// Function to check if a message is spam
int is_spam(char* message, char** messages, int n) {
    int count = 0;
    int length = strlen(message);

    // Check if the message is too short
    if (length < MIN_LENGTH) {
        return 0;
    }

    // Check if the message contains too many repeating words
    char* word = strtok(message, " ");
    while (word != NULL) {
        int frequency = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(word, messages[i]) == 0) {
                frequency++;
            }
        }
        if (frequency >= MAX_FREQUENCY) {
            return 1;
        }
        word = strtok(NULL, " ");
    }

    // Check if the message is too similar to previous messages
    for (int i = 0; i < n; i++) {
        int similarity = 0;
        int message_length = strlen(messages[i]);
        for (int j = 0; j < length; j++) {
            if (message[j] == messages[i][j % message_length]) {
                similarity++;
            }
        }
        if (similarity >= length / 2) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char* messages[MAX_MESSAGES];
    int n = 0; // Number of messages
    char message[MAX_LENGTH];

    while (1) {
        printf("> ");
        fgets(message, MAX_LENGTH, stdin);

        if (is_spam(message, messages, n)) {
            printf("SPAM\n");
        } else {
            printf("NOT SPAM\n");
            messages[n] = strdup(message);
            n++;
        }
    }

    return 0;
}