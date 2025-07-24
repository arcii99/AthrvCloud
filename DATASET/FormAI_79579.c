//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

int main()
{
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special_characters[] = "!@#$%^&*()_+";

    char password[MAX_PASSWORD_LENGTH + 1] = "";
    int password_length = MIN_PASSWORD_LENGTH + rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1);

    srand(time(NULL));

    int num_lowercase_letters = rand() % (password_length / 2);
    int num_uppercase_letters = rand() % (password_length / 2);
    int num_digits = rand() % (password_length / 2);
    int num_special_characters = password_length - num_lowercase_letters - num_uppercase_letters - num_digits;

    for (int i = 0; i < num_lowercase_letters; i++)
    {
        password[i] = lowercase_letters[rand() % 26];
    }

    for (int i = 0; i < num_uppercase_letters; i++)
    {
        password[num_lowercase_letters + i] = uppercase_letters[rand() % 26];
    }

    for (int i = 0; i < num_digits; i++)
    {
        password[num_lowercase_letters + num_uppercase_letters + i] = digits[rand() % 10];
    }

    for (int i = 0; i < num_special_characters; i++)
    {
        password[num_lowercase_letters + num_uppercase_letters + num_digits + i] = special_characters[rand() % 10];
    }

    for (int i = 0; i < password_length; i++)
    {
        int j = rand() % password_length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[password_length] = '\0';

    printf("Generated password: %s", password);

    return 0;
}