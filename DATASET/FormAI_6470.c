//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitizeInput(char* userInput) {
    int len = strlen(userInput);
    int i, j;
    char sanitizedString[len];

    //Iterate through the string to remove any non-alphanumeric characters
    for(i=0, j=0; i<len; i++) {
        if(isalnum(userInput[i])) {
            sanitizedString[j++] = toupper(userInput[i]);
        }
    }

    sanitizedString[j] = '\0'; //add null character to the end of the string

    //Copy the sanitized string back to the user input
    strcpy(userInput, sanitizedString);
}

int main() {
    char userInput[100];
    printf("Enter a string: ");
    fgets(userInput, sizeof(userInput), stdin);
    printf("Your original input was: %s\n", userInput);

    //sanitize user input
    sanitizeInput(userInput);

    printf("The sanitized string is: %s\n", userInput);

    return 0;
}