//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check password strength
int passwordStrength(char *password) {
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
        } else if (islower(password[i])) {
            lower = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    if (length < 8 || length > 15) {
        return 0;   // password length is not appropriate
    }

    if (upper == 0 || lower == 0 || digit == 0 || special == 0) {
        return 0;   // password strength criteria is not met
    }

    return 1;   // password is strong
}

int main() {
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    if (passwordStrength(password)) {
        printf("Your password is strong. Keep it up!\n");
    } else {
        printf("Your password is weak. Please choose a stronger one.\n");
    }

    return 0;
}