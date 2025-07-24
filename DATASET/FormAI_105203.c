//FormAI DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char choice;
    printf("Welcome to the System Administration program!\n");
    printf("Please select an option:\n");
    printf("a. Add user\n");
    printf("b. Remove user\n");
    printf("c. Create backup\n");
    printf("d. Restore backup\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'a':
            printf("Enter username: ");
            char username[50];
            scanf("%s", username);
            printf("User %s added successfully!\n", username); 
            break;
        case 'b':
            printf("Enter username to remove: ");
            char username_remove[50];
            scanf("%s", username_remove);
            printf("User %s removed successfully!\n", username_remove);
            break;
        case 'c':
            printf("Enter directory to back up: ");
            char directory_backup[100];
            scanf("%s", directory_backup);
            printf("Creating backup of %s...\n", directory_backup);
            printf("Backup created successfully!\n");
            break;
        case 'd':
            printf("Enter directory to restore backup: ");
            char backup_directory[100];
            scanf("%s", backup_directory);
            printf("Restoring backup of %s...\n", backup_directory);
            printf("Backup restored successfully!\n");
            break;
        default:
            printf("Invalid option selected!\n");
    }
    return 0;
}