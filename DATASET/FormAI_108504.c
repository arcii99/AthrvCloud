//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int spamCounter = 0;
    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    // Check for repeated characters
    for(int i = 0; i < strlen(message) - 1; i++) {
        if(message[i] == message[i+1]) {
            spamCounter++;
        }
    }

    // Check for excessive punctuation
    int punctuationCount = 0;
    char* ptr = message;
    while(*ptr) {
        if(*ptr == '.' || *ptr == '!' || *ptr == '?') {
            punctuationCount++;
        }
        ptr++;
    }
    if (punctuationCount > 5) {
        spamCounter += 2;
    }

    // Check for excessive use of uppercase letters
    int uppercaseCount = 0;
    ptr = message;
    while(*ptr) {
        if(*ptr >= 'A' && *ptr <= 'Z') {
            uppercaseCount++;
        }
        ptr++;
    }
    if(uppercaseCount > 10) {
        spamCounter += 3;
    }

    // Check for excessive use of exclamation marks
    int exclamationCount = 0;
    ptr = message;
    while(*ptr) {
        if(*ptr == '!') {
            exclamationCount++;
        }
        ptr++;
    }
    if(exclamationCount > 3) {
        spamCounter += 5;
    }

    // Check for excessive use of words associated with spam
    char spamWords[10][10] = {"money", "cheap", "buy", "sale", "offer", "limited", "opportunity", "credit", "loan", "free"};
    int spamWordCount = 0;
    char* token = strtok(message, " .,?!");
    while(token != NULL) {
        for(int i = 0; i < 10; i++) {
            if(strcmp(token, spamWords[i]) == 0) {
                spamWordCount++;
            }
        }
        token = strtok(NULL, " .,?!");
    }
    if(spamWordCount > 2) {
        spamCounter += 6;
    }

    // Final spam check
    if(spamCounter > 10) {
        printf("Your message has been classified as spam!\n");
    } else {
        printf("Congratulations! Your message is not spam.\n");
    }
    return 0;
}