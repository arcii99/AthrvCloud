//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20 // Defines the maximum length for a password
#define NUMBER_OF_CHARACTERS 62 // Defines the number of possible characters to use for a password

// Generates a random password and stores it in the given password array
void generatePassword(char *password) {
    // Define possible characters to use for password
    const char *possibleCharacters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int passwordLength = rand() % MAX_PASSWORD_LENGTH + 8; // Randomly choose a length between 8 and MAX_PASSWORD_LENGTH

    for (int i = 0; i < passwordLength; i++) {
        password[i] = possibleCharacters[rand() % NUMBER_OF_CHARACTERS]; // Choose a random character from the possible characters
    }

    password[passwordLength] = '\0'; // Terminate the string
}

int main() {
    srand(time(NULL)); // Initialize the random number generator with the current time

    int numberOfPasswords;
    printf("How many passwords would you like to generate? ");
    scanf("%d", &numberOfPasswords);

    for (int i = 0; i < numberOfPasswords; i++) {
        char password[MAX_PASSWORD_LENGTH + 1]; // Define password array with room for a terminating null character
        generatePassword(password);
        printf("%s\n", password);
    }

    return 0;
}