//FormAI DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void display_menu() {
    printf("\n\n=====================\n");
    printf(" System Administration\n");
    printf("=====================\n");
    printf("1. Show current user\n");
    printf("2. List all users\n");
    printf("3. Add new user\n");
    printf("4. Delete user\n");
    printf("5. Change password for user\n");
    printf("6. Exit\n\n");
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        choice = atoi(buffer);

        switch (choice) {
            case 1:
                printf("\nCurrent user: %s\n", getenv("USER"));
                break;

            case 2:
                printf("\nList of all users:\n");
                system("cat /etc/passwd | awk -F: '{print $1}'");
                break;

            case 3:
                printf("\nEnter the name of the new user: ");
                fgets(buffer, MAX_BUFFER_SIZE, stdin);
                strtok(buffer, "\n"); // remove the newline character
                printf("\nCreating new user %s...\n", buffer);
                sprintf(buffer, "sudo useradd %s", buffer);
                system(buffer);
                break;

            case 4:
                printf("\nEnter the name of the user to delete: ");
                fgets(buffer, MAX_BUFFER_SIZE, stdin);
                strtok(buffer, "\n"); // remove the newline character
                printf("\nDeleting user %s...\n", buffer);
                sprintf(buffer, "sudo userdel %s", buffer);
                system(buffer);
                break;

            case 5:
                printf("\nEnter the name of the user to change password for: ");
                fgets(buffer, MAX_BUFFER_SIZE, stdin);
                strtok(buffer, "\n"); // remove the newline character
                sprintf(buffer, "sudo passwd %s", buffer);
                system(buffer);
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }
    }

    return 0;
}