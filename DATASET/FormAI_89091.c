//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50  // Maximum length of password
#define PASSWORDS_FILE "passwords.txt"  // Passwords file name

int main()
{
    char passwords[MAX_LENGTH][MAX_LENGTH];  // Array to store passwords
    int num_passwords = 0;  // Number of passwords stored
    
    FILE* file_ptr = fopen(PASSWORDS_FILE, "r");  // Open passwords file
    
    if (file_ptr != NULL) {
        // Read passwords from file
        char password[MAX_LENGTH];
        while (fgets(password, MAX_LENGTH, file_ptr)) {
            password[strcspn(password, "\n")] = '\0';  // Remove newline character
            strcpy(passwords[num_passwords++], password);
        }
        
        fclose(file_ptr);  // Close passwords file
    }
    
    // Display menu options
    printf("Select an option:\n");
    printf("1. Add a new password\n");
    printf("2. View all passwords\n");
    printf("3. Quit\n");
    
    int menu_choice;
    do {
        // Get user menu choice
        printf("Enter option (1-3): ");
        scanf("%d", &menu_choice);
        getchar();  // Consume newline character
        
        switch (menu_choice) {
            case 1:
                // Add new password
                if (num_passwords == MAX_LENGTH) {
                    printf("Error: passwords array is full\n");
                    break;
                }
                
                char new_password[MAX_LENGTH];
                printf("Enter new password (up to %d characters): ", MAX_LENGTH);
                fgets(new_password, MAX_LENGTH, stdin);
                new_password[strcspn(new_password, "\n")] = '\0';  // Remove newline character
                
                // Check if password already exists
                for (int i = 0; i < num_passwords; i++) {
                    if (strcmp(new_password, passwords[i]) == 0) {
                        printf("Error: password already exists\n");
                        break;
                    }
                }
                
                // Add new password to array and passwords file
                strcpy(passwords[num_passwords++], new_password);
                file_ptr = fopen(PASSWORDS_FILE, "a");  // Open passwords file in append mode
                fprintf(file_ptr, "%s\n", new_password);
                fclose(file_ptr);  // Close passwords file
                printf("Password added successfully\n");
                break;
                
            case 2:
                // View all passwords
                if (num_passwords == 0) {
                    printf("No passwords stored\n");
                    break;
                }
                
                printf("Stored passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s\n", passwords[i]);
                }
                break;
                
            case 3:
                // Quit
                printf("Exiting program\n");
                break;
                
            default:
                printf("Invalid option selected\n");
                break;
        }
    } while (menu_choice != 3);
    
    return 0;
}