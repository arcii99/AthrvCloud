//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MASTER_PASSWORD "password"

struct Password {
    char title[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int numPasswords = 0;
struct Password passwords[MAX_PASSWORDS];

void printMenu() {
    printf("\n==== Password Manager ====\n");
    printf("1. View all passwords\n");
    printf("2. Add a new password\n");
    printf("3. Remove a password\n");
    printf("4. Change master password\n");
    printf("5. Quit\n");
    printf("Enter your selection: ");
}

void viewPasswords() {
    printf("\n--- Passwords ---\n");
    for(int i = 0; i < numPasswords; i++) {
        printf("%d. Title: %s\n", i+1, passwords[i].title);
        printf("   Username: %s\n", passwords[i].username);
        printf("   Password: %s\n", passwords[i].password);
    }
    printf("-----------------\n");
}

void addPassword() {
    printf("\nEnter the new password's information:\n");

    if(numPasswords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords. Please remove one to add another.\n");
        return;
    }

    struct Password newPass;

    printf("Title: ");
    fgets(newPass.title, MAX_PASSWORD_LENGTH, stdin);
    newPass.title[strcspn(newPass.title, "\n")] = 0;

    printf("Username: ");
    fgets(newPass.username, MAX_PASSWORD_LENGTH, stdin);
    newPass.username[strcspn(newPass.username, "\n")] = 0;

    printf("Password: ");
    fgets(newPass.password, MAX_PASSWORD_LENGTH, stdin);
    newPass.password[strcspn(newPass.password, "\n")] = 0;

    passwords[numPasswords++] = newPass;

    printf("Password added successfully.\n");
}

void removePassword() {
    printf("\nEnter the number of the password to remove: ");
    char input[MAX_PASSWORD_LENGTH];
    fgets(input, MAX_PASSWORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    int num = atoi(input);

    if(num <= 0 || num > numPasswords) {
        printf("Error: Invalid password number.\n");
        return;
    }

    num--;

    printf("Are you sure you want to delete the following password?\n");
    printf("Title: %s\n", passwords[num].title);
    printf("Username: %s\n", passwords[num].username);
    printf("Password: %s\n", passwords[num].password);
    printf("Type 'YES' to confirm, or anything else to cancel: ");

    fgets(input, MAX_PASSWORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    if(strcmp(input, "YES") == 0) {
        for(int i = num; i < numPasswords-1; i++) {
            passwords[i] = passwords[i+1];
        }
        numPasswords--;
        printf("Password removed successfully.\n");
    } else {
        printf("Password removal cancelled.\n");
    }
}

void changeMasterPassword() {
    printf("\nEnter the current master password: ");
    char input[MAX_PASSWORD_LENGTH];
    fgets(input, MAX_PASSWORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    if(strcmp(input, MASTER_PASSWORD) != 0) {
        printf("Error: Incorrect master password.\n");
        return;
    }

    printf("Enter the new master password: ");
    fgets(input, MAX_PASSWORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    strcpy(MASTER_PASSWORD, input);

    printf("Master password changed successfully.\n");
}

int main() {
    char masterInput[MAX_PASSWORD_LENGTH];
    printf("Enter master password: ");
    fgets(masterInput, MAX_PASSWORD_LENGTH, stdin);
    masterInput[strcspn(masterInput, "\n")] = 0;

    if(strcmp(masterInput, MASTER_PASSWORD) != 0) {
        printf("Incorrect master password. Exiting program.\n");
        return 0;
    }

    int choice = 0;

    while(choice != 5) {
        printMenu();

        char input[MAX_PASSWORD_LENGTH];
        fgets(input, MAX_PASSWORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        choice = atoi(input);

        switch(choice) {
            case 1:
                viewPasswords();
                break;
            case 2:
                addPassword();
                break;
            case 3:
                removePassword();
                break;
            case 4:
                changeMasterPassword();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("Error: Invalid selection.\n");
                break;
        }
    }

    return 0;
}