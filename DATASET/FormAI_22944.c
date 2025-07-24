//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// function to check if password contains uppercase letter(s)
bool has_uppercase(char *password) {
    for(int i = 0; i < strlen(password); i++) {
        if(isupper(password[i])) {
            return true;
        }
    }
    return false;
}

// function to check if password contains lowercase letter(s)
bool has_lowercase(char *password) {
    for(int i = 0; i < strlen(password); i++) {
        if(islower(password[i])) {
            return true;
        }
    }
    return false;
}

// function to check if password contains digit(s)
bool has_digit(char *password) {
    for(int i = 0; i < strlen(password); i++) {
        if(isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// function to check if password contains special character(s)
bool has_special(char *password) {
    for(int i = 0; i < strlen(password); i++) {
        if(!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// function to check if password satisfies all the criteria (at least one uppercase, one lowercase, one digit, and one special character)
bool is_strong_password(char *password) {
    if(strlen(password) < 8) {
        return false; // password is too short
    }
    if(!has_uppercase(password) || !has_lowercase(password) || !has_digit(password) || !has_special(password)) {
        return false; // password does not have all the required criteria
    }
    return true; // password satisfies all the criteria
}

int main() {
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);
    // remove newline character from input
    password[strcspn(password, "\n")] = 0;
    if(is_strong_password(password)) {
        printf("Your password is strong.\n");
    }
    else {
        printf("Your password is not strong enough. Please enter a password with at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
    return 0;
}