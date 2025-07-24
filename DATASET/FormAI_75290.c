//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // Welcome message for the program
    printf("Welcome to the Cyberpunk Password Strength Checker!\n");
    printf("Please enter your desired password:\n");

    // Taking input from the user
    char password[50];
    fgets(password, 50, stdin);

    // Variables to store password criteria
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_number = false;
    bool has_special = false;

    // Looping through the password to check for criteria
    for(int i = 0; i < strlen(password); i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = true;
        }
        if(password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = true;
        }
        if(password[i] >= '0' && password[i] <= '9') {
            has_number = true;
        }
        if((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) {
            has_special = true;
        }
    }

    // Checking the password strength and giving feedback
    if(strlen(password) < 8 || !has_uppercase || !has_lowercase || !has_number || !has_special) {
        printf("Your password is weak. Please consider these criteria to make a strong password:\n");
        printf("- Password length should be at least 8 characters.\n");
        printf("- Password should contain at least one uppercase letter.\n");
        printf("- Password should contain at least one lowercase letter.\n");
        printf("- Password should contain at least one number.\n");
        printf("- Password should contain at least one special character.\n");
    } else {
        printf("Congratulations! Your password is strong and meets all of the criteria!\n");
    }

    return 0;
}