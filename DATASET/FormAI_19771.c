//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

int main() {
    char command[MAX_COMMAND_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        
        if (strcmp(command, "add user") == 0) {
            printf("\nEnter the username: ");
            fgets(username, MAX_USERNAME_LENGTH, stdin);
            username[strcspn(username, "\n")] = 0;

            printf("Enter the password: ");
            fgets(password, MAX_PASSWORD_LENGTH, stdin);
            password[strcspn(password, "\n")] = 0;

            // Validate username and password
            int valid_username = 1, valid_password = 1;
            for (int i = 0; i < strlen(username); i++) {
                if (!isalnum(username[i])) {
                    valid_username = 0;
                    break;
                }
            }
            for (int i = 0; i < strlen(password); i++) {
                if (!isalnum(password[i])) {
                    valid_password = 0;
                    break;
                }
            }

            // Add user to system if username and password are valid
            if (valid_username && valid_password) {
                char command_add_user[MAX_COMMAND_LENGTH];
                snprintf(command_add_user, MAX_COMMAND_LENGTH, "sudo adduser %s --quiet", username);
                system(command_add_user);

                char command_set_password[MAX_COMMAND_LENGTH];
                snprintf(command_set_password, MAX_COMMAND_LENGTH, "echo %s:%s | sudo chpasswd", username, password);
                system(command_set_password);

                printf("User added successfully.\n");
            } else {
                printf("Invalid username or password. Username and password must only contain alphanumeric characters.\n");
            }
        } else if (strcmp(command, "remove user") == 0) {
            printf("\nEnter the username: ");
            fgets(username, MAX_USERNAME_LENGTH, stdin);
            username[strcspn(username, "\n")] = 0;

            // Remove user from system
            char command_remove_user[MAX_COMMAND_LENGTH];
            snprintf(command_remove_user, MAX_COMMAND_LENGTH, "sudo userdel -r %s", username);
            system(command_remove_user);

            printf("User removed successfully.\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command. Available commands: add user, remove user, exit.\n");
        }
    }

    return 0;
}