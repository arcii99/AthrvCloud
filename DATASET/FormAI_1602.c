//FormAI DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <string.h>

// Define maximum character length for password and username
#define MAX_LENGTH 32

// Declare function to check if a password is strong or not
int is_password_strong(char password[]);

// Declare function to encrypt password
void encrypt_password(char password[]);

int main() {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    int password_strength;

    // Prompt user for username and password
    printf("Enter your username: ");
    fgets(username, MAX_LENGTH, stdin);

    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);

    // Check if password is strong
    password_strength = is_password_strong(password);

    // If password is not strong enough, prompt user to change password
    if (password_strength < 10) {
        printf("\nYour password is too weak. It must contain at least 10 characters, including uppercase letters, lowercase letters, numbers, and special characters.\n");
        printf("Please enter a new password: ");
        fgets(password, MAX_LENGTH, stdin);

        // Re-check password strength after changing password
        password_strength = is_password_strong(password);

        // If password is still not strong enough, terminate program
        if (password_strength < 10) {
            printf("\nYour new password is still too weak. Program terminated. Please try again later.\n");
            return 0;
        }
    }

    // Encrypt password
    encrypt_password(password);

    // Display username and encrypted password
    printf("\nYour username is: %s", username);
    printf("Your encrypted password is: %s", password);

    return 0;
}

// Function to check if password is strong enough
int is_password_strong(char password[]) {
    int length = strlen(password);
    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special_char = 0, i;

    // Check password length
    if (length < 10) {
        return 0;
    }

    // Check password for uppercase letters, lowercase letters, numbers, and special characters
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            has_number = 1;
        }
        else {
            has_special_char = 1;
        }
    }

    // Return password strength score based on the number of requirements met
    return has_uppercase + has_lowercase + has_number + has_special_char;
}

// Function to encrypt password using basic XOR encryption algorithm
void encrypt_password(char password[]) {
    int key = 10, i;

    for (i = 0; i < strlen(password); i++) {
        password[i] ^= key;
    }
}