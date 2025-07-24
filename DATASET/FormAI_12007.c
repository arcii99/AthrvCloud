//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int len, upper = 0, lower = 0, digit = 0, special = 0, strength = 0;

    printf("Enter a password (max 50 characters): ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;
    len = strlen(password);

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            upper += 1;
        } else if (islower(password[i])) {
            lower += 1;
        } else if (isdigit(password[i])) {
            digit += 1;
        } else {
            special += 1;
        }
    }

    if (len >= 8) {
        strength += 1;
    }
    if (upper > 0) {
        strength += 1;
    }
    if (lower > 0) {
        strength += 1;
    }
    if (digit > 0) {
        strength += 1;
    }
    if (special > 0) {
        strength += 1;
    }

    printf("\nPassword Strength\n");
    printf("-----------------\n");

    switch (strength) {
        case 1:
            printf("Very Weak\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        case 3:
            printf("Moderate\n");
            break;
        case 4:
            printf("Strong\n");
            break;
        case 5:
            printf("Very Strong\n");
            break;
        default:
            break;
    }

    return 0;
}