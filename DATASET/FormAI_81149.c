//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

void change_password();
void display_menu();

int main() {
    // Authenticating user
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0; // Removing newline character from input
    if(strcmp(password, "password123") != 0) {
        printf("Invalid password!\n");
        exit(1);
    }

    printf("Welcome to the System Administration Program\n");
    display_menu();

    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nChanging password...\n");
                change_password();
                break;
            case 2:
                printf("\nAdding user...\n");
                // Code for adding user goes here
                break;
            case 3:
                printf("\nRemoving user...\n");
                // Code for removing user goes here
                break;
            case 4:
                printf("\nViewing system information...\n");
                // Code for viewing system information goes here
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again...\n");
                break;
        }
        // Clearing input buffer
        while(getchar() != '\n');
        display_menu();
    } while(choice != 5);

    return 0;
}

void change_password() {
    char new_password[MAX_PASSWORD_LENGTH];
    printf("Enter new password: ");
    fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
    new_password[strcspn(new_password, "\n")] = 0; // Removing newline character from input
    printf("Password changed successfully!\n");
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Change Password\n");
    printf("2. Add User\n");
    printf("3. Remove User\n");
    printf("4. View System Information\n");
    printf("5. Exit Program\n");
}