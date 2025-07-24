//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function to check if a given password is strong or not
int isStrong(char* password)
{
    int len = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    // Checking if password length is between 8 and 20 characters
    if (len < 8 || len > 20)
        return 0;

    // Checking if password has at least one lowercase letter, one uppercase letter, one digit and one special character
    for (int i = 0; i < len; i++) 
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            hasLower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    if (hasLower && hasUpper && hasDigit && hasSpecial)
        return 1;
    else
        return 0;
}

// Function to validate user input
void validateInput(char* password, int len)
{
    int valid = 1;

    // Checking if password contains any whitespace characters
    for (int i = 0; i < len; i++)
    {
        if (password[i] == ' ' || password[i] == '\n' || password[i] == '\t')
        {
            valid = 0;
            break;
        }
    }

    // If password contains whitespace characters, prompting user to enter password again
    if (!valid)
    {
        printf("\nPassword cannot contain whitespace characters. Please enter a valid password: ");
        fgets(password, 100, stdin);
        len = strlen(password);
        validateInput(password, len);
    }
}

int main()
{
    char password[100];
    int len;

    printf("Enter a password between 8 and 20 characters: ");
    fgets(password, 100, stdin);
    len = strlen(password);

    // Validating user input
    validateInput(password, len);

    // Checking if password is strong or not
    if (isStrong(password))
        printf("\nPassword is strong!");
    else
        printf("\nPassword is not strong!");

    return 0;
}