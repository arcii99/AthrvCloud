//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_PASSWORDS 10

// Define a struct to hold password information
typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    int numChars;
    int numDigits;
    int numSymbols;
} Password;

// Define a function to check if a character is a symbol
int isSymbol(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' ||
            c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' ||
            c == '=' || c == '[' || c == ']' || c == '{' || c == '}' || c == ';' ||
            c == ':' || c == '\'' || c == '\"' || c == ',' || c == '.' || c == '<' ||
            c == '>' || c == '/' || c == '?' || c == '`' || c == '~');
}

// Define a function to prompt the user for input
void prompt(char *message, char *input, int maxLength) {
    printf("%s (max %d characters):\n", message, maxLength);
    fgets(input, maxLength, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
}

int main() {
    Password passwordArray[MAX_PASSWORDS]; // Array to hold passwords
    int numPasswords = 0; // Keep track of the number of passwords

    while (1) {
        char input[MAX_PASSWORD_LENGTH + 1]; // Buffer for user input

        // Prompt the user for input
        prompt("Enter a new password", input, MAX_PASSWORD_LENGTH);

        // Check if the password is too short
        if (strlen(input) < 8) {
            printf("Password is too short\n");
            continue;
        }

        // Check if the password is too long
        if (strlen(input) > 20) {
            printf("Password is too long\n");
            continue;
        }

        // Check if the password already exists
        int i;
        for (i = 0; i < numPasswords; i++) {
            if (strcmp(input, passwordArray[i].password) == 0) {
                printf("Password already exists\n");
                break;
            }
        }
        if (i < numPasswords) {
            continue;
        }

        // Determine the number of characters, digits, and symbols in the password
        int numChars = 0;
        int numDigits = 0;
        int numSymbols = 0;
        for (i = 0; i < strlen(input); i++) {
            if (isalpha(input[i])) {
                numChars++;
            } else if (isdigit(input[i])) {
                numDigits++;
            } else if (isSymbol(input[i])) {
                numSymbols++;
            }
        }

        // Check if the password has at least one character, one digit, and one symbol
        if (numChars == 0 || numDigits == 0 || numSymbols == 0) {
            printf("Password must contain at least one letter, one number, and one symbol\n");
            continue;
        }

        // Add the password to the array
        if (numPasswords < MAX_PASSWORDS) {
            Password newPass;
            strcpy(newPass.password, input);
            newPass.numChars = numChars;
            newPass.numDigits = numDigits;
            newPass.numSymbols = numSymbols;
            passwordArray[numPasswords] = newPass;
            numPasswords++;
            printf("Password added!\n");
        } else {
            printf("Maximum number of passwords reached\n");
        }
    }

    return 0;
}