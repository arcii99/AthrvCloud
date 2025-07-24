//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[101];
    int length, uppercase, lowercase, digit;

    printf("Enter a password:\n");
    fgets(password, 101, stdin);
    length = strlen(password) - 1; // -1 to exclude newline character

    // Check length
    if (length < 8) {
        printf("Password is too short, it must be at least 8 characters long.\n");
        return 0;
    }

    // Check uppercase letter
    uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }
    if (!uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check lowercase letter
    lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }
    if (!lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check digit
    digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }
    if (!digit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    // Password meets all criteria, print success message
    printf("Password is valid and meets all strength criteria!\n");

    return 0;
}