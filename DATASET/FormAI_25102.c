//FormAI DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <string.h>

// function to detect spam in the input string
int detectSpam(char* inputString) {
    // list of spam words to check for
    char* spamWords[] = {"buy", "click", "limited time offer", "money back guarantee"};
    int numSpamWords = sizeof(spamWords)/sizeof(spamWords[0]);
    
    // loop through each word in the input string
    char* token = strtok(inputString, " "); // get first word
    while(token != NULL) {
        // check if each word is a spam word
        for(int i=0; i<numSpamWords; i++) {
            if(strcmp(token, spamWords[i]) == 0) {
                return 1; // spam detected
            }
        }
        token = strtok(NULL, " "); // get next word
    }
    return 0; // no spam detected
}

int main() {
    char inputString[100];
    printf("Enter a string to check for spam: ");
    fgets(inputString, 100, stdin); // get user input
    
    // remove newline character at end of input string
    if(inputString[strlen(inputString)-1] == '\n') {
        inputString[strlen(inputString)-1] = '\0';
    }
    
    // check if input string contains spam
    if(detectSpam(inputString)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }
    
    return 0;
}