//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_secure_password(int password_length);

int main()
{
    int password_length;

    printf("Enter password length (recommended minimum: 10 characters): ");
    scanf("%d", &password_length);

    generate_secure_password(password_length);

    return 0;
}

void generate_secure_password(int password_length)
{
    char password[password_length];
    const char* lower_case_alphabets = "abcdefghijklmnopqrstuvwxyz";
    const char* upper_case_alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* numbers = "0123456789";
    const char* special_characters = "!@#$%^&*()[]{}<>,.?/|";
    const char* character_set =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()[]{}<>,.?/|";
    int i, random_number, character_set_length = strlen(character_set);

    srand(time(NULL));

    for (i = 0; i < password_length; i++)
    {
        random_number = rand() % character_set_length;
        password[i] = character_set[random_number];
    }

    password[password_length] = '\0';

    printf("\nYour secure password is: %s\n", password);
}