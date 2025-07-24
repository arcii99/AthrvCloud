//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is our spam detection function
int detect_spam(char *message)
{
    // Here, we check if the message contains the word "spam"
    char *result = strstr(message, "spam");
    
    // If the word "spam" is found, we return 1 (true)
    if (result != NULL) {
        return 1;
    }
    
    // Otherwise, we return 0 (false)
    return 0;
}

int main()
{
    char message[1000];
    
    printf("Hello! Welcome to our cheerful spam detection system.\n");
    printf("Please enter a message to check for spam:\n");
    
    // Get input from the user
    fgets(message, 1000, stdin);
    
    // Remove the newline character from the input
    message[strcspn(message, "\n")] = 0;
    
    // Check if the message contains spam
    int is_spam = detect_spam(message);
    
    if (is_spam) {
        printf("Oh no! Your message contains spam. Please try again with a different message.\n");
    } else {
        printf("Congratulations! Your message is spam-free. You may proceed.\n");
    }
    
    return 0;
}