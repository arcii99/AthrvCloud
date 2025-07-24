//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

char *generate_password()
{
    // Define the character set for the password
    char character_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#$%&";

    // Get the length of the character set
    int character_set_length = strlen(character_set);

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Allocate memory for the password
    char *password = malloc(sizeof(char) * PASSWORD_LENGTH + 1);

    // Generate random characters for the password
    for (int i = 0; i < PASSWORD_LENGTH; ++i)
    {
        password[i] = character_set[rand() % character_set_length];
        if (i==0)
            password[i]=toupper(password[i]);
    }

    // Null terminate the password
    password[PASSWORD_LENGTH] = '\0';

    // Return the password
    return password;
}

int main()
{
    // Generate and print a new password
    printf("Your new secure password is: %s", generate_password());

    return 0;
}