//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define all possible characters for the password
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_characters[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?\\";
    char password[PASSWORD_LENGTH + 1];

    // Initialize the password to all zeros
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = '0';
    }
    password[PASSWORD_LENGTH] = '\0';

    // Randomly generate characters for the password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int category = rand() % 4;  // Choose a category of characters
        switch (category) {
            case 0:  // Lowercase letters
                password[i] = lowercase_letters[rand() % 26];
                break;
            case 1:  // Uppercase letters
                password[i] = uppercase_letters[rand() % 26];
                break;
            case 2:  // Numbers
                password[i] = numbers[rand() % 10];
                break;
            case 3:  // Special characters
                password[i] = special_characters[rand() % 23];
                break;
        }
    }

    printf("Your secure password is: %s\n", password);

    return 0;
}