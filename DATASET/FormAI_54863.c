//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char userInput[100];
    printf("Welcome to the Happy Sanitizer 3000! Let's sanitize some user input! :)\n");

    printf("Enter a string of characters: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0; // Remove trailing newline character

    printf("Your original string was: %s\n", userInput);

    for (int i = 0; i < strlen(userInput); i++) {
        if (!isalnum(userInput[i])) { // If the character is not alphanumeric
            userInput[i] = '_'; // Replace it with an underscore
        }
    }

    printf("Your sanitized string is: %s\n", userInput);
    printf("Hooray! User input successfully sanitized! :D\n");

    return 0;
}