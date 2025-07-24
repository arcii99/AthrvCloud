//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandom(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a Secure Password
void generateSecurePassword()
{
    int lowercase = 0, uppercase = 0, digit = 0, symbol = 0;
    char password[15];
    srand(time(NULL));

    // Loop to generate a password with at least one lowercase letter, one uppercase letter, one digit, and one symbol
    while (lowercase == 0 || uppercase == 0 || digit == 0 || symbol == 0)
    {
        // Loop to generate a random password
        for (int i = 0; i < 15; i++)
        {
            int type = generateRandom(1, 4);

            switch (type)
            {
                case 1:
                    password[i] = generateRandom(65, 90);  // Uppercase
                    uppercase = 1;
                    break;
                case 2:
                    password[i] = generateRandom(97, 122); // Lowercase
                    lowercase = 1;
                    break;
                case 3:
                    password[i] = generateRandom(48, 57);  // Digit
                    digit = 1;
                    break;
                case 4:
                    password[i] = generateRandom(33, 47);  // Symbol
                    symbol = 1;
                    break;
            }
        }
    }

    printf("Your Secure Password is: %s\n", password);
}

// Main function to execute the program
int main()
{
    generateSecurePassword();
    return 0;
}