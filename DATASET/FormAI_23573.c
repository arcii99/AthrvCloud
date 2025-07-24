//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN_LENGTH 8

int main() {
    char password[100];
    int length, hasLowercase, hasUppercase, hasDigit, hasSpecialChar;
    char c;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    hasLowercase = hasUppercase = hasDigit = hasSpecialChar = 0;

    if (length >= MIN_LENGTH) {
        for (int i = 0; i < length; i++) {
            c = password[i];

            if (islower(c)) {
                hasLowercase = 1;
            } else if (isupper(c)) {
                hasUppercase = 1;
            } else if (isdigit(c)) {
                hasDigit = 1;
            } else {
                hasSpecialChar = 1;
            }
        }

        if (hasLowercase && hasUppercase && hasDigit && hasSpecialChar) {
            printf("Congrats! Your password is very strong!\n");
        } else if ((hasLowercase || hasUppercase) && hasDigit && hasSpecialChar) {
            printf("Your password is strong enough.\n");
        } else {
            printf("Your password is too weak!\n");
        }
    } else {
        printf("Your password must be at least %d characters.\n", MIN_LENGTH);
    }

    return 0;
}