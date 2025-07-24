//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a password is strong
int check_password_strength(char password[]) {
    int length = strlen(password);
    int uppercase_letters = 0, lowercase_letters = 0;
    int digits = 0, special_characters = 0;

    // Check if the password has at least 8 characters
    if (length < 8) {
        return 0;
    }

    // Loop through each character in the password
    for (int i = 0; i < length; i++) {
        char c = password[i];

        // Check if the character is an uppercase letter
        if (isupper(c)) {
            uppercase_letters++;
        }
          
         // Check if the character is a lowercase letter
        else if (islower(c)) {
            lowercase_letters++;
        }
          
        // Check if the character is a digit
        else if (isdigit(c)) {
            digits++;
        }
          
        // Check if the character is a special character
        else {
            special_characters++;
        }
    }

    // Check if all criteria are met
    if (uppercase_letters >= 1 && lowercase_letters >= 1 && digits >= 1 
        && special_characters >= 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char password[100];

    // Get password from the user
    printf("Enter a password: ");
    fgets(password, 100, stdin);

    // Remove the newline character from the end of the password
    password[strcspn(password, "\n")] = 0;

    // Check if the password is strong
    int is_strong = check_password_strength(password);

    if (is_strong) {
        printf("Password is strong!\n");
    }
    else {
        printf("Password is weak.\n");
    }

    return 0;
}