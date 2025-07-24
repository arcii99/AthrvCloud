//FormAI DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 20
#define MAX_LENGTH 50

// struct for holding a password and its associated username
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

// function for printing all stored passwords and their usernames
void printPasswords(Password passwords[], int count) {
    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Username: %s, Password: %s\n", i+1, passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int count = 0;
    int choice;
    char input[MAX_LENGTH];

    do {
        // print menu and get user choice
        printf("\nPassword Manager\n");
        printf("1. Add new password\n");
        printf("2. View stored passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(input, MAX_LENGTH, stdin);
        sscanf(input, "%d", &choice);

        switch(choice) {
            case 1: // add new password
                // allocate memory for new password
                Password *newPassword = malloc(sizeof(Password));
                if (!newPassword) {
                    printf("Error: memory allocation failed\n");
                    break;
                }

                // get username and password from user
                printf("Enter username: ");
                fgets(newPassword->username, MAX_LENGTH, stdin);
                printf("Enter password: ");
                fgets(newPassword->password, MAX_LENGTH, stdin);

                // remove newline character from input
                newPassword->username[strcspn(newPassword->username, "\n")] = '\0';
                newPassword->password[strcspn(newPassword->password, "\n")] = '\0';

                // add new password to array
                if (count < MAX_PASSWORDS) {
                    passwords[count] = *newPassword;
                    count++;
                    printf("Password added successfully.\n");
                } else {
                    printf("Error: maximum number of passwords reached.\n");
                }
                break;
            case 2: // view stored passwords
                printPasswords(passwords, count);
                break;
            case 3: // exit program
                printf("Exiting program.\n");
                break;
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}