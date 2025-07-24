//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_char_count = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Password is too short. It should be at least 8 characters long.\n");
    } else {
        for (int i = 0; i < length; i++) {
            if (isupper(password[i])) {    // Check for uppercase letters
                uppercase_count++;
            } else if (islower(password[i])) {    // Check for lowercase letters
                lowercase_count++;
            } else if (isdigit(password[i])) {    // Check for digits
                digit_count++;
            } else {    // Check for special characters
                special_char_count++;
            }
        }

        // Print the strength of the password based on the counts of different types of characters
        if (uppercase_count > 0 && lowercase_count > 0 && digit_count > 0 && special_char_count > 0) {
            printf("Strong password\n");
        } else if (uppercase_count > 0 && lowercase_count > 0 && digit_count > 0) {
            printf("Good password\n");
        } else {
            printf("Weak password\n");
        }
    }

    return 0;
}