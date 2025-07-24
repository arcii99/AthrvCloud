//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];

    printf("Enter a password: ");
    fgets(password, 50, stdin);

    // Puzzle 1: Check if password is made up of only lowercase letters
    int lowercase_count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase_count++;
        }
    }
    if(lowercase_count == strlen(password)-1)
    {
        printf("Password is too weak - must contain at least one uppercase letter and one number.\n");
        return 0;
    }

    // Puzzle 2: Check if password has at least one uppercase letter
    int uppercase_count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase_count++;
        }
    }
    if(uppercase_count == 0)
    {
        printf("Password is too weak - must contain at least one uppercase letter.\n");
        return 0;
    }

    // Puzzle 3: Check if password has at least one number
    int number_count = 0;
    for(int i=0; i<strlen(password); i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            number_count++;
        }
    }
    if(number_count == 0)
    {
        printf("Password is too weak - must contain at least one number.\n");
        return 0;
    }

    // Puzzle 4: Check if password has at least one special character
    int special_count = 0;
    char special_chars[] = "!@#$%^&*()_+{}[]|:;<>,.?/~`";
    for(int i=0; i<strlen(password); i++)
    {
        for(int j=0; j<strlen(special_chars); j++)
        {
            if(password[i] == special_chars[j])
            {
                special_count++;
                break;
            }
        }
    }
    if(special_count == 0)
    {
        printf("Password is too weak - must contain at least one special character.\n");
        return 0;
    }

    // Puzzle 5: Check if password contains consecutive numbers
    for(int i=0; i<strlen(password)-1; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            if(password[i+1] >= '0' && password[i+1] <= '9')
            {
                printf("Password is too weak - cannot contain consecutive numbers.\n");
                return 0;
            }
        }
    }

    // Puzzle 6: Check if password is a palindrome
    int is_palindrome = 1;
    int length = strlen(password)-1;
    for(int i=0; i<length/2; i++)
    {
        if(password[i] != password[length-i-1])
        {
            is_palindrome = 0;
            break;
        }
    }
    if(is_palindrome)
    {
        printf("Password is too weak - cannot be a palindrome.\n");
        return 0;
    }

    // Puzzle 7: Check if password is a sequence of repeated characters
    int is_repeating = 1;
    for(int i=0; i<strlen(password)-1; i++)
    {
        if(password[i] != password[i+1])
        {
            is_repeating = 0;
            break;
        }
    }
    if(is_repeating)
    {
        printf("Password is too weak - cannot be a sequence of repeated characters.\n");
        return 0;
    }

    // If password passes all checks, it is considered strong
    printf("Password is strong!\n");
    return 0;
}