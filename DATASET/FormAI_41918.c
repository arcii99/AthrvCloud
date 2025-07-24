//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if password contains uppercase, lowercase, digits and special characters
bool has_special_chars(char password[]) {
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    bool has_special_char = false;
    int length = strlen(password);
    for(int i=0; i<length; i++) {
        char c = password[i];
        if(c >= 'A' && c <= 'Z') {
            has_uppercase = true;
        }
        else if(c >= 'a' && c <= 'z') {
            has_lowercase = true;
        }
        else if(c >= '0' && c <= '9') {
            has_digit = true;
        }
        else {
            has_special_char = true;
        }
    }
    return has_uppercase && has_lowercase && has_digit && has_special_char;
}

// Function to check password strength
int check_password_strength(char password[]) {
    int length = strlen(password);
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    bool has_special_char = false;
    bool has_repeated_chars = false;
    // Check if password contains uppercase, lowercase, digits and special characters
    if(has_special_chars(password)) {
        for(int i=0; i<length-2; i++) {
            // Check if password has repeated characters
            if(password[i] == password[i+1] && password[i+1] == password[i+2]) {
                has_repeated_chars = true;
                break;
            }
        }
        if(!has_repeated_chars) {
            // Check password length and assign strength
            if(length < 8) {
                return 0; // Weak password
            }
            else if(length < 12) {
                return 1; // Medium password
            }
            else {
                return 2; // Strong password
            }
        }
        else {
            return -1; // Password has repeated characters
        }
    }
    else {
        return -2; // Password has no special characters
    }
}

int main() {
    char password[50];
    printf("Enter password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character from input
    int strength = check_password_strength(password);
    if(strength == 0) {
        printf("Weak password\n");
    }
    else if(strength == 1) {
        printf("Medium password\n");
    }
    else if(strength == 2) {
        printf("Strong password\n");
    }
    else if(strength == -1) {
        printf("Password has repeated characters\n");
    }
    else if(strength == -2) {
        printf("Password has no special characters\n");
    }
    return 0;
}