//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char userInput[50];
    printf("Enter your input: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0; // removes the new line character from fgets();

    // check for non-alphanumeric characters and replace them with space
    for(int i=0; i<strlen(userInput); i++) {
        if(!isalnum(userInput[i])) {
            userInput[i] = ' ';
        }
    }

    // convert all characters to lower case
    for(int i=0; i<strlen(userInput); i++) {
        userInput[i] = tolower(userInput[i]);
    }

    printf("Sanitized input: %s", userInput);

    return 0;
}