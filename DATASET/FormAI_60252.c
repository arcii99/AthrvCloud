//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool has_digit(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

bool has_uppercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) {
            return true;
        }
    }
    return false;
}

bool has_lowercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (islower(str[i])) {
            return true;
        }
    }
    return false;
}

bool has_special_char(char* str) {
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', ':', ';', '<', '>', '?', '/', '|'};
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < sizeof(special_chars); j++) {
            if (str[i] == special_chars[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char password[100];
    while (true) {
        printf("Enter password to check its strength: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0; // remove newline character from input
        
        if (strlen(password) < 8) {
            printf("Password is too short. Please enter a password that is at least 8 characters long.\n\n");
        } else if (!has_digit(password)) {
            printf("Password is weak. Please use at least one number in your password.\n\n");
        } else if (!has_uppercase(password)) {
            printf("Password is weak. Please use at least one uppercase letter in your password.\n\n");
        } else if (!has_lowercase(password)) {
            printf("Password is weak. Please use at least one lowercase letter in your password.\n\n");
        } else if (!has_special_char(password)) {
            printf("Password is weak. Please use at least one special character in your password.\n\n");
        } else {
            printf("Password is strong!\n");
            break;
        }
    }
    return 0;
}