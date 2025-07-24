//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define MAX_ENTRIES 100

//define a struct to store each password entry
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

//initialize a global array to keep track of all password entries
PasswordEntry passwords[MAX_ENTRIES];

//keep track of the number of entries in the passwords array
int numEntries = 0;

//function to add a new password entry
void addPassword() {
    if (numEntries < MAX_ENTRIES) {
        PasswordEntry newEntry;
        printf("Enter a new username: ");
        fgets(newEntry.username, MAX_USERNAME_LENGTH, stdin);
        printf("Enter a new password: ");
        fgets(newEntry.password, MAX_PASSWORD_LENGTH, stdin);
        passwords[numEntries++] = newEntry;
        printf("Password added successfully.\n");
    } else {
        printf("Error: maximum number of entries exceeded.\n");
    }
}

//function to display all password entries
void displayPasswords() {
    printf("Password Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Username: %sPassword: %s", passwords[i].username, passwords[i].password);
    }
}

//function to search for a password entry by username
void searchByUsername() {
    char searchUsername[MAX_USERNAME_LENGTH];
    printf("Enter the username to search for: ");
    fgets(searchUsername, MAX_USERNAME_LENGTH, stdin);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(passwords[i].username, searchUsername) == 0) {
            printf("Match found:\nUsername: %sPassword: %s", 
                passwords[i].username, passwords[i].password);
            return;
        }
    }
    printf("No matching entry found.\n");
}

//main program loop
int main() {
    char input[10];
    while (1) {
        printf("\nEnter a command:\n1. add password\n2. display passwords\n3. search by username\n4. exit\n");
        fgets(input, 10, stdin);
        switch (atoi(input)) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                searchByUsername();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }
    return 0;
}