//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, has_uppercase, has_lowercase, has_number, has_special;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    has_uppercase = 0;
    has_lowercase = 0;
    has_number = 0;
    has_special = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special = 1;
        }
    }

    if (length >= 8 && has_uppercase && has_lowercase && has_number && has_special) {
        printf("Your password is very strong.\n");
        printf("Congratulations!\n");
    } else if (length >= 8 && ((has_uppercase && has_lowercase) || (has_uppercase && has_number) || (has_uppercase && has_special) || (has_lowercase && has_number) || (has_lowercase && has_special) || (has_number && has_special))) {
        printf("Your password is strong enough.\n");
        printf("But it can be even stronger.\n");
    } else {
        printf("Your password is weak.\n");
        printf("Please try again with a stronger password.\n");
    }

    return 0;
}