//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50 // Define a maximum password length

// Struct to hold password information
typedef struct {
    char website[100];
    char username[50];
    char password[MAX_LENGTH+1]; // Add one for null terminator
} Password;

// Function to get a new password from the user
void getNewPassword(Password* p) {
    printf("\nPlease enter the website: ");
    scanf("%s", p->website);

    printf("Please enter the username: ");
    scanf("%s", p->username);

    char pw[MAX_LENGTH+1]; // Temporary variable to hold password

    // Get the password from the user, making sure it is less than the maximum length
    do {
        printf("Please enter the password (maximum %d characters): ", MAX_LENGTH);
        scanf("%s", pw);
    } while (strlen(pw) > MAX_LENGTH);

    // Copy the password into the struct
    strcpy(p->password, pw);
}

// Function to print out the password information
void printPassword(Password p) {
    printf("\nWebsite: %s\n", p.website);
    printf("Username: %s\n", p.username);
    printf("Password: %s\n", p.password);
}

int main() {
    Password passwords[100]; // Create an array of passwords
    int numPasswords = 0; // Keep track of the number of passwords

    int option = 0;
    do {
        // Print out the menu
        printf("\nWhat would you like to do?\n");
        printf("1 - Add a new password\n");
        printf("2 - View all passwords\n");
        printf("3 - Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &option);

        switch (option) {
            case 1: // Add a new password
                Password p;
                getNewPassword(&p);
                passwords[numPasswords] = p;
                numPasswords++;
                printf("\nPassword added successfully!\n");
                break;

            case 2: // View all passwords
                printf("\nAll saved passwords:\n");
                for (int i = 0; i < numPasswords; i++) {
                    printPassword(passwords[i]);
                }
                break;

            case 3: // Exit the program
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid option!\n");
                break;
        }
    } while (option != 3);

    return 0;
}