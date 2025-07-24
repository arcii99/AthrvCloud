//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

void check_password_strength(char *password) {
    int length = strlen(password);
    int has_lowercase = 0, has_uppercase = 0, has_number = 0, has_symbol = 0;

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short. Minimum length is %d characters.\n", MIN_PASSWORD_LENGTH);
        return;
    }

    if (length > MAX_PASSWORD_LENGTH) {
        printf("Password is too long. Maximum length is %d characters.\n", MAX_PASSWORD_LENGTH);
        return;
    }

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (c >= 'a' && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= 'A' && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= '0' && c <= '9') {
            has_number = 1;
        } else {
            has_symbol = 1;
        }
    }

    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return;
    }

    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return;
    }

    if (!has_number) {
        printf("Password must contain at least one number.\n");
        return;
    }

    if (!has_symbol) {
        printf("Password must contain at least one symbol.\n");
        return;
    }

    printf("Password is strong!\n");
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);

    // Remove trailing newline character from fgets result
    password[strcspn(password, "\n")] = 0;

    check_password_strength(password);

    return 0;
}