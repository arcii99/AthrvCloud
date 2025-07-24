//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNTS 5

typedef struct {
    char account_name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

void print_menu() {
    printf("Password Manager\n"
           "----------------\n"
           "1. Add new password\n"
           "2. View all passwords\n"
           "3. Search for password\n"
           "4. Delete password\n"
           "5. Exit\n");
}

int get_input(int min, int max) {
    int input;
    char buffer[MAX_PASSWORD_LENGTH];

    do {
        printf("Enter choice (%d-%d): ", min, max);
        fgets(buffer, MAX_PASSWORD_LENGTH, stdin);
        input = atoi(buffer);
    } while (input < min || input > max);

    return input;
}

void add_new_password(PasswordEntry* password_list, int* num_passwords) {
    char account_name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    if (*num_passwords >= MAX_ACCOUNTS) {
        printf("Error: password manager is full!\n");
        return;
    }

    printf("\nEnter account name: ");
    fgets(account_name, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from input
    account_name[strcspn(account_name, "\n")] = '\0';

    // Make sure account name is not already in use
    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(account_name, password_list[i].account_name) == 0) {
            printf("Error: account name already in use!\n");
            return;
        }
    }

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    password[strcspn(password, "\n")] = '\0';

    // Copy new password entry into password list
    strncpy(password_list[*num_passwords].account_name, account_name, MAX_PASSWORD_LENGTH);
    strncpy(password_list[*num_passwords].password, password, MAX_PASSWORD_LENGTH);

    printf("Password added successfully!\n");
    (*num_passwords)++;
}

void view_all_passwords(PasswordEntry* password_list, int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords to display!\n");
        return;
    }

    printf("\n%-20s %s\n", "Account Name", "Password");
    printf("---------------------------------\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%-20s %s\n", password_list[i].account_name, password_list[i].password);
    }

    printf("\n");
}

void search_password(PasswordEntry* password_list, int num_passwords) {
    char account_name[MAX_PASSWORD_LENGTH];

    if (num_passwords == 0) {
        printf("No passwords to search!\n");
        return;
    }

    printf("\nEnter account name to search for: ");
    fgets(account_name, MAX_PASSWORD_LENGTH, stdin);
    account_name[strcspn(account_name, "\n")] = '\0';

    for (int i = 0; i < num_passwords; i++) {
        if (strcasecmp(account_name, password_list[i].account_name) == 0) {
            printf("Password for %s is %s\n", password_list[i].account_name, password_list[i].password);
            return;
        }
    }

    printf("Password not found!\n");
}

void delete_password(PasswordEntry* password_list, int* num_passwords) {
    char account_name[MAX_PASSWORD_LENGTH];

    if (*num_passwords == 0) {
        printf("No passwords to delete!\n");
        return;
    }

    printf("\nEnter account name to delete: ");
    fgets(account_name, MAX_PASSWORD_LENGTH, stdin);
    account_name[strcspn(account_name, "\n")] = '\0';

    for (int i = 0; i < *num_passwords; i++) {
        if (strcasecmp(account_name, password_list[i].account_name) == 0) {
            // Shift all passwords after the deleted password back by one index
            for (int j = i; j < *num_passwords - 1; j++) {
                strncpy(password_list[j].account_name, password_list[j+1].account_name, MAX_PASSWORD_LENGTH);
                strncpy(password_list[j].password, password_list[j+1].password, MAX_PASSWORD_LENGTH);
            }

            memset(password_list[*num_passwords-1].account_name, 0, MAX_PASSWORD_LENGTH);
            memset(password_list[*num_passwords-1].password, 0, MAX_PASSWORD_LENGTH);

            (*num_passwords)--;
            printf("Password for %s deleted!\n", account_name);
            return;
        }
    }

    printf("Password not found!\n");
}

int main() {
    PasswordEntry password_list[MAX_ACCOUNTS];
    int num_passwords = 0;
    int choice;

    do {
        print_menu();
        choice = get_input(1, 5);

        switch (choice) {
            case 1:
                add_new_password(password_list, &num_passwords);
                break;
            case 2:
                view_all_passwords(password_list, num_passwords);
                break;
            case 3:
                search_password(password_list, num_passwords);
                break;
            case 4:
                delete_password(password_list, &num_passwords);
                break;
            case 5:
                printf("Exiting password manager...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}