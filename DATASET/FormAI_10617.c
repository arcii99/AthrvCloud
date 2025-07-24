//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macros
#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define MAX_TRIES 3

// Define global variables
int tries = MAX_TRIES;

// Function to check password strength
int check_password_strength(char password[])
{
    int length = strlen(password);

    // Check if password is too short or too long
    if(length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH)
    {
        printf("Password length must be between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 0;
    }

    // Check if password contains uppercase and lowercase letters
    int contains_uppercase = 0;
    int contains_lowercase = 0;
    for(int i = 0; i < length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            contains_uppercase = 1;
        }
        else if(password[i] >= 'a' && password[i] <= 'z')
        {
            contains_lowercase = 1;
        }
    }
    if(!contains_uppercase || !contains_lowercase)
    {
        printf("Password must contain both uppercase and lowercase letters.\n");
        return 0;
    }

    // Check if password contains at least one digit and one special character
    int contains_digit = 0;
    int contains_special_character = 0;
    for(int i = 0; i < length; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            contains_digit = 1;
        }
        else if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~'))
        {
            contains_special_character = 1;
        }
    }
    if(!contains_digit || !contains_special_character)
    {
        printf("Password must contain at least one digit and one special character.\n");
        return 0;
    }

    return 1;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    while(tries > 0)
    {
        // Prompt user for input
        printf("Please enter your password: ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);

        // Remove newline character from input
        password[strcspn(password, "\n")] = 0;

        if(check_password_strength(password))
        {
            printf("Password is strong!\n");
            break;
        }

        printf("Password is not strong. Please try again.\n");

        tries--;
        if(tries > 0)
        {
            printf("You have %d attempts left.\n", tries);
        }
    }

    if(tries == 0)
    {
        printf("You have run out of attempts.\n");
    }

    return 0;
}