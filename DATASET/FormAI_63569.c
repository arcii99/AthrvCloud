//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char password[100];
    bool upper_flag = false, lower_flag = false, digit_flag = false, symbol_flag = false;
    int length, score = 0;

    printf("Enter password: ");
    fgets(password, 100, stdin);

    length = strlen(password) - 1; // subtract 1 to remove newline

    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c) && !upper_flag) {
            upper_flag = true;
            score += 5;
        }

        if (islower(c) && !lower_flag) {
            lower_flag = true;
            score += 5;
        }

        if (isdigit(c) && !digit_flag) {
            digit_flag = true;
            score += 5;
        }

        if (!isalnum(c) && !symbol_flag) {
            symbol_flag = true;
            score += 5;
        }
    }

    if (!upper_flag)
        printf("Password must contain at least one uppercase letter.\n");

    if (!lower_flag)
        printf("Password must contain at least one lowercase letter.\n");

    if (!digit_flag)
        printf("Password must contain at least one digit.\n");

    if (!symbol_flag)
        printf("Password must contain at least one non-alphanumeric character.\n");

    if (score < 25)
        printf("Password strength is weak.\n");
    else if (score < 40)
        printf("Password strength is medium.\n");
    else
        printf("Password strength is strong.\n");

    return 0;
}