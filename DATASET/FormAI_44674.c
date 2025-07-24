//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 10 // Change this value to set desired length of password

// Function to generate a random character
char generateRandomChar() {
    char randomChar;
    do {
        randomChar = rand() % 128;
    } while((randomChar < 48 || randomChar > 57) && (randomChar < 65 || randomChar > 90) && (randomChar < 97 || randomChar > 122)); // Only accept alphanumeric characters
    return randomChar;
}

int main() {
    srand(time(NULL));

    char password[PASSWORD_LENGTH+1]; // Null terminated string
    memset(password, 0, sizeof(password)); // Initialize password as empty string

    // Generate random password
    for(int i=0; i<PASSWORD_LENGTH; i++) {
        password[i] = generateRandomChar();
    }

    // Output password
    printf("Generated Password: %s\n", password);

    return 0;
}