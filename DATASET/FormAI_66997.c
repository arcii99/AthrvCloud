//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 500

int main(void) {

    char message[MAX_MESSAGE_LENGTH];
    bool is_spam = false;

    // prompt user to enter message
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // check for spam words
    if (strstr(message, "buy now") != NULL) {
        is_spam = true;
    }
    if (strstr(message, "free money") != NULL) {
        is_spam = true;
    }
    if (strstr(message, "discount") != NULL) {
        is_spam = true;
    }
    if (strstr(message, "limited time offer") != NULL) {
        is_spam = true;
    }
    if (strstr(message, "act now") != NULL) {
        is_spam = true;
    }

    // print result
    if (is_spam) {
        printf("This message is SPAM.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}