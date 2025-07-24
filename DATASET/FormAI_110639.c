//FormAI DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <string.h>

void changePassword(char *password) 
{
    char newPassword[20];
    printf("Enter new password: ");
    scanf("%s", newPassword);
    if (strlen(newPassword) >= 8) 
    {
        strcpy(password, newPassword);
        printf("Password changed successfully\n");
    } 
    else 
    {
        printf("New password should be at least 8 characters long\n");
    }
}

int main() 
{
    char password[20] = "mysecretpass";
    char input[20];

    while (1) 
    {
        printf("Enter password: ");
        scanf("%s", input);
        if (strcmp(input, password) == 0) 
        {
            printf("Welcome to password management system\n");
            changePassword(password);
            break;
        } 
        else 
        {
            printf("Incorrect password, try again\n");
        }
    }

    return 0;
}