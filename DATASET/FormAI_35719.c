//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_MSG_SIZE 1024
#define SPAM_KEYWORDS_SIZE 5

const char* SPAM_KEYWORDS[] = {"buy", "cheap", "discount", "free", "win"};

int is_spam(const char* message) {
    int i;
    char lowercase[MAX_MSG_SIZE];
    
    // Convert message to lowercase
    for (i = 0; i < strlen(message); i++) {
        lowercase[i] = tolower(message[i]);
    }
    lowercase[i] = '\0';
    
    // Check for spam keywords
    for (i = 0; i < SPAM_KEYWORDS_SIZE; i++) {
        if (strstr(lowercase, SPAM_KEYWORDS[i]) != NULL) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char message[MAX_MSG_SIZE];
    
    printf("Enter a message: ");
    fgets(message, MAX_MSG_SIZE, stdin);
    
    if (is_spam(message)) {
        printf("Spam detected!\n");
    } else {
        printf("Message is not spam.\n");
    }
    
    return 0;
}