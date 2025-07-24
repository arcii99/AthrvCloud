//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 20

int main()
{
    char password[MAX_PASSWORD_LENGTH + 1]; // adding 1 to account for null-terminator
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_char = 0; // initialize password strength variables to 0
    int num_char_types = 0; // to keep track of how many character types the password contains
    int password_length = 0; // to keep track of password length
    
    printf("Please enter a password (maximum of %d characters):\n", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin); // read in password from user and include null-terminator
    
    password_length = strlen(password) - 1; // subtract 1 to not include the null-terminator
    
    // loop through each character in the password and check if it belongs to a certain character type
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_uppercase = 1;
            num_char_types++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lowercase = 1;
            num_char_types++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_digit = 1;
            num_char_types++;
        }
        else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*')
        {
            has_special_char = 1;
            num_char_types++;
        }
    }
    
    // check the strength of the password based on number of character types and length
    if (num_char_types < 3 || password_length < 8)
    {
        printf("This password is too weak.\n");
        printf("Please include a minimum of 8 characters and at least 3 of the following character types:\n");
        printf("- Uppercase letters\n");
        printf("- Lowercase letters\n");
        printf("- Numbers\n");
        printf("- Special characters (!,@,#,$,%,&,*)\n");
    }
    else if (num_char_types == 3 && password_length >= 8)
    {
        printf("This password is moderately strong.\n");
    }
    else if (num_char_types >= 4 && password_length >= 8)
    {
        printf("This password is very strong.\n");
    }
    
    return 0;
}