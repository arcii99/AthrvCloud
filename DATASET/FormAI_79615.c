//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char password[20];    
    bool has_uppercase_letter = false, has_lowercase_letter = false, has_digit = false, has_special_character = false;
    int i, len;
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    len = strlen(password);
    
    if(len < 8)
    {
        printf("Your password is too short. It should contain at least 8 characters.\n");
        return 0;
    }
    
    for(i = 0; i < len; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            has_uppercase_letter = true;
        else if(password[i] >= 'a' && password[i] <= 'z')
            has_lowercase_letter = true;
        else if(password[i] >= '0' && password[i] <= '9')
            has_digit = true;
        else
            has_special_character = true;
    }
    
    if(has_uppercase_letter && has_lowercase_letter && has_digit && has_special_character)
        printf("Your password is strong!\n");
    else if((has_uppercase_letter || has_lowercase_letter) && has_digit && has_special_character)
        printf("Your password is medium.\n");
    else
        printf("Your password is weak. It should contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        
    return 0;
}