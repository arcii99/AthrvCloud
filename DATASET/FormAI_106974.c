//FormAI DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int spam_count = 0;

    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter a message: ");
    fgets(message, 100, stdin);

    // Check for all caps
    int caps_count = 0;
    for(int i = 0; i < strlen(message); i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            caps_count++;
        }
    }
    if(caps_count > strlen(message) / 2) {
        printf("Warning: Your message is all in uppercase letters!\n");
        spam_count++;
    }

    // Check for excessive use of exclamation marks
    int exclamation_count = 0;
    for(int i = 0; i < strlen(message); i++) {
        if(message[i] == '!') {
            exclamation_count++;
        }
    }
    if(exclamation_count > 3) {
        printf("Warning: Your message contains excessive use of exclamation marks!\n");
        spam_count++;
    }

    // Check for excessive use of dollar signs
    int dollar_count = 0;
    for(int i = 0; i < strlen(message); i++) {
        if(message[i] == '$') {
            dollar_count++;
        }
    }
    if(dollar_count > strlen(message) / 4) {
        printf("Warning: Your message contains excessive use of dollar signs!\n");
        spam_count++;
    }

    // Check for use of certain keywords
    char keywords[5][10] = {"earn", "money", "free", "offer", "win"};
    for(int i = 0; i < 5; i++) {
        if(strstr(message, keywords[i]) != NULL) {
            printf("Warning: Your message contains the keyword \"%s\"!\n", keywords[i]);
            spam_count++;
        }
    }

    if(spam_count > 1) {
        printf("Your message has been flagged as spam and will not be sent.\n");
    } else {
        printf("Your message is not considered spam and will be sent.\n");
    }

    return 0;
}