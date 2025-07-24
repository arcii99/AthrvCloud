//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>   // For rand() and srand()
#include <time.h>     // For time()

#define PASSWORD_LENGTH 12

// Function to generate a random character from the given set
char getRandomCharacter(char set[]) {
    return set[rand() % strlen(set)];
}

// Function to generate a secure password
void generatePassword(char password[]) {
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()-_=+[]{}\\|;:'\",.<>/?";
    int i;

    srand((unsigned int) time(NULL));  // Seed the random number generator

    // Choose a random lowercase letter, uppercase letter, digit, and symbol
    password[0] = getRandomCharacter(lowercase);
    password[1] = getRandomCharacter(uppercase);
    password[2] = getRandomCharacter(digits);
    password[3] = getRandomCharacter(symbols);

    // Fill the rest of the password with random characters from the combined set
    for (i = 4; i < PASSWORD_LENGTH; i++) {
        char set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}\\|;:'\",.<>/?";
        password[i] = getRandomCharacter(set);
    }

    // Shuffle the password using Fisher–Yates shuffle algorithm
    for (i = PASSWORD_LENGTH - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    char password[PASSWORD_LENGTH + 1];  // Add 1 for null terminating character
    generatePassword(password);
    printf("Your secure password is: %s\n", password);
    return 0;
}