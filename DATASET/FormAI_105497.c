//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

// Define a macro to represent the maximum length of a message
#define MAX_MESSAGE_LENGTH 1000

// Define a function to check if a message is spam
int is_spam(char message[]) {
    // Define a list of spam words and phrases
    char spam_words[][20] = {"buy", "sell", "click here", "discount", "money back guarantee", "limited time offer"};
    
    // Loop through each spam word or phrase
    for (int i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
        // Check if the spam word or phrase appears in the message
        if (strstr(message, spam_words[i]) != NULL) {
            // The message is spam - return true
            return 1;
        }
    }
    
    // The message is not spam - return false
    return 0;
}

int main() {
    // Define a variable to store the user's message
    char message[MAX_MESSAGE_LENGTH];
    
    // Prompt the user to enter a message
    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    // Remove the newline character at the end of the message
    message[strcspn(message, "\n")] = '\0';
    
    // Check if the message is spam
    if (is_spam(message)) {
        printf("Warning: This message appears to be spam!\n");
    } else {
        printf("This message appears to be legitimate.\n");
    }
    
    // Exit the program
    return 0;
}