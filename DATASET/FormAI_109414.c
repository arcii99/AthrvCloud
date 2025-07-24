//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    // get password input
    char password[20];
    printf("Enter password: ");
    fgets(password, 20, stdin);

    // check password length
    int length = strlen(password);
    if (length < 8) {
        printf("Password must be at least 8 characters.\n");
        return 0;
    }

    // check password complexity
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    for (int i = 0; i < length-1; i++) {
        char c = password[i];
        if (isupper(c)) has_upper++;
        if (islower(c)) has_lower++;
        if (isdigit(c)) has_digit++;
        if (ispunct(c)) has_special++;
    }

    // check if password has all required elements
    if (has_upper && has_lower && has_digit && has_special) {
        printf("Password is strong!\n");
        return 0;
    } else {
        printf("Password is weak.\n");
        return 0;
    }
}