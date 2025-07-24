//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/* Function to check if message is spam or not */
bool isSpam(char* message) {
    const char* spamWords[] = {"buy", "buy now", "limited time offer", "act now", "make money fast"};
    const int spamCount = sizeof(spamWords) / sizeof(spamWords[0]);
    char* tempMessage = message;
    bool isMessageSpam = false;
    
    /* Convert message to lowercase for easier comparison */
    while(*tempMessage) {
        *tempMessage = tolower(*tempMessage);
        tempMessage++;
    }
    
    /* Check if message contains any spam words */
    for(int i = 0; i < spamCount; i++) {
        if(strstr(message, spamWords[i])) {
            isMessageSpam = true;
            break;
        }
    }
    
    /* Return whether message is spam or not */
    return isMessageSpam;
}

/* Main function to run the spam detection system */
int main() {
    char message[1000];
    printf("Please enter a message to check for spam: ");
    fgets(message, 1000, stdin);
    
    /* Remove newline character at the end of message */
    message[strcspn(message, "\n")] = 0;
    
    /* Check if message is spam or not */
    if(isSpam(message)) {
        printf("SPAM DETECTED!\n");
    }
    else {
        printf("Message is not spam.\n");
    }
    
    return 0;
}