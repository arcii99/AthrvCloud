//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_SCORE 5

int isSpam(char* message);

int main() {
    char message[1000];
    char* spamWords[MAX_SPAM_WORDS] = {"sale", "discount", "money", "limited time offer", "free", "click here", "get rich", "lottery", "earn money", "opportunity"};
    
    printf("Enter your message: ");
    fgets(message, 1000, stdin);
    
    if(isSpam(message)) {
        printf("SPAM DETECTED!\n");
    } else {
        printf("Message is not spam.\n");
    }
    
    return 0;
}

int isSpam(char* message) {
    int score = 0;
    char* token;
    char* spamWords[MAX_SPAM_WORDS] = {"sale", "discount", "money", "limited time offer", "free", "click here", "get rich", "lottery", "earn money", "opportunity"};
    
    // Convert message to lowercase
    for(int i=0; i<strlen(message); i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + 32;
        }
    }
    
    // Check for spam words
    token = strtok(message, " .,!?\n");
    while(token != NULL) {
        for(int i=0; i<MAX_SPAM_WORDS; i++) {
            if(strcmp(token, spamWords[i]) == 0) {
                score++;
            }
        }
        token = strtok(NULL, " .,!?\n");
    }
    
    return (score >= MAX_SPAM_SCORE);
}