//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 128

int main() {

    char password[MAX_PASSWORD_LENGTH];
    int num_uppercase = 0, num_lowercase = 0, num_digits = 0, num_symbols = 0, password_length = 0;
    int i;

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // remove newline character from the end of the password string
    password[strcspn(password, "\n")] = '\0';

    // check password length
    password_length = strlen(password);
    if (password_length < 8 || password_length > 50) {
        printf("Password must be at least 8 characters and at most 50 characters long.\n");
        return 0;
    }

    // check for uppercase letters, lowercase letters, digits, and symbols
    for (i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            num_uppercase++;
        }
        if (islower(password[i])) {
            num_lowercase++;
        }
        if (isdigit(password[i])) {
            num_digits++;
        }
        if (ispunct(password[i])) {
            num_symbols++;
        }
    }

    // print the password strength score
    printf("Password Strength Score: %d/100\n", (num_uppercase * 25) + (num_lowercase * 25) + (num_digits * 25) + (num_symbols * 25));

    // print feedback based on the password strength score
    if ((num_uppercase * 25) + (num_lowercase * 25) + (num_digits * 25) + (num_symbols * 25) >= 80) {
        printf("Password Strength: STRONG\n");
    } else if ((num_uppercase * 25) + (num_lowercase * 25) + (num_digits * 25) + (num_symbols * 25) >= 60) {
        printf("Password Strength: MEDIUM\n");
    } else {
        printf("Password Strength: WEAK\n");
    }

    return 0;
}