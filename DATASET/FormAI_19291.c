//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {

    printf("--Welcome to the C Password Strength Checker--\n");

    // Password input
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0;

    // Calculating password strength
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digits = 0, symbols = 0, uniqueChars = 0;
    int strength = 0, maxStrength = 10;
    for (int i = 0; i < length; i++) {
        char ch = password[i];
        if (ch >= 'A' && ch <= 'Z') {
            uppercase = 1;
        } else if (ch >= 'a' && ch <= 'z') {
            lowercase = 1;
        } else if (ch >= '0' && ch <= '9') {
            digits = 1;
        } else {
            symbols = 1;
        }
        if (strchr(password, ch) == &password[i]) {
            uniqueChars++;
        }
    }
    strength += length * 4;
    if (uppercase) {
        strength += 2;
    }
    if (lowercase) {
        strength += 2;
    }
    if (digits) {
        strength += 4;
    }
    if (symbols) {
        strength += 6;
    }
    strength += uniqueChars * 2;

    // Displaying password strength
    printf("\nPassword strength: %d/%d\n", strength, maxStrength);
    if (strength < 6) {
        printf("Weak password.\n");
    } else if (strength < 8) {
        printf("Moderate password.\n");
    } else if (strength < 10) {
        printf("Strong password.\n");
    } else {
        printf("Very strong password!\n");
    }

    return 0;
}