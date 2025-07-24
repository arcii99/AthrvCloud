//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define PASSWORD_LENGTH 12

int main() {
    // Ask user for a string to be used to generate password
    char inputString[100];
    printf("Enter a string to be used to generate the password: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character from user input
    inputString[strcspn(inputString, "\n")] = '\0';

    // Convert inputString to all uppercase
    for (int i = 0; inputString[i]; i++) {
        inputString[i] = toupper(inputString[i]);
    }

    // Create an array of allowed characters for the password
    char allowedChars[36];
    int index = 0;
    for (int i = 0; inputString[i]; i++) {
        if (isalpha(inputString[i])) {
            allowedChars[index] = inputString[i];
            index++;
        } else if (isdigit(inputString[i])) {
            allowedChars[index] = inputString[i];
            index++;
        }
    }
    allowedChars[index++] = '@';
    allowedChars[index++] = '#';
    allowedChars[index++] = '$';
    allowedChars[index++] = '%';
    allowedChars[index++] = '&';

    // Set random number generator seed
    srand(time(NULL));

    // Generate random password
    char password[PASSWORD_LENGTH + 1];
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = allowedChars[rand() % strlen(allowedChars)];
    }
    password[PASSWORD_LENGTH] = '\0';

    // Print out generated password
    printf("Your generated password is: %s\n", password);

    return 0;
}