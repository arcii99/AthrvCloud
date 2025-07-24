//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int verify_password(char *password) {
    int len = strlen(password);
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;
    for (int i = 0; i < len; i++) {
        char c = password[i];
        if (c >= 'A' && c <= 'Z') has_uppercase = 1;
        if (c >= 'a' && c <= 'z') has_lowercase = 1;
        if (c >= '0' && c <= '9') has_digit = 1;
        if (strchr("!@#$%^&*()_-+=", c) != NULL) has_special = 1;
    }
    if (len < 8 || len > MAX_PASSWORD_LENGTH) return 0;
    if (!has_uppercase || !has_lowercase) return 0;
    if (!has_digit || !has_special) return 0;
    return 1;
}

void change_password(User users[], int num_users) {
    char username[MAX_USERNAME_LENGTH];
    char old_password[MAX_PASSWORD_LENGTH], new_password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    strtok(username, "\n");

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Enter old password: ");
            fgets(old_password, MAX_PASSWORD_LENGTH, stdin);
            strtok(old_password, "\n");

            if (strcmp(users[i].password, old_password) == 0) {
                while (1) {
                    printf("Enter new password: ");
                    fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
                    strtok(new_password, "\n");
                    if (verify_password(new_password)) {
                        printf("Password changed successfully.\n");
                        strcpy(users[i].password, new_password);
                        return;
                    }
                    else {
                        printf("Invalid password. Please try again.\n");
                    }
                }
            }
            else {
                printf("Incorrect password.\n");
            }
            return;
        }
    }

    printf("User not found.\n");
}

int main() {
    User users[10] = {
        {"alice", "P@ssw0rd1"},
        {"bob", "S3cretPa$$"},
        {"charlie", "passw0rd"},
        {"dave", "1234abcd"}
    };
    int num_users = 4;

    while (1) {
        printf("Enter username: ");
        char username[MAX_USERNAME_LENGTH];
        fgets(username, MAX_USERNAME_LENGTH, stdin);
        strtok(username, "\n");

        User *user = NULL;
        for (int i = 0; i < num_users; i++) {
            if (strcmp(users[i].username, username) == 0) {
                user = &users[i];
                break;
            }
        }

        if (user == NULL) {
            // User not found
            printf("User not found. Would you like to register? (y/n)\n");
            char choice = getchar();
            clear_input();
            if (choice == 'y' || choice == 'Y') {
                if (num_users == 10) {
                    printf("Maximum number of users reached.\n");
                    continue;
                }
                printf("Enter password: ");
                char password[MAX_PASSWORD_LENGTH];
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                strtok(password, "\n");
                if (verify_password(password)) {
                    strncpy(user->username, username, MAX_USERNAME_LENGTH - 1);
                    strncpy(user->password, password, MAX_PASSWORD_LENGTH - 1);
                    printf("Registration successful.\n");
                    num_users++;
                }
                else {
                    printf("Invalid password. Please try again.\n");
                }
            }
            else {
                printf("Exiting...\n");
                break;
            }
        }
        else {
            // User found
            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            fgets(password, MAX_PASSWORD_LENGTH, stdin);
            strtok(password, "\n");
            if (strcmp(user->password, password) == 0) {
                printf("Welcome, %s!\n", username);
                printf("Would you like to change your password? (y/n)\n");
                char choice = getchar();
                clear_input();
                if (choice == 'y' || choice == 'Y') {
                    change_password(users, num_users);
                }
            }
            else {
                printf("Incorrect password.\n");
            }
        }
    }

    return 0;
}