//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length);

int main()
{
    int length;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the length of the password you would like to generate: ");
    scanf("%d", &length);

    printf("Generating a %d character secure password...\n", length);

    generatePassword(length);

    printf("\nYour secure password has been generated!\n");

    return 0;
}

void generatePassword(int length)
{
    srand(time(0));

    char password[length + 1];

    for (int i = 0; i < length; i++)
    {
        int randomChar = rand() % 94 + 33;
        password[i] = (char)randomChar;
    }

    password[length] = '\0';

    printf("\nYour new password is: %s\n", password);
}