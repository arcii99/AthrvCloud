//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, num_count, upper_count, lower_count, special_count;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    num_count = upper_count = lower_count = special_count = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            num_count++;
        } else if (isupper(password[i])) {
            upper_count++;
        } else if (islower(password[i])) {
            lower_count++;
        } else {
            special_count++;
        }
    }

    if (length < 8) {
        printf("Password should be at least 8 characters long.");
    } else if (num_count < 2) {
        printf("Password should have at least two digits.");
    } else if (upper_count < 1) {
        printf("Password should have at least one uppercase letter.");
    } else if (lower_count < 1) {
        printf("Password should have at least one lowercase letter.");
    } else if (special_count < 1) {
        printf("Password should have at least one special character.");
    } else {
        printf("Password is strong!");
    }

    return 0;
}