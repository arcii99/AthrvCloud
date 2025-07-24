//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: futuristic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length, i, count_lower, count_upper, count_digit, count_special;

    printf("Please enter your password: ");
    fgets(password, sizeof(password), stdin);

    length = strlen(password) - 1;

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password too short! Your password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    } else if (length > MAX_PASSWORD_LENGTH) {
        printf("Password too long! Your password must be no longer than %d characters.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    count_lower = count_upper = count_digit = count_special = 0;

    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            count_lower++;
        } else if (isupper(password[i])) {
            count_upper++;
        } else if (isdigit(password[i])) {
            count_digit++;
        } else {
            count_special++;
        }
    }
    
    if (count_lower == 0 || count_upper == 0 || count_digit == 0 || count_special == 0) {
        printf("Weak password! Your password must contain at least one of each: lower case letter, upper case letter, digit and special character.\n");
        return 1;
    }

    printf("Strong password! Your password has %d characters, %d lower case letters, %d upper case letters, %d digits and %d special characters.\n",
        length, count_lower, count_upper, count_digit, count_special);

    return 0;
}