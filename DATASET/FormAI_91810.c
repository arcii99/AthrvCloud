//FormAI DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char username[20], password[20];
    printf("\nWelcome to the System Administration Program\n");
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Create a new user\n");
        printf("2. Delete an existing user\n");
        printf("3. Change password for a user\n");
        printf("4. Exit program\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nPlease enter new username: ");
                scanf("%s", username);
                printf("\nPlease enter new password: ");
                scanf("%s", password);
                printf("\nUser %s created successfully!\n", username);
                break;
            case 2:
                printf("\nPlease enter username to delete: ");
                scanf("%s", username);
                printf("\nUser %s deleted successfully!\n", username);
                break;
            case 3:
                printf("\nPlease enter username to update password: ");
                scanf("%s", username);
                printf("\nPlease enter new password for %s: ", username);
                scanf("%s", password);
                printf("\nPassword for user %s updated successfully!\n", username);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}