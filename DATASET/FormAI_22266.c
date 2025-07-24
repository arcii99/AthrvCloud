//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
bool checkLength(char password[]);
bool checkUpperCase(char password[]);
bool checkLowerCase(char password[]);
bool checkDigits(char password[]);
bool checkSpecialChars(char password[]);

int main()
{
    char password[100];
    int strengthScore = 0;
    
    printf("Enter password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character
    
    if(checkLength(password))
    {
        strengthScore++;
    }
    if(checkUpperCase(password))
    {
        strengthScore++;
    }
    if(checkLowerCase(password))
    {
        strengthScore++;
    }
    if(checkDigits(password))
    {
        strengthScore++;
    }
    if(checkSpecialChars(password))
    {
        strengthScore++;
    }
    
    // Print password strength score
    switch(strengthScore)
    {
        case 0:
        case 1:
            printf("Password strength: weak\n");
            break;
        case 2:
        case 3:
            printf("Password strength: medium\n");
            break;
        case 4:
        case 5:
            printf("Password strength: strong\n");
            break;
    }
    
    return 0;
}

bool checkLength(char password[])
{
    int length = strlen(password);
    
    if(length >= 8 && length <= 20)
    {
        return true;
    }
    else
    {
        printf("Password must be between 8 and 20 characters in length.\n");
        return false;
    }
}

bool checkUpperCase(char password[])
{
    int length = strlen(password);
    
    for(int i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            return true;
        }
    }
    
    printf("Password must contain at least one uppercase letter.\n");
    return false;
}

bool checkLowerCase(char password[])
{
    int length = strlen(password);
    
    for(int i = 0; i < length; i++)
    {
        if(islower(password[i]))
        {
            return true;
        }
    }
    
    printf("Password must contain at least one lowercase letter.\n");
    return false;
}

bool checkDigits(char password[])
{
    int length = strlen(password);
    
    for(int i = 0; i < length; i++)
    {
        if(isdigit(password[i]))
        {
            return true;
        }
    }
    
    printf("Password must contain at least one digit.\n");
    return false;
}

bool checkSpecialChars(char password[])
{
    int length = strlen(password);
    char specialChars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < strlen(specialChars); j++)
        {
            if(password[i] == specialChars[j])
            {
                return true;
            }
        }
    }
    
    printf("Password must contain at least one special character.\n");
    return false;
}