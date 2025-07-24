//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generatePassword(int length) {
    // Define character set for password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";

    // Get length of character set
    int charsetLength = sizeof(charset) - 1;

    // Seed random number generator
    srand((unsigned int) time(NULL));

    // Initialize password
    char password[length];

    // Fill password with random characters from character set
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }

    // Terminate password with null character
    password[length] = '\0';

    // Print password
    printf("Secure Password: %s\n", password);
}

int main() {
    // Initialize variables
    int passwordLength = 0;

    // Prompt user for password length
    printf("Enter password length: ");
    scanf("%d", &passwordLength);

    // Generate password of given length
    if (passwordLength >= 8) {
        generatePassword(passwordLength);
    } else {
        printf("Password must be at least 8 characters long.\n");
    }

    return 0;
}