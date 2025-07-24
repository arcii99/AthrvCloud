//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char *generate_password(int length);
int is_valid_password(char *password);

int main()
{
    int password_length;
    char *password;

    srand(time(0));

    printf("Password length (min %d, max %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Password length should be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        printf("Password length (min %d, max %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    }

    password = generate_password(password_length);

    printf("Generated password: %s\n", password);

    if (is_valid_password(password))
    {
        printf("Password is valid.\n");
    }
    else
    {
        printf("Password is not valid.\n");
    }

    free(password);

    return 0;
}

char *generate_password(int length)
{
    char *password = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        int character_type = rand() % 3;

        if (character_type == 0)
        {
            // Lowercase letter
            password[i] = (char)(rand() % 26 + 'a');
        }
        else if (character_type == 1)
        {
            // Uppercase letter
            password[i] = (char)(rand() % 26 + 'A');
        }
        else
        {
            // Digit
            password[i] = (char)(rand() % 10 + '0');
        }
    }

    password[length] = '\0';

    return password;
}

int is_valid_password(char *password)
{
    int has_lowercase_letter = 0;
    int has_uppercase_letter = 0;
    int has_digit = 0;

    int length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lowercase_letter = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_uppercase_letter = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_digit = 1;
        }
    }

    if (has_lowercase_letter && has_uppercase_letter && has_digit)
    {
        return 1;
    }

    return 0;
}