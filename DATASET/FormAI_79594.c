//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000

/* Function that checks if a message contains the word "spam" */
int is_spam(char* message) {

    char* spam_message = "spam";

    // Convert message and spam_message to lowercase
    for(int i = 0; message[i]; i++){
        message[i] = tolower(message[i]);
    }
    for(int i = 0; spam_message[i]; i++){
        spam_message[i] = tolower(spam_message[i]);
    }

    // Check if message contains spam_message
    if (strstr(message, spam_message) != NULL) {
        return 1;
    }

    return 0;
}

int main() {

    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    if (is_spam(message)) {
        printf("This message contains spam.\n");
    } else {
        printf("This message does not contain spam.\n");
    }

    return 0;
}