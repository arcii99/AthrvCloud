//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

// Function to generate a random character
char generate_random_char() {
    return (char)((rand() % 94) + 33);
}

// Function to generate a secure password
void generate_password(char* password, int length) {
    for(int i = 0; i < length; i++) {
        password[i] = generate_random_char();
    }
    password[length] = '\0';
}

// Function to check if the password is secure or not
int is_secure_password(char* password) {
    int len = strlen(password);
    int has_lowercase = 0, has_uppercase = 0, has_digit = 0, has_special = 0;
    for(int i = 0; i < len; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if(password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if(password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    return (has_lowercase && has_uppercase && has_digit && has_special);
}

// Main function
int main() {
    srand(time(0)); // Set seed for rand() function
    char password[MAX_PASSWORD_LENGTH + 1] = {0}; // Initialize password array with zeroes
    int password_length = 0;
    do {
        password_length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH; // Generate a random length for password
        generate_password(password, password_length); // Generate a password of the given length
    } while(!is_secure_password(password)); // Repeat until a secure password is generated
    printf("Your secure password is: %s\n", password); // Print the password
    return 0;
}