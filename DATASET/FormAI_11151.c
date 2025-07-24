//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MIN_ALPHABETS_COUNT 4
#define MIN_DIGITS_COUNT 2
#define MIN_SPECIAL_CHARS_COUNT 1

int is_valid_password(char *password);

int main()
{
    char password[100];
    printf("Enter a password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character
    if (is_valid_password(password))
    {
        printf("The password is strong. You can use it.\n");
    }
    else
    {
        printf("The password is weak. Please choose a stronger password.\n");
    }
}

int is_valid_password(char *password)
{
    int length = strlen(password);
    int alphabets_count = 0;
    int digits_count = 0;
    int special_chars_count = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        if (isalpha(*(password + i)))
        {
            alphabets_count++;
        }
        else if (isdigit(*(password + i)))
        {
            digits_count++;
        }
        else
        {
            special_chars_count++;
        }
    }

    if (length < MIN_PASSWORD_LENGTH)
    {
        printf("The password should be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 0;
    }
    
    if (alphabets_count < MIN_ALPHABETS_COUNT)
    {
        printf("The password should contain at least %d alphabets.\n", MIN_ALPHABETS_COUNT);
        return 0;
    }

    if (digits_count < MIN_DIGITS_COUNT)
    {
        printf("The password should contain at least %d digits.\n", MIN_DIGITS_COUNT);
        return 0;
    }

    if (special_chars_count < MIN_SPECIAL_CHARS_COUNT)
    {
        printf("The password should contain at least %d special characters.\n", MIN_SPECIAL_CHARS_COUNT);
        return 0;
    }

    return 1;
}