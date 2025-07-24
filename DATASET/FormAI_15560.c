//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("Welcome to the Happy Sysadmin Example Program!\n");
    printf("Today we will be automating the mundane task of creating user accounts.\n");

    char username[20], command[50];

    printf("Please enter the desired username: ");
    scanf("%s", username);

    printf("Creating user account...\n");

    // Create user account
    snprintf(command, sizeof(command), "useradd %s", username);
    system(command);

    printf("User account created successfully!\n");
    printf("Adding user to sudoers list...\n");

    // Add user to sudoers list
    snprintf(command, sizeof(command), "usermod -aG sudo %s", username);
    system(command);

    printf("User added to sudoers list successfully!\n");
    printf("Setting password for user...\n");

    // Set user password
    snprintf(command, sizeof(command), "passwd %s", username);
    system(command);

    printf("Password set successfully!\n");
    printf("Account creation complete!\n");

    return 0;
}