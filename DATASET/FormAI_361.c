//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

// function to check if the password is strong or not
int isPasswordStrong(char* password)
{
    // set flag variables to false
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
    int passwordLength = strlen(password);

    // check each character in password
    for (int i = 0; i < passwordLength; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowercase = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            hasDigit = 1;
        }
        else
        {
            hasSpecialChar = 1;
        }
    }

    // count the number of requirements fulfilled
    int requirementsFulfilled = hasLowercase + hasUppercase + hasDigit + hasSpecialChar;

    // print the strength of the password
    if (passwordLength < 8 || requirementsFulfilled < 3)
    {
        printf("Password is weak\n");
        return 0;
    }
    else if (passwordLength >= 8 && requirementsFulfilled == 3)
    {
        printf("Password is strong\n");
        return 1;
    }
    else if (passwordLength >= 12 && requirementsFulfilled == 4)
    {
        printf("Password is very strong\n");
        return 2;
    }
    else
    {
        printf("Password is weak\n");
        return 0;
    }
}

int main()
{
    char password[100];

    printf("Enter password: ");
    fgets(password, 100, stdin);

    // remove newline character from password
    password[strcspn(password, "\n")] = 0;

    int passwordStrength = isPasswordStrong(password);

    // do something based on password strength
    switch (passwordStrength)
    {
        case 0:
            printf("Please choose a stronger password!\n");
            break;
        case 1:
            printf("Good job! Your password is strong enough\n");
            break;
        case 2:
            printf("Wow! Your password is very strong\n");
            break;
        default:
            printf("Something went wrong. Please try again!\n");
            break;
    }

    return 0;
}