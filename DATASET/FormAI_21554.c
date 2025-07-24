//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, has_uppercase, has_lowercase, has_digit, has_special;
    int strength = 0;
    
    printf("Enter password: ");
    fgets(password, 100, stdin);
    length = strlen(password) - 1; // remove newline character
    
    for(int i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            has_uppercase = 1;
        }
        else if(islower(password[i]))
        {
            has_lowercase = 1;
        }
        else if(isdigit(password[i]))
        {
            has_digit = 1;
        }
        else
        {
            has_special = 1;
        }
    }
    
    // Calculate password strength 
    if(length < 8)
    {
        strength = 1;
    }
    else if(length >= 8 && length <= 12)
    {
        strength = 2;
    }
    else
    {
        strength = 3;
    }
    
    if(has_uppercase && has_lowercase && has_digit && has_special)
    {
        strength = 4;
    }
    
    // Print password strength
    switch(strength)
    {
        case 1:
            printf("Password strength: Weak\n");
            break;
        case 2:
            printf("Password strength: Medium\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        case 4:
            printf("Password strength: Very Strong\n");
            break;
    }
    
    return 0;
}