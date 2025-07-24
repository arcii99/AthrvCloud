//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    //Declare variables
    char password[50], c;
    int length = 0, lowercase = 0, uppercase = 0, digit = 0, symbol = 0;
    float score = 0, totalScore = 0;
    
    //Instructions for user
    printf("Enter a password: ");
    
    //Get user input
    while ((c = getchar()) != '\n' && length < 50)
    {
        password[length++] = c;
    }
    
    //Check password length
    if (length >= 8) 
    {
        score += 0.5;
        totalScore += 0.5;
    }
    else
    {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    
    //Check for lowercase, uppercase, digit, and symbol
    for (int i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            lowercase++;
        }
        else if (isupper(password[i]))
        {
            uppercase++;
        }
        else if (isdigit(password[i]))
        {
            digit++;
        }
        else if (ispunct(password[i]) || isspace(password[i]))
        {
            symbol++;
        }
    }
    
    //Calculate scores
    if (lowercase > 0)
    {
        score += 0.5;
        totalScore += 0.5;
    }
    if (uppercase > 0)
    {
        score += 0.5;
        totalScore += 0.5;
    }
    if (digit > 0)
    {
        score += 0.5;
        totalScore += 0.5;
    }
    if (symbol > 0)
    {
        score += 1;
        totalScore += 1;
    }
    
    //Check scores
    if (score < 2)
    {
        printf("Password not strong enough.\n");
        return 0;
    }
    else if (score < 3)
    {
        printf("Password could be stronger.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }
    
    //Calculate strength percentage
    float strength = (totalScore / 3) * 100;
    
    //Print strength percentage
    printf("Strength: %.2f%%\n", strength);
    
    return 0;
}