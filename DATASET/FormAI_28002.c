//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters allowed in a message
#define MAX_MSG_LENGTH 1000

// Define the number of messages to scan for spam
#define NUM_MSGS 10

bool is_spam_detected(char *msg) {
    // Check if the message contains any spam keywords
    if (strstr(msg, "lottery") != NULL) {
        return true;
    } else if (strstr(msg, "Nigerian prince") != NULL) {
        return true;
    } else if (strstr(msg, "enlargement") != NULL) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Create an array to store the messages
    char msgs[NUM_MSGS][MAX_MSG_LENGTH];

    // Get messages from user input and store them in the array
    printf("Please enter %d messages to scan for spam:\n", NUM_MSGS);
    for (int i = 0; i < NUM_MSGS; i++) {
        printf("Message %d: ", i + 1);
        fgets(msgs[i], MAX_MSG_LENGTH, stdin);
    }

    // Scan each message for spam and output the results
    for (int i = 0; i < NUM_MSGS; i++) {
        if (is_spam_detected(msgs[i])) {
            printf("Message %d contains spam!\n", i + 1);
        } else {
            printf("Message %d is clean.\n", i + 1);
        }
    }

    return 0;
}