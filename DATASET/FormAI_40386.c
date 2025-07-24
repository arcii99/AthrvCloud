//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int len, upper, lower, digit, special;
    int strength = 0;

    printf("Enter your password (maximum length 50 characters): ");
    fgets(password, sizeof(password), stdin);

    len = strlen(password) - 1; // to remove the newline character at the end

    if (len < 8) {
        printf("Your password is too short. It should contain at least 8 characters.\n");
        exit(0);
    }

    for (int i = 0; i < len; i++) {
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

    strength = upper + lower + digit + special;

    if (strength == 1) {
        printf("Your password is very weak.\n");
    } else if (strength == 2) {
        printf("Your password is weak.\n");
    } else if (strength == 3) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is very strong.\n");
    }

    return 0;
}