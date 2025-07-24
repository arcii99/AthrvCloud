//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000 // Maximum number of passwords

struct password_entry {
    char service[50];
    char username[50];
    char password[50];
};

struct password_entry password_list[MAX_PASSWORDS]; // List of passwords
int num_passwords = 0; // Number of passwords in the list

void add_password(const char* service, const char* username, const char* password) {
    // Check if the password list is already full
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached!\n");
        return;
    }

    // Add the new password entry to the list
    struct password_entry new_password;
    strcpy(new_password.service, service);
    strcpy(new_password.username, username);
    strcpy(new_password.password, password);

    password_list[num_passwords] = new_password;
    num_passwords++;

    printf("Password added for service '%s'\n", service);
}

void print_passwords() {
    printf("Service\tUsername\tPassword\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\t%s\n", password_list[i].service, password_list[i].username, password_list[i].password);
    }
}

void find_password(const char* service) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(password_list[i].service, service) == 0) {
            printf("Password for service '%s' is: %s\n", service, password_list[i].password);
            return;
        }
    }

    printf("Error: Password not found for service '%s'\n", service);
}

int main() {
    char input[50];

    while (1) {
        printf("Enter command (add, list, find, quit): ");
        fgets(input, 50, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "add") == 0) {
            char service[50];
            char username[50];
            char password[50];

            printf("Enter service name: ");
            fgets(service, 50, stdin);
            service[strcspn(service, "\n")] = 0;

            printf("Enter username: ");
            fgets(username, 50, stdin);
            username[strcspn(username, "\n")] = 0;

            printf("Enter password: ");
            fgets(password, 50, stdin);
            password[strcspn(password, "\n")] = 0;

            add_password(service, username, password);
        } else if (strcmp(input, "list") == 0) {
            print_passwords();
        } else if (strcmp(input, "find") == 0) {
            char service[50];
            printf("Enter service name: ");
            fgets(service, 50, stdin);
            service[strcspn(service, "\n")] = 0;

            find_password(service);
        } else if (strcmp(input, "quit") == 0) {
            return 0;
        } else {
            printf("Unknown command: %s\n", input);
        }
    }
}