//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char spam_message[100];
    int spam_score = 0;

    //Prompt user to input message
    printf("Enter a message to check for spam: ");
    
    //Read user input
    fgets(spam_message, 100, stdin);

    //Replace newline character with null terminator
    spam_message[strcspn(spam_message, "\n")] = '\0';

    //Check for common spam keywords
    if (strstr(spam_message, "free") != NULL) {
        spam_score += 10;
    }
    if (strstr(spam_message, "win") != NULL) {
        spam_score += 10;
    }
    if (strstr(spam_message, "limited time") != NULL) {
        spam_score += 5;
    }
    if (strstr(spam_message, "urgent") != NULL) {
        spam_score += 5;
    }
    if (strstr(spam_message, "act now") != NULL) {
        spam_score += 5;
    }

    //Calculate spam score and output results
    if (spam_score >= 20) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}