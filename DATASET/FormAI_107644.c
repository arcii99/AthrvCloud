//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    char confirm[20];
    int attempts = 0;
    printf("Please enter a new password:\n");
    scanf("%s", password);
    
    printf("Please confirm your password:\n");
    scanf("%s", confirm);
    
    while(strcmp(password, confirm) != 0 && attempts < 3)
    {
        printf("Passwords do not match. Please try again.\n");
        printf("Please enter a new password:\n");
        scanf("%s", password);
        
        printf("Please confirm your password:\n");
        scanf("%s", confirm);
        
        attempts++;
    }
    
    if(attempts == 3)
    {
        printf("Maximum attempts reached.\n");
    }
    else
    {
        printf("Password has been successfully set.\n");
    }
    
    return 0;
}