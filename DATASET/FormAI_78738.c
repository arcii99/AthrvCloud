//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
// Ada Lovelace Style C Password Strength Checker Example Program
// By OpenAI GPT-3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PWD_LENGTH 8
#define MAX_PWD_LENGTH 16

int main(int argc, char *argv[]) {

    char pwd[MAX_PWD_LENGTH+1];
    char c;
    int i, pwd_length;
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;

    printf("Please enter your password (8-16 characters): ");
    fgets(pwd, MAX_PWD_LENGTH+1, stdin);
    pwd_length = strlen(pwd) - 1;

    if (pwd_length < MIN_PWD_LENGTH || pwd_length > MAX_PWD_LENGTH) {
        printf("Invalid password length!\n");
        return 1;
    }

    for (i = 0; i < pwd_length; i++) {
        c = pwd[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (ispunct(c)) {
            has_special = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_digit && has_special) {
        printf("Strong password!\n");
    } else {
        printf("Weak password! Please include at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }

    return 0;
}