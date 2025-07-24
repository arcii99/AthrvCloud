//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surprised
#include <stdio.h>
#include <string.h>

// Defining the minimum length of password that we require
#define MIN_PASSWORD_LENGTH 8

// Defining the maximum length of password that we allow
#define MAX_PASSWORD_LENGTH 16

int is_upper_case(char c) {
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int is_lower_case(char c) {
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int is_digit(char c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

int is_special(char c) {
    return (c == '@' || c == '#' || c == '$' || c == '%' || c == '^'
           || c == '&' || c == '*' || c == '(' || c == ')' || c == '-'
           || c == '+' || c == '/' || c == ':' || c == ';' || c == '<'
           || c == '>' || c == '=' || c == '?' || c == '[' || c == ']'
           || c == '{' || c == '}' || c == '~' || c == '!' || c == '.'
           || c == ',' || c == '"') ? 1 : 0;
}

int get_password_strength(char *password) {
    int password_length = strlen(password);
    int upper_case_chars = 0;
    int lower_case_chars = 0;
    int digit_chars = 0;
    int special_chars = 0;

    if (password_length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    if (password_length > MAX_PASSWORD_LENGTH) {
        password_length = MAX_PASSWORD_LENGTH;
    }

    int i;
    for (i = 0; i < password_length; i++) {
        if (is_upper_case(password[i])) {
            upper_case_chars++;
        }

        if (is_lower_case(password[i])) {
            lower_case_chars++;
        }

        if (is_digit(password[i])) {
            digit_chars++;
        }

        if (is_special(password[i])) {
            special_chars++;
        }
    }

    if (upper_case_chars > 0 && lower_case_chars > 0 && digit_chars > 0 && special_chars > 0) {
        return 4;
    } else if (upper_case_chars > 0 && lower_case_chars > 0 && digit_chars > 0) {
        return 3;
    } else if (upper_case_chars > 0 && lower_case_chars > 0) {
        return 2;
    } else if ((upper_case_chars > 0 || lower_case_chars > 0) && digit_chars > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[100];

    printf("Enter a password to check its strength (8 to 16 characters): ");
    scanf("%s", password);

    int strength = get_password_strength(password);

    if (strength == 0) {
        printf("Weak password! Please try again.\n");
    } else if (strength == 1) {
        printf("Not bad! But can be better.\n");
    } else if (strength == 2) {
        printf("Good job! Your password is average.\n");
    } else if (strength == 3) {
        printf("Great work! Your password is strong.\n");
    } else if (strength == 4) {
        printf("Amazing! Your password is very strong.\n");
    }

    return 0;
}