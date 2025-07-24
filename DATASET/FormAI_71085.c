//FormAI DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 5

const char *SPAM_WORDS[] = {
    "buy",
    "free",
    "offer",
    "discount",
    "cash"
};

int is_spam(char *message) {
    // Convert message to lowercase
    for (int i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }
    
    // Check if message contains spam words
    char *token = strtok(message, " ");
    while (token != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strstr(token, SPAM_WORDS[i]) != NULL) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    
    return 0;
}

int main() {
    char message[256];
    printf("Welcome to the Spam Detection System!\n");
    
    while (1) {
        printf("Enter your message: ");
        fgets(message, 256, stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove newline character
        
        if (is_spam(message)) {
            printf("WARNING: This message contains spam!\n");
        } else {
            printf("Success! This message is not spam.\n");
        }
    }
    
    return 0;
}