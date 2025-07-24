//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 500 // Maximum message length

int is_spam(char[], char[][MAX_MSG_LENGTH], int); // Function declaration

int main() {
    char messages[][MAX_MSG_LENGTH] = {"Buy now and get 50% off!", "Get rich quick scheme!", "Lose weight fast!", "Congratulations, you've won a free iPad!", "Enlarge your manhood!", "Click here for free money!", "Make money from home!"}; // Array of spam messages
    int num_spam_messages = sizeof(messages) / sizeof(messages[0]); // Number of spam messages
    char input_message[MAX_MSG_LENGTH]; // User input message
    printf("Enter a message:\n");
    fgets(input_message, MAX_MSG_LENGTH, stdin); // Read user input message
    input_message[strcspn(input_message, "\n")] = 0; // Remove newline character
    if (is_spam(input_message, messages, num_spam_messages)) {
        printf("Your message is spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }
    return 0;
}

int is_spam(char message[], char messages[][MAX_MSG_LENGTH], int num_messages) {
    int i, j, k, msg_length, match_count;
    msg_length = strlen(message);
    for (i = 0; i < num_messages; i++) {
        match_count = 0;
        for (j = 0; j < strlen(messages[i]); j++) {
            for (k = 0; k < msg_length; k++) {
                if (toupper(messages[i][j]) == toupper(message[k])) { // Convert characters to uppercase before comparing
                    match_count++;
                    break; // Move to next character in spam message
                }
            }
            if (j == strlen(messages[i]) - 1 && match_count >= strlen(messages[i]) * 0.7) { // Check if message contains 70% of the spam message
                return 1; // Message is spam
            }
        }
    }
    return 0; // Message is not spam
}