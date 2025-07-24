//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main()
{
    char password[PASSWORD_LENGTH + 1];
    int i, randomNum;

    srand(time(NULL));

    // Generate a random password
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        randomNum = rand() % 94 + 33; // Generate random number from 33 to 126 (ASCII table)
        password[i] = (char)randomNum;
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("Secure password: %s\n", password);

    return 0;
}