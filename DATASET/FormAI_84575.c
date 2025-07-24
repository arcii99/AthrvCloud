//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int lowercase = 0, uppercase = 0, digits = 0, symbols = 0, length = 0;
    int score = 0;
    
    printf("Enter a password in medieval style: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    for(int i=0; i<length; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
            lowercase = 1;
        else if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase = 1;
        else if(password[i] >= '0' && password[i] <= '9')
            digits = 1;
        else
            symbols = 1;
    }
    
    if(length >= 8 && length <= 16)
        score += 20;
    else if(length > 16)
        score += 40;
    
    if(lowercase && uppercase)
        score += 20;
    
    if(digits && symbols)
        score += 20;
    
    if(length >= 8 && lowercase && uppercase && digits && symbols)
        score += 40;
    
    if(score >= 80)
        printf("Your password is strong like a knight in shining armor!\n");
    else if(score >= 60)
        printf("Your password is decent like a peasant with a decent yield.\n");
    else
        printf("Your password is weak like a cowardly squire.\n");
    
    return 0;
}