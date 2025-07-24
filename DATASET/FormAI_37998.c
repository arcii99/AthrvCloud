//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASS_LENGTH 20
#define ADMIN_PASSWORD "admin123"

// Function to get user input
char getChoice() {
    char choice = getchar();
    while(getchar() != '\n'); // clear input buffer
    return choice;
}

// Function to add password to list
void addPassword(char* passwords[MAX_PASSWORDS], int* numPasswords) {
    if(*numPasswords == MAX_PASSWORDS) {
        printf("Max number of passwords reached.\n");
        return;
    }

    char* newPassword = malloc(sizeof(char) * MAX_PASS_LENGTH);
    printf("Enter new password: ");
    fgets(newPassword, MAX_PASS_LENGTH, stdin);
    newPassword[strcspn(newPassword, "\n")] = 0; // remove newline character

    passwords[*numPasswords] = newPassword;
    (*numPasswords)++;
    printf("Password added successfully.\n");
}

// Function to view list of passwords
void viewPasswords(char* passwords[MAX_PASSWORDS], int numPasswords) {
    if(numPasswords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Passwords:\n");
    for(int i=0; i<numPasswords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

int main() {
    char* passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char input;

    printf("Enter administrator password to access password manager: ");
    char adminPass[MAX_PASS_LENGTH];
    fgets(adminPass, MAX_PASS_LENGTH, stdin);
    adminPass[strcspn(adminPass, "\n")] = 0; // remove newline character

    if(strcmp(adminPass, ADMIN_PASSWORD) != 0) {
        printf("Incorrect password. Access denied.\n");
        exit(1);
    }

    while(1) {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add a new password\n");
        printf("2. View saved passwords\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        input = getChoice();

        switch(input) {
            case '1':
                addPassword(passwords, &numPasswords);
                break;
            case '2':
                viewPasswords(passwords, numPasswords);
                break;
            case '3':
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}