//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int i, j, found_spam;

    printf("Enter your message: ");
    fgets(message, 1000, stdin);
    
    // Check for spam keywords
    char spam_keywords[5][20] = {"buy", "viagra", "free", "money", "win"};
    found_spam = 0;
    
    for (i = 0; i < 5; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            found_spam = 1;
            break;
        }
    }
    
    // Shape shift the message
    if (found_spam) {
        for (j = 0; j < strlen(message); j++) {
            if (message[j] >= 'a' && message[j] <= 'z') {
                message[j] -= 32;
            } else if (message[j] >= 'A' && message[j] <= 'Z') {
                message[j] += 32;
            }
        }
        printf("Spam detected! Shifting shape...\n");
    } else {
        printf("Message is clean. No action required.\n");
    }
    
    printf("Your transformed message is: %s", message);
    
    return 0;
}