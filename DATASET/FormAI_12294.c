//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define NUM_USERS 1000

char *generate_password()
{
    char *password = malloc(sizeof(char) * (PASSWORD_LENGTH + 1));
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]|;:<>,.?/";

    srand(time(NULL));
    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        int index = rand() % (sizeof(characters) - 1);
        password[i] = characters[index];
    }

    password[PASSWORD_LENGTH] = '\0';
    return password;
}

int main()
{
    char *passwords[NUM_USERS];

    for (int i = 0; i < NUM_USERS; i++)
    {
        passwords[i] = generate_password();
        printf("User %d: %s\n", i+1, passwords[i]);
    }

    for (int i = 0; i < NUM_USERS; i++)
    {
        free(passwords[i]);
    }

    return 0;
}