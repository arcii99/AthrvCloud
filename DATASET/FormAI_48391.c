//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

/* This program will create a new user account on the system */

int main() {
    char username[20];
    char password[20];
    char confirm_password[20];
    char command[50];
    
    /* Prompt for Username */
    printf("Enter a username: ");
    scanf("%s", username);
    
    /* Prompt for Password and confirm */
    printf("Enter a password: ");
    scanf("%s", password);
    
    printf("Confirm password: ");
    scanf("%s", confirm_password);
    
    if(strcmp(password, confirm_password) != 0) {
        printf("Passwords do not match!\n");
        exit(1);
    }
    
    /* Create command to add user */
    sprintf(command, "sudo useradd -m %s -p %s", username, password);
    
    /* Execute add user command */
    system(command);
    
    printf("User %s has been created successfully!\n", username);
    
    return 0;
}