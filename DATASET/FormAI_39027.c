//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int count_uppercase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int count_lowercase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            count++;
        }
    }
    return count;
}

int count_numbers(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            count++;
        }
    }
    return count;
}

int count_special_chars(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!(password[i] >= 'a' && password[i] <= 'z') &&
            !(password[i] >= 'A' && password[i] <= 'Z') &&
            !(password[i] >= '0' && password[i] <= '9')) {
            count++;
        }
    }
    return count;
}

int password_strength(char *password) {
    int length = strlen(password);
    int uppercase_count = count_uppercase(password);
    int lowercase_count = count_lowercase(password);
    int number_count = count_numbers(password);
    int special_char_count = count_special_chars(password);

    int strength = 0;

    if (length >= 8 && length <= 16) {
        strength++;
    }
    if (uppercase_count >= 1 && lowercase_count >= 1) {
        strength++;
    }
    if (number_count >= 1) {
        strength++;
    }
    if (special_char_count >= 1) {
        strength++;
    }

    return strength;
}

int main() {
    char password[50];
    printf("Enter your password: ");

    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;

    int strength = password_strength(password);

    if (strength == 0) {
        printf("Your password is very weak.\n");
    } else if (strength == 1) {
        printf("Your password is weak.\n");
    } else if (strength == 2) {
        printf("Your password is okay.\n");
    } else if (strength == 3) {
        printf("Your password is strong.\n");
    } else if (strength == 4) {
        printf("Your password is very strong.\n");
    }
    
    return 0;
}