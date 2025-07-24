//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: irregular
//Secure Password Generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char password[16];  //password length is set to 16 characters
    int i, n;

    srand(time(NULL));  //seeding the random number generator with time

    printf("Generating password...\n");
    printf("Your new password is: ");

    for (i = 0; i < 16; i++)  //loop to generate 16 random characters
    {
        n = rand() % 94 + 33;  //ASCII range for printable characters

        if (n > 47 && n < 58)  //if the character is a digit, choose another one
        {
            i--;
            continue;
        }

        password[i] = n;  //add the character to the password
        printf("%c", password[i]);
    }

    printf("\n\nPlease save this password in a safe place.\n");

    return 0;
}