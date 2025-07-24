//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int score = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    int length = strlen(password) - 1;

    // Check length of the password
    if (length >= 8) {
        score++;
    } else {
        printf("Password must be at least 8 characters long.\n");
    }

    // Check if password contains at least one uppercase character
    for (int i = 0; i < length; i++) {
        char character = password[i];
        if (character >= 'A' && character <= 'Z') {
            score++;
            break;
        }
    }

    // Check if password contains at least one lowercase character
    for (int i = 0; i < length; i++) {
        char character = password[i];
        if (character >= 'a' && character <= 'z') {
            score++;
            break;
        }
    }

    // Check if password contains at least one number
    for (int i = 0; i < length; i++) {
        char character = password[i];
        if (character >= '0' && character <= '9') {
            score++;
            break;
        }
    }

    // Check if password contains at least one special character
    for (int i = 0; i < length; i++) {
        char character = password[i];
        if ((character >= ' ' && character <= '/') || 
            (character >= ':' && character <= '@') ||
            (character >= '[' && character <= '`') ||
            (character >= '{' && character <= '~')) {
            score++;
            break;
        }
    }

    // Check the strength score of the password
    if (length == 0) {
        printf("Password cannot be empty.\n");
    } else if (score == 1) {
        printf("Password is weak.\n");
    } else if (score == 2) {
        printf("Password is moderate.\n");
    } else if (score == 3) {
        printf("Password is strong.\n");
    } else if (score == 4) {
        printf("Password is very strong.\n");
    } else {
        printf("Invalid password.\n");
    }

    return 0;
}