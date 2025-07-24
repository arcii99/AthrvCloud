//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>

int main() {
    char password[50];
   
    printf("Enter a password: ");
    fgets(password, 50, stdin);

    int length = strlen(password) - 1;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        }
        else if (isupper(password[i])) {
            has_uppercase = 1;
        }
        else if (islower(password[i])) {
            has_lowercase = 1;
        }
        else {
            has_special_char = 1;
        }
    }

    int strength = has_digit + has_uppercase + has_lowercase + has_special_char;

    if (length >= 8 && strength == 4) {
        printf("Strong password!.\n");
    }
    else if (length >= 8 && strength >= 2) {
        printf("Medium strength password.\n");
    }
    else {
        printf("Weak password!.\n");
    }

    return 0;
}