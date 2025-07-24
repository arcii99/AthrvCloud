//FormAI DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing password data
struct Password {
    char site[20];
    char username[20];
    char password[20];
};

// Global variable for storing current user's password list
struct Password passwordList[50];

// Function for adding a new password to the list
void addPassword() {
    char site[20];
    char username[20];
    char password[20];

    printf("\nEnter the website: ");
    scanf("%s", site);

    printf("\nEnter the username: ");
    scanf("%s", username);

    printf("\nEnter the password: ");
    scanf("%s", password);

    // Create new Password struct and add it to passwordList
    struct Password newPassword;
    strcpy(newPassword.site, site);
    strcpy(newPassword.username, username);
    strcpy(newPassword.password, password);

    for (int i = 0; i < 50; i++) {
        if (strcmp(passwordList[i].site, "") == 0) {
            passwordList[i] = newPassword;
            printf("\nPassword saved.\n");
            break;
        }
        if (i == 49) {
            printf("\nNo free slots in password list.\n");
        }
    }
}

// Function for displaying the current user's saved passwords
void displayPasswords() {
    printf("\nCurrent Password List:\n\n");

    for (int i = 0; i < 50; i++) {
        if (strcmp(passwordList[i].site, "") != 0) {
            printf("Website: %s\n", passwordList[i].site);
            printf("Username: %s\n", passwordList[i].username);
            printf("Password: %s\n\n", passwordList[i].password);
        }
    }

    printf("End of password list.\n");
}

int main() {
    int option;

    // Clear initial password list
    for (int i = 0; i < 50; i++) {
        struct Password newPassword;
        strcpy(newPassword.site, "");
        strcpy(newPassword.username, "");
        strcpy(newPassword.password, "");
        passwordList[i] = newPassword;
    }

    printf(" _____                          _____           _     \n");
    printf("|  __ \\                        / ____|         | |    \n");
    printf("| |__) |__ _ __ __ _ _   _ ___| (___  _   _ ___| |_   \n");
    printf("|  _  // _` '__/ _` | | | / __|\\___ \\| | | / __| __|  \n");
    printf("| | \\ \\ (_| | | | (_| | |_| \\__ \\____) | |_| \\__ \\\\ |_ \n");
    printf("|_|  \\_\\__,_|_|  \\__,_|\\__, |___/|____/ \\__,_|___/\n"); 
    printf("                        __/ |                      \n");
    printf("                       |___/                       \n");

    printf("\nWelcome to CodePass, your personal password manager.\n\n");

    do {
        printf("Please select an option:\n");
        printf("1) Add a password\n");
        printf("2) Display saved passwords\n");
        printf("3) Quit\n\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                printf("\nExiting application.\n");
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    } while (option != 3);

    return 0;
}