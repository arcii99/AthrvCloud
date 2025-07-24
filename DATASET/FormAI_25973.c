//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() {
    char password[MAX];
    int len, i, digits = 0, uppercase = 0, lowercase = 0, special_chars = 0, strength = 0;

    printf("Enter your password: ");
    fgets(password, MAX, stdin);
    len = strlen(password);

    // Check password length
    if (len < 8) {
        printf("Your password should be at least 8 characters long.\n");
        return 0;
    }

    // Check for digits, uppercase and lowercase letters, and special characters
    for (i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            digits = 1;
        } else if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else {
            special_chars = 1;
        }
    }

    // Calculate password strength
    strength = digits + uppercase + lowercase + special_chars;

    // Print password strength
    switch (strength) {
        case 1:
            printf("Your password is very weak.\n");
            break;
        case 2:
            printf("Your password is weak.\n");
            break;
        case 3:
            printf("Your password is moderate.\n");
            break;
        case 4:
            printf("Your password is strong.\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }

    return 0;
}