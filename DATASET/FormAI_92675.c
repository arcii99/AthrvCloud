//FormAI DATASET v1.0 Category: System administration ; Style: shape shifting
#include<stdio.h>

int main() {
    int option;
    
    printf("Welcome to the Shape-Shifting System Administration Program!\n");
    printf("Enter your selection:\n");
    printf("1. Change user password\n");
    printf("2. Add new user\n");
    printf("3. Delete user\n");
    printf("4. View system logs\n");
    
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Enter new password: ");
            // code to change user password
            break;
        case 2:
            printf("Enter new user's name: ");
            // code to add new user
            break;
        case 3:
            printf("Enter user's name to be deleted: ");
            // code to delete user
            break;
        case 4:
            printf("System logs:\n");
            // code to read system logs
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }
    
    printf("Thank you for using the Shape-Shifting System Administration Program!\n");
    
    return 0;
}