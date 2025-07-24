//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define MAX_SPAM_MSGS 5
#define SPAM_MSG "Buy our product!"
#define BLOCKED_MSG "Message blocked due to spam content."

int main() {
    char msg[MAX_MSG_LENGTH];
    char spammsg[MAX_SPAM_MSGS][MAX_MSG_LENGTH];
    int num_spam_msgs = 0;
    int is_spam = 0;

    // initialize the array of spam messages
    strcpy(spammsg[num_spam_msgs++], "Buy our product!");
    strcpy(spammsg[num_spam_msgs++], "Get rich quick!");
    strcpy(spammsg[num_spam_msgs++], "Make money fast!");
    strcpy(spammsg[num_spam_msgs++], "Lose weight quickly!");
    strcpy(spammsg[num_spam_msgs++], "Bankruptcy help!");

    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);

    // check the message for spam content
    for (int i = 0; i < num_spam_msgs; i++) {
        if (strstr(msg, spammsg[i])) {
            is_spam = 1;
            break;
        }
    }

    // if the message is spam, display a blocked message
    if (is_spam) {
        printf("%s\n", BLOCKED_MSG);
    } 
    // otherwise, display the original message
    else {
        printf("Message: %s\n", msg);
    }

    return 0;
}