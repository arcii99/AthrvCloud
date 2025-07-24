//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8

int main() {
    char password[50];
    int length = 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    int strength = 0;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline from password
    password[strcspn(password, "\n")] = '\0';

    // Calculate length of password
    length = strlen(password);
    printf("Password length: %d\n", length);

    // Check for uppercase, lowercase, digits, and special characters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else
            has_special = 1;
    }

    // Calculate password strength based on criteria
    if (length >= MIN_LENGTH && has_upper && has_lower && has_digit && has_special)
        strength = 4;
    else if (length >= MIN_LENGTH && has_upper && has_lower && has_digit)
        strength = 3;
    else if (length >= MIN_LENGTH && (has_upper || has_lower) && has_digit)
        strength = 2;
    else if (length >= MIN_LENGTH)
        strength = 1;

    // Output password strength
    if (strength == 4)
        printf("Password strength: Strong\n");
    else if (strength == 3)
        printf("Password strength: Good\n");
    else if (strength == 2)
        printf("Password strength: Fair\n");
    else if (strength == 1)
        printf("Password strength: Weak\n");
    else
        printf("Invalid password\n");

    return 0;
}