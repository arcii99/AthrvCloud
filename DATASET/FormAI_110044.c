//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generate_password(int length);

int main()
{
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    char *password = generate_password(length);

    printf("Your secure password is: %s\n", password);

    free(password);

    return 0;
}

char *generate_password(int length)
{
    const char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int alphabet_length = strlen(alphabet);

    char *password = malloc(length + 1);

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        int random_index = rand() % alphabet_length;
        char random_char = alphabet[random_index];
        password[i] = random_char;
    }

    password[length] = '\0';

    return password;
}