//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, i, uppercase, lowercase, digits, symbols, strength;

    printf("Enter your password: ");
    fgets(password, 50, stdin);
    length = strlen(password);

    uppercase = lowercase = digits = symbols = strength = 0;

    for (i = 0; i < length - 1; i++) {
        if (isupper(password[i])) {
            uppercase++;
        }
        if (islower(password[i])) {
            lowercase++;
        }
        if (isdigit(password[i])) {
            digits++;
        }
        if (!isalnum(password[i])) {
            symbols++;
        }
    }

    strength = uppercase + lowercase + digits + symbols;

    if (length < 8) {
        printf("Your password is too short. It must be at least 8 characters long.\n");
    }
    else if (strength < 8) {
        printf("Your password is weak. Please use a mix of uppercase letters, lowercase letters, digits and symbols.\n");
    }
    else if (strength < 12) {
        printf("Your password is moderate, but can be improved. Please use a mix of uppercase letters, lowercase letters, digits and symbols.\n");
    }
    else {
        printf("Your password is strong! Good job.\n");
    }

    return 0;
}