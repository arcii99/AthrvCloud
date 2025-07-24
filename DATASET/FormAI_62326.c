//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char generateRandomChar() {
    /*
     * This function generates a random character in the range of ASCII '!' to '~' characters.
     * These characters belong to the printable ASCII range and can be safely used in password generation.
     */
    return (char) ('!' + rand() % 94);
}

void generatePassword(char *password) {
    /*
     * This function generates a secure password based on the given length.
     * It calls the generateRandomChar() function to insert a random character at each index of the password array.
     */
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomChar();
    }
    password[PASSWORD_LENGTH] = '\0'; // Null terminate the string
}

int main() {
    // Set the random seed based on the current time
    srand((unsigned) time(NULL));
    
    char password[PASSWORD_LENGTH+1]; // Password array with space for null terminator
    generatePassword(password); // Generate a password
    printf("Your new secure password is: %s\n", password);

    return 0;
}