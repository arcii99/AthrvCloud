//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

// Function to generate a random character
char randomChar() {
    int r;
    char c;
    // Generate a random integer between 0 and 2
    r = rand() % 3;
    // Generate a random character based on the random integer
    if (r == 0) {
        c = rand() % 10 + '0'; // Generate a digit
    } else if (r == 1) {
        c = rand() % 26 + 'a'; // Generate a lowercase letter
    } else {
        c = rand() % 26 + 'A'; // Generate an uppercase letter
    }
    return c;
}

// Function to generate a secure password
void generatePassword(char* password) {
    int i;
    // Set random seed based on current time
    srand(time(NULL));
    // Generate random characters for the password
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = randomChar();
    }
    // Terminate the password string
    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    char password[PASSWORD_LENGTH + 1];
    // Generate a secure password
    generatePassword(password);
    // Print the secure password
    printf("Secure password: %s\n", password);
    return 0;
}