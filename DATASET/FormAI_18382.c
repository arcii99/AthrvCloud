//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new password
void add_password(char *website, char *username, char *password) {
    char input[100]; // For user input validation

    // Open file for appending
    FILE *fptr = fopen("passwords.txt", "a");

    // Check if file opened successfully
    if (fptr == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Write website, username, and password to file
    fprintf(fptr, "%s %s %s\n", website, username, password);

    // Close file
    fclose(fptr);

    printf("Password added successfully!\n");
}

// Function to search for a password based on website name
void search_password(char *website) {
    char buffer[100];
    char *website_name;
    char *username;
    char *password;
    int found = 0;

    // Open file for reading
    FILE *fptr = fopen("passwords.txt", "r");

    // Check if file opened successfully
    if (fptr == NULL) {
        printf("No passwords found!\n");
        return;
    }

    // Read file line by line
    while (!feof(fptr)) {
        fgets(buffer, 100, fptr);

        // Extract website name, username, and password from line
        website_name = strtok(buffer, " ");
        username = strtok(NULL, " ");
        password = strtok(NULL, " ");

        // Remove newline character from password
        password[strlen(password)-1] = '\0';

        // Check if website name matches query
        if (strcmp(website_name, website) == 0) {
            found = 1;
            printf("Website: %s\n", website_name);
            printf("Username: %s\n", username);
            printf("Password: %s\n", password);
            break;
        }
    }

    // Close file
    fclose(fptr);

    // If password not found
    if (!found) {
        printf("No password found for website: %s\n", website);
    }
}

// Function to delete password based on website name
void delete_password(char *website) {
    char buffer[100];
    char *website_name;
    char *username;
    char *password;
    int found = 0;

    // Open file for reading
    FILE *fptr = fopen("passwords.txt", "r");

    // Check if file opened successfully
    if (fptr == NULL) {
        printf("No passwords found!\n");
        return;
    }

    // Open temporary file for writing
    FILE *temp = fopen("temp.txt", "w");

    // Read file line by line and copy to temporary file
    while (!feof(fptr)) {
        fgets(buffer, 100, fptr);

        // Extract website name, username, and password from line
        website_name = strtok(buffer, " ");
        username = strtok(NULL, " ");
        password = strtok(NULL, " ");

        // Remove newline character from password
        password[strlen(password)-1] = '\0';

        // Check if website name matches query
        if (strcmp(website_name, website) == 0) {
            found = 1;
        } else {
            // Write line to temporary file
            fprintf(temp, "%s %s %s\n", website_name, username, password);
        }
    }

    // Close files
    fclose(fptr);
    fclose(temp);

    // If password not found
    if (!found) {
        printf("No password found for website: %s\n", website);
        return;
    }

    // Delete original file
    remove("passwords.txt");

    // Rename temporary file to original filename
    rename("temp.txt", "passwords.txt");

    printf("Password successfully deleted!\n");
}

// Main function
int main() {
    int choice;
    char website[20];
    char username[20];
    char password[20];
    char input[10];

    do {
        // Display menu
        printf("\nPassword Management System\n");
        printf("1. Add a new password\n");
        printf("2. Search for a password\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Get user choice
        fgets(input, 10, stdin);
        choice = atoi(input);

        // Process user choice
        switch(choice) {
            case 1:
                // Get website, username, and password from user
                printf("Enter website name: ");
                fgets(website, 20, stdin);
                website[strlen(website)-1] = '\0'; // Remove newline character
                printf("Enter username: ");
                fgets(username, 20, stdin);
                username[strlen(username)-1] = '\0'; // Remove newline character
                printf("Enter password: ");
                fgets(password, 20, stdin);
                password[strlen(password)-1] = '\0'; // Remove newline character

                // Add password to file
                add_password(website, username, password);
                break;

            case 2:
                // Get website name from user
                printf("Enter website name: ");
                fgets(website, 20, stdin);
                website[strlen(website)-1] = '\0'; // Remove newline character

                // Search for password
                search_password(website);
                break;

            case 3:
                // Get website name from user
                printf("Enter website name to delete password: ");
                fgets(website, 20, stdin);
                website[strlen(website)-1] = '\0'; // Remove newline character

                // Delete password
                delete_password(website);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}