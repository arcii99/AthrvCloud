//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000

int check_spam(char* message) {
    int score = 0;
    
    if (strstr(message, "click this") != NULL) {
        score += 5;
    }
    
    if (strstr(message, "buy now") != NULL) {
        score += 5;
    }
    
    if (strstr(message, "limited offer") != NULL) {
        score += 5;
    }
    
    if (strstr(message, "you have won") != NULL) {
        score += 10;
    }
    
    if (strstr(message, "bank account") != NULL) {
        score += 10;
    }
    
    return score;
}

int main(void) {
    char message[MAX_MESSAGE_LENGTH];
    
    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    int spam_score = check_spam(message);
    
    if (spam_score >= 15) {
        printf("This message is spam!\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}