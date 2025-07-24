//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 30
#define LETTERS_LOWER "abcdefghijklmnopqrstuvwxyz"
#define LETTERS_UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()_+-={}|[]\\:\";'<>?,./"

int check_minimum_length(char *password);
int check_maximum_length(char *password);
int check_contains_lowercase(char *password);
int check_contains_uppercase(char *password);
int check_contains_number(char *password);
int check_contains_special_character(char *password);

int main() {
    char password[MAX_LENGTH+1];

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
   
    if (check_minimum_length(password) &&
        check_maximum_length(password) &&
        check_contains_lowercase(password) &&
        check_contains_uppercase(password) &&
        check_contains_number(password) &&
        check_contains_special_character(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

int check_minimum_length(char *password) {
    if (strlen(password) < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    }
    return 1;
}

int check_maximum_length(char *password) {
    if (strlen(password) > MAX_LENGTH) {
        printf("Password cannot be more than %d characters long.\n", MAX_LENGTH);
        return 0;
    }
    return 1;
}

int check_contains_lowercase(char *password) {
    char *pos = strpbrk(password, LETTERS_LOWER);
    if (pos == NULL) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    return 1;
}

int check_contains_uppercase(char *password) {
    char *pos = strpbrk(password, LETTERS_UPPER);
    if (pos == NULL) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    return 1;
}

int check_contains_number(char *password) {
    char *pos = strpbrk(password, NUMBERS);
    if (pos == NULL) {
        printf("Password must contain at least one number.\n");
        return 0;
    }
    return 1;
}

int check_contains_special_character(char *password) {
    char *pos = strpbrk(password, SPECIAL_CHARACTERS);
    if (pos == NULL) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    return 1;
}