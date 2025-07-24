//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // define maximum length of an input message

// function to check if a message contains spam
int isSpam(char *message) {
    char *keywords[] = {"buy", "sale", "cheap", "free", "moneyback"}; // define list of keywords indicating spam
    int num_keywords = 5; // define number of keywords

    char *token; // define token for message parsing
    char copy[MAX_LENGTH]; // define copy of message for parsing

    // create copy of message to avoid modifying original message
    strncpy(copy, message, MAX_LENGTH);
    copy[MAX_LENGTH - 1] = '\0';

    // parse message and check for keyword occurrence
    token = strtok(copy, " "); // get first token

    while(token != NULL) { // loop through all tokens
        for(int i = 0; i < num_keywords; i++) {
            if(strcmp(token, keywords[i]) == 0) { // check if token matches keyword
                return 1; // return 1 if keyword is found
            }
        }
        token = strtok(NULL, " "); // get next token
    }

    return 0; // return 0 if no keyword is found
}

int main() {
    char message[MAX_LENGTH]; // define message input buffer

    printf("Enter your message:\n");
    fgets(message, MAX_LENGTH, stdin); // get input message from user

    int result = isSpam(message); // check if input message is spam

    if(result == 1) {
        printf("Your message is classified as spam.\n"); // print result if message is spam
    } else {
        printf("Your message is not spam.\n"); // print result if message is not spam
    }

    return 0;
}