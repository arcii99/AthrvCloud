//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char password[12];
    int i, random;
    srand(time(0)); // seed random number generator

    printf("Welcome to the Happy Password Generator!\n");

    // Generate random password with 12 characters
    for (i = 0; i < 12; i++)
    {
        // Generates a random number 0-2 to choose what type of character to add to password
        random = rand() % 3;
        if (random == 0)
            password[i] = rand() % 26 + 'A'; // uppercase letter
        else if (random == 1)
            password[i] = rand() % 26 + 'a'; // lowercase letter
        else
            password[i] = rand() % 10 + '0'; // digit
    }

    printf("Your new password is: ");
    for (i = 0; i < 12; i++)
    {
        printf("%c", password[i]);
    }
    printf("\n");

    return 0;
}