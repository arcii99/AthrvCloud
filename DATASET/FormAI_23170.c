//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

int main()
{
    int length, i, random;
    char password[MAX_PASSWORD_LENGTH + 1];

    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("This program will generate a random password for you.\n");

    do
    {
        printf("Please choose a password length between %d and %d characters: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &length);

        if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH)
        {
            printf("Invalid password length. Please try again.\n");
        }
    } while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH);

    printf("Your random password is: ");

    for (i = 0; i < length; i++)
    {
        random = rand() % 94 + 33;
        password[i] = (char)random;
        printf("%c", password[i]);
    }
    
    password[length] = '\0';

    printf("\n\nThank you for using the Secure Password Generator!\n");
    printf("Your password has been securely generated and can be used immediately.\n");

    return 0;
}