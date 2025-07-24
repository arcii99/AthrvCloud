//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LEN 10 // Password length

// Function to generate a random uppercase letter
char getRandomUppercase()
{
    return rand() % 26 + 'A'; // ASCII value of A is 65.
}

// Function to generate a random lowercase letter
char getRandomLowercase()
{
    return rand() % 26 + 'a'; // ASCII value of a is 97.
}

// Function to generate a random number
char getRandomNumber()
{
    return rand() % 10 + '0'; // ASCII value of 0 is 48.
}

// Function to generate a random special character
char getRandomSpecialChar()
{
    char specialChars[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_' };

    return specialChars[rand() % 12]; // Randomly select a special character from the array.
}

// Function to generate a secure password
void generatePassword(char *password)
{
    int i, j;

    srand(time(0)); // Seed the random number generator with the current time.

    // Generate a secure password by randomly selecting upper and lowercase letters, numbers, and special characters.
    for (i = 0; i < PASSWORD_LEN; i++) {
        switch (rand() % 4) {
            case 0:
                password[i] = getRandomUppercase();
                break;
            case 1:
                password[i] = getRandomLowercase();
                break;
            case 2:
                password[i] = getRandomNumber();
                break;
            case 3:
                password[i] = getRandomSpecialChar();
                break;
        }
    }

    // Replace one lowercase letter with an uppercase letter.
    j = rand() % PASSWORD_LEN;
    if (password[j] >= 'a' && password[j] <= 'z') {
        password[j] = getRandomUppercase();
    }

    // Replace one number with a special character.
    j = rand() % PASSWORD_LEN;
    if (password[j] >= '0' && password[j] <= '9') {
        password[j] = getRandomSpecialChar();
    }
}

int main()
{
    char password[PASSWORD_LEN + 1]; // Declare a character array to store the password.

    generatePassword(password); // Call the function to generate a secure password.

    printf("Your secure password is: %s\n", password);

    return 0;
}