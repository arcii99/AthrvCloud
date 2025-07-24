//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surrealist-style Secure Password Generator

int main()
{
    // Seed the random number generator
    srand(time(0));

    char vowels[5] = {'a', 'e', 'i', 'o', 'u'}; // Used for random vowels
    char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'}; // Used for random consonants
    char specialChars[7] = {'!', '@', '#', '$', '%', '^', '&'}; // Used for random special characters

    // Declare variables
    int length;
    char password[101] = {'\0'}; // Initialize array with null terminators
    
    printf("Password length: "); // User input
    scanf("%d", &length);

    // Generate the password
    for (int i = 0; i < length; i++)
    {
        // Randomly choose a character type
        int charType = rand() % 3;

        if (charType == 0)
        {
            // Random vowel
            password[i] = vowels[rand() % 5];
        }
        else if (charType == 1)
        {
            // Random consonant
            password[i] = consonants[rand() % 21];
        }
        else
        {
            // Random special character
            password[i] = specialChars[rand() % 7];
        }
    }

    printf("Surreal secure password generated: %s\n", password);

    return 0;
}