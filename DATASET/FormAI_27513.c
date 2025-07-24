//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum character length of a message
#define MAX_MESSAGE_LENGTH 100

// Define the maximum number of messages that can be stored in the system
#define MAX_MESSAGE_COUNT 100

// Define the maximum number of repeated messages allowed before triggering a spam alert
#define MAX_REPETITION_COUNT 3

// Define the message struct
typedef struct {
    char content[MAX_MESSAGE_LENGTH];
    int repeat_count;
} Message;

int main() {
    // Create an array of message structs
    Message messages[MAX_MESSAGE_COUNT];

    // Define variables to keep track of the number of messages and the spam alert status
    int message_count = 0;
    int spam_alert = 0;

    // Start the message loop
    while (1) {
        // Get user input
        char input[MAX_MESSAGE_LENGTH];
        printf("Enter a message: ");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);

        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Check if message is a repeat
        int repeat_index = -1;
        for (int i = 0; i < message_count; i++) {
            if (strcmp(input, messages[i].content) == 0) {
                repeat_index = i;
                break;
            }
        }

        // If message is a repeat, increment repeat count and check for spam alert
        if (repeat_index != -1) {
            messages[repeat_index].repeat_count++;

            if (messages[repeat_index].repeat_count >= MAX_REPETITION_COUNT) {
                printf("SPAM ALERT: '%s' has been repeated %d times!\n", messages[repeat_index].content, messages[repeat_index].repeat_count);
                spam_alert = 1;
            }
        }
        // If message is not a repeat, add it to the message array
        else {
            messages[message_count].repeat_count = 1;
            strcpy(messages[message_count].content, input);
            message_count++;
        }

        // Check for maximum message count and spam alert status
        if (message_count >= MAX_MESSAGE_COUNT) {
            printf("Maximum message count reached!\n");
            break;
        }

        if (spam_alert) {
            printf("You are spamming the system! Exiting.\n");
            break;
        }
    }

    return 0;
}