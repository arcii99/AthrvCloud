//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char password[50];
    int length, i;
    int lowercase = 0, uppercase = 0, digits = 0, specialchar = 0;

    // Asks user for input
    printf("Enter password: ");
    scanf("%s", password);

    // Calculates length of password
    length = strlen(password);

    // Checks for each required condition for the password strength
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase++;
        }
        if (isupper(password[i])) {
            uppercase++;
        }
        if (isdigit(password[i])) {
            digits++;
        }
        if (ispunct(password[i])) {
            specialchar++;
        }
    }

    // Determines the strength of the password
    if (length < 8 || lowercase < 1 || uppercase < 1 || digits < 1 || specialchar < 1) {
        printf("Your password is weak. It should have at least 8 characters, an uppercase letter, a lowercase letter, a digit, and a special character.\n");
    }
    else if (length < 12 || lowercase == 0 || uppercase == 0 || digits == 0 || specialchar == 0) {
        printf("Your password is medium. It should have at least 12 characters, an uppercase letter, a lowercase letter, a digit, and a special character.\n");
    }
    else {
        printf("Your password is strong. It meets all the requirements.\n");
    }
    return 0;
}