//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000
#define MAX_USERS 10
#define MAX_SPAM_COUNT 3

int spam_count[MAX_USERS] = {0}; // Keep track of spam counts for each user

int is_spam(char *msg, char *user) {
    int i, count = 0;
    for(i = 0; i < strlen(msg) - strlen(user) + 1; i++) {
        if(strncmp(msg + i, user, strlen(user)) == 0) {
            count++;
        }
    }
    spam_count[atoi(user) - 1] = count; // Update spam count for the user
    return count >= MAX_SPAM_COUNT;
}

int main() {
    char msg[MAX_MSG_LENGTH];
    char user[MAX_USERS];
    int i;
    printf("Welcome to the Spam Detection System\n");

    // Loop for receiving and processing messages
    while(1) {
        printf("Enter the user number: ");
        fgets(user, MAX_USERS, stdin);
        user[strcspn(user, "\n")] = 0; // Remove trailing newline character
        
        printf("Enter the message: ");
        fgets(msg, MAX_MSG_LENGTH, stdin);
        msg[strcspn(msg, "\n")] = 0; // Remove trailing newline character
        
        if(is_spam(msg, user)) {
            printf("SPAM ALERT: User %s sent a spam message %d times!\n", user, spam_count[atoi(user) - 1]);
        } else {
            printf("Message received\n");
        }
    }
    
    return 0;
}