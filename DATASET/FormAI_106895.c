//FormAI DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if the password matches the criteria
int validatePassword(char password[])
{
    //Check length of the password
    if(strlen(password) < 8)
    {
        return 0;
    }
    //Check if it has at least one digit (0-9)
    int i;
    int hasDigit = 0;
    for(i = 0; i < strlen(password); i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            hasDigit = 1;
            break;
        }
    }
    if(!hasDigit)
    {
        return 0;
    }
    //Check if it has at least one lowercase letter (a-z)
    int hasLowercase = 0;
    for(i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowercase = 1;
            break;
        }
    }
    if(!hasLowercase)
    {
        return 0;
    }
    //Check if it has at least one uppercase letter (A-Z)
    int hasUppercase = 0;
    for(i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = 1;
            break;
        }
    }
    if(!hasUppercase)
    {
        return 0;
    }
    //Check if it has at least one special character
    int hasSpecialChar = 0;
    char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ';', ':', '\'', '\"', ',', '.', '<', '>'};
    for(i = 0; i < strlen(password); i++)
    {
        if(strchr(specialChars, password[i]) != NULL)
        {
            hasSpecialChar = 1;
            break;
        }
    }
    if(!hasSpecialChar)
    {
        return 0;
    }
    //If all criteria are met, return true
    return 1;
}

int main()
{
    char username[20];
    char password[20];
    char confirm[20];
    int attempts = 3;
    
    printf("Welcome to the post-apocalyptic password manager!\n");
    printf("Please create a new username and password.\n");
    printf("Username (max 20 characters): ");
    scanf("%s", username);
    do
    {
        printf("Password (min 8 characters, at least one digit, one lowercase letter, one uppercase letter, one special character): ");
        scanf("%s", password);
        printf("Confirm password: ");
        scanf("%s", confirm);
        if(strcmp(password, confirm) == 0)
        {
            if(validatePassword(password))
            {
                printf("Password successfully set!\n");
                return 0;
            }
            else
            {
                printf("Password does not meet criteria, please try again.\n");
            }
        }
        else
        {
            printf("Passwords do not match, please try again.\n");
            attempts--;
            printf("You have %d attempts remaining.\n", attempts);
        }
    } while(attempts > 0);
    printf("You have been locked out of your account. Please contact customer support for assistance.\n");
    return 0;
}