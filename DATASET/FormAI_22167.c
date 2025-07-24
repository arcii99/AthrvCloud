//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

// Function to generate random password
void generatePassword(char* password)
{
    int i;
    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Loop through each character in password
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        int random = rand() % 3;
        // Generate a random character
        switch (random)
        {
            case 0:
                password[i] = rand() % 26 + 'a'; // lowercase letter
                break;
            case 1:
                password[i] = rand() % 26 + 'A'; // uppercase letter
                break;
            case 2:
                password[i] = rand() % 10 + '0'; // digit
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    char password[PASSWORD_LENGTH + 1];
    generatePassword(password);
    printf("Generated Password: %s\n", password);
    return 0;
}