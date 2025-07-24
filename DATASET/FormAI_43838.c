//FormAI DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 5

//Structs to hold account information and passwords
typedef struct {
    char account_name[50];
    char password[MAX_PASSWORD_LENGTH + 1];
} Account;

//Generates a random password
void generate_password(char *password) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}|<>?";
    int n = strlen(charset);
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % n];
    }
    password[MAX_PASSWORD_LENGTH] = '\0'; //Add null terminator
}

//Prompts the user for a new account name and password, and saves it
void add_account(Account *accounts, int *num_accounts) {
    char name[50];
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter account name: ");
    scanf("%s", name);
    generate_password(password);
    strcpy(accounts[*num_accounts].account_name, name);
    strcpy(accounts[*num_accounts].password, password);
    printf("Account created successfully.\n");
    (*num_accounts)++;
}

//Prompts the user for an account name and returns the index in the accounts array
int find_account(Account *accounts, int num_accounts, char *name) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(name, accounts[i].account_name) == 0) {
            return i;
        }
    }
    return -1;
}

//Prompts the user for an account name and deletes the corresponding account
void delete_account(Account *accounts, int *num_accounts) {
    char name[50];
    printf("Enter account name: ");
    scanf("%s", name);
    int index = find_account(accounts, *num_accounts, name);
    if (index == -1) {
        printf("Account not found.\n");
        return;
    }
    for (int i = index; i < *num_accounts - 1; i++) {
        accounts[i] = accounts[i + 1]; //Shift elements to fill gap
    }
    (*num_accounts)--;
    printf("Account deleted successfully.\n");
}

//Prompts the user for an account name and password, and checks if the information is correct
bool check_password(Account *accounts, int num_accounts, char *name, char *password) {
    int index = find_account(accounts, num_accounts, name);
    if (index == -1) {
        printf("Account not found.\n");
        return false;
    }
    if (strcmp(password, accounts[index].password) == 0) {
        printf("Password correct.\n");
        return true;
    }
    printf("Password incorrect.\n");
    return false;
}

int main() {
    Account accounts[50];
    int num_accounts = 0;
    char master_password[MAX_PASSWORD_LENGTH + 1];
    generate_password(master_password);

    printf("Welcome to the Post-Apocalyptic Password Manager.\n");
    printf("Your master password is \"%s\"\n", master_password);

    int num_attempts = 0;
    char input[50];
    while (num_attempts < MAX_ATTEMPTS) {
        printf("Enter master password: ");
        scanf("%s", input);
        if (strcmp(input, master_password) == 0) {
            printf("Access granted.\n");
            break;
        }
        printf("Access denied.\n");
        num_attempts++;
    }

    if (num_attempts == MAX_ATTEMPTS) {
        printf("Maximum number of attempts reached. Exiting.\n");
        return 0;
    }

    while (true) {
        printf("Enter a command (\"add\", \"delete\", \"check\", or \"exit\"):");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            add_account(accounts, &num_accounts);
        } else if (strcmp(input, "delete") == 0) {
            delete_account(accounts, &num_accounts);
        } else if (strcmp(input, "check") == 0) {
            printf("Enter account name: ");
            scanf("%s", input);
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH + 1];
            scanf("%s", password);
            check_password(accounts, num_accounts, input, password);
        } else if (strcmp(input, "exit") == 0) {
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}