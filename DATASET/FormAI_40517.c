//FormAI DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define SPAM_LIMIT 5

int main() {
    int count = 0;
    char previous_message[100], current_message[100];

    printf("SPAM DETECTION SYSTEM\n");

    while(1) {
        printf("Enter your message: ");
        fgets(current_message, 100, stdin);

        // Check for spam
        if(strcmp(current_message, previous_message) == 0) {
            count++;
        } else {
            count = 0;
        }

        // If spam limit reached, inform user and exit
        if(count == SPAM_LIMIT) {
            printf("SPAM ALERT: You have reached the spam limit.\n");
            printf("Please try again later.\n");
            break;
        }

        // Copy current message to previous message
        strcpy(previous_message, current_message);
    }

    return 0;
}