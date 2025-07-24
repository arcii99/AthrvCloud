//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define SPAM_THRESHOLD 5 // Maximum number of repeated messages before considering it as spam

bool check_spam(char messages[][100], int messages_len, char new_message[]) {
    int count = 0;
    for (int i = 0; i < messages_len; i++) {
        if (strcmp(messages[i], new_message) == 0) { // Compare if the message is equal to any previous message
            count++;
        }
        if (count >= SPAM_THRESHOLD) { // Check if the number of repeated messages exceeds the threshold
            return true;
        }
    }
    return false;
}

int main() {
    char messages[100][100] = {}; // Array to store messages
    int messages_len = 0; // Counter for number of messages
    char new_message[100]; // Variable to store new message
    
    while (true) { // Loop to continuously ask for new messages
        printf("Enter a message: ");
        scanf(" %[^\n]", new_message);
        
        if (check_spam(messages, messages_len, new_message)) { // Check if the message is spam
            printf("This message is spam.\n");
        } else {
            printf("This message is not spam.\n");
            strcpy(messages[messages_len], new_message); // Store message in the array
            messages_len++; // Increment the counter for number of messages
        }
    }
    
    return 0;
}