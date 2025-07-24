//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isWeakPassword(char password[]) {
    // Returns 1 if the length of the password is less than 8
    if (strlen(password) < 8) {
        return 1;
    }

    int hasUpperCase = 0, hasLowerCase = 0, hasDigit = 0, hasSpecialChar = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (isalpha(password[i])) {
            if (islower(password[i])) {
                hasLowerCase = 1;
            } else if (isupper(password[i])) {
                hasUpperCase = 1;
            }
        } else {
            hasSpecialChar = 1;
        }
    }

    // Return 1 if the password doesn't have at least one uppercase character, one lowercase character,
    // one digit, and one special character
    if (!(hasLowerCase && hasUpperCase && hasDigit && hasSpecialChar)) {
        return 1;
    }

    // Return 0 if the password is strong
    return 0;
}

int main() {
    char password[100];
    printf("Enter your password: ");

    fgets(password, 100, stdin);

    // Remove the new line character from the password
    password[strcspn(password, "\n")] = '\0';

    int isWeak = isWeakPassword(password);

    if (isWeak) {
        printf("Password is weak. Consider making the password stronger by adding uppercase letters, numbers and special characters.\n");
    } else {
        printf("Password is strong!\n");
    }

    return 0;
}