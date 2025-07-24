//FormAI DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int spam_score = 0;
    
    printf("Enter a message: ");
    fgets(message, 1000, stdin);
    
    char *token = strtok(message, " ");
    
    while (token != NULL) {
        if (strcmp(token, "buy") == 0 || strcmp(token, "click") == 0 || strcmp(token, "cash") == 0) {
            spam_score += 2;
        } else if (strcmp(token, "free") == 0 || strcmp(token, "offer") == 0 || strcmp(token, "limited") == 0) {
            spam_score += 1;
        } else if (strcmp(token, "unsubscribe") == 0 || strcmp(token, "remove") == 0 || strcmp(token, "opt-out") == 0) {
            printf("This message is not spam.\n");
            return 0;
        }
        
        token = strtok(NULL, " ");
    }
    
    if (spam_score >= 4) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}