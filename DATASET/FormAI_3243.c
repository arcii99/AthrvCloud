//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, upper = 0, lower = 0, digits = 0, special = 0;
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    length = strlen(password) - 1;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper++;
        } else if (islower(password[i])) {
            lower++;
        } else if (isdigit(password[i])) {
            digits++;
        } else if (ispunct(password[i])) {
            special++;
        }
    }
    printf("\nPassword strength: ");
    if (length < 8 || length > 20) {
        printf("Password must be between 8 and 20 characters in length.");
    } else if (upper < 1 || lower < 1) {
        printf("Password must contain at least 1 uppercase and 1 lowercase letter.");
    } else if (digits < 1 || special < 1) {
        printf("Password must contain at least 1 digit and 1 special character.");
    } else {
        printf("Password is strong!");
    }
    return 0;
}