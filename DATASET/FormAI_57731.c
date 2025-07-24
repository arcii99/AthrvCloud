//FormAI DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PASSWORD_LENGTH 12
#define MAX_ATTEMPTS 3

int main()
{
    char password[PASSWORD_LENGTH + 1] = "Cyp3rpunk!23"; //Replace with your password
    char user_password[PASSWORD_LENGTH + 1];
    int attempts = 0;

    while (1) 
    {
        printf("Enter password: ");
        fgets(user_password, PASSWORD_LENGTH + 1, stdin);
        user_password[strcspn(user_password, "\n")] = 0; //remove new line character
        
        if (strcmp(user_password, password) == 0) 
        {
            printf("Access granted... Welcome to Cyp3rWarriors\n");
            break;
        } 
        else 
        {
            attempts++;
            printf("Access DENIED\n");
            if (attempts >= MAX_ATTEMPTS) 
            {
                printf("Security Breach!\n"); //Alerting security team
                exit(1);
            }
        }
    }
    
    // Password change
    char new_password[PASSWORD_LENGTH + 1];

    printf("Enter new password: ");
    fgets(new_password, PASSWORD_LENGTH + 1, stdin);
    new_password[strcspn(new_password, "\n")] = 0;

    printf("Confirm new password: ");
    fgets(user_password, PASSWORD_LENGTH + 1, stdin);
    user_password[strcspn(user_password, "\n")] = 0;

    if (strcmp(new_password, user_password) == 0) 
    {
        printf("Password changed successfully\n");
        strcpy(password, new_password); //updating the password
    }
    else 
    {
        printf("Password change failed\n");
        exit(1);
    }
    return 0;
}