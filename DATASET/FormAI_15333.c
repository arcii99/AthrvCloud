//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkLength(char *password) {
    int length = strlen(password);
    if (length < 8) { // Minimum password length of 8
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    return 1; 
}

int checkUpper(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) // Check if the password contains an uppercase letter
            return 1;
    }
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
}

int checkLower(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) // Check if the password contains a lowercase letter
            return 1;
    }
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
}

int checkDigit(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) // Check if the password contains a digit
            return 1;
    }
    printf("Password must contain at least one digit.\n");
    return 0;
}

int checkSpecial(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) // Check if the password contains a special character
            return 1;
    }
    printf("Password must contain at least one special character.\n");
    return 0;
}

void checkPassword(char *password) {
    if (checkLength(password) && checkUpper(password) && 
        checkLower(password) && checkDigit(password) && checkSpecial(password))
        printf("Password is strong!\n");
}

int main() {
    char password[100];
    printf("Enter password: ");
    fgets(password, 100, stdin); // Allow spaces in the password
    password[strcspn(password, "\n")] = '\0'; // Remove newline character
    checkPassword(password);
    return 0;
}