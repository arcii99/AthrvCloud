//FormAI DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Function to check if a string contains spam keywords
int has_spam(char *message) {
    char *spam_words[] = {"buy", "cheap", "discount", "free", "offer", "sale"};
    int num_words = sizeof(spam_words) / sizeof(spam_words[0]);
    
    for (int i = 0; i < num_words; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[100];
    
    // Prompt user to enter a message
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    
    // Remove the newline character at the end of the message
    message[strcspn(message, "\n")] = 0;
    
    // Check if the message contains spam keywords
    if (has_spam(message)) {
        printf("Your message contains spam.\n");
    } else {
        printf("Your message is clean.\n");
    }
    
    return 0;
}