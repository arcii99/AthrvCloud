//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 100
#define MAX_LINE 100
#define MAX_COMMAND 20

struct User {
    char username[MAX_LINE];
    char password[MAX_LINE];
    char home_dir[MAX_LINE];
};

struct User users[MAX_USER];
int user_count = 0;

void parse_command(char input[MAX_LINE]);
int authenticate_user(char username[MAX_LINE], char password[MAX_LINE]);
void change_password(char username[MAX_LINE]);
void create_user(char username[MAX_LINE], char password[MAX_LINE], char home_dir[MAX_LINE]);
void delete_user(char username[MAX_LINE]);
void show_users();
void help();

int main() {
    printf("Welcome to the User Administration System\n");
    printf("Please enter your username and password to continue\n\n");

    char username[MAX_LINE], password[MAX_LINE];
    int authenticated = 0;
    while (!authenticated) {
        printf("Username: ");
        fgets(username, MAX_LINE, stdin);
        username[strcspn(username, "\n")] = 0;

        printf("Password: ");
        fgets(password, MAX_LINE, stdin);
        password[strcspn(password, "\n")] = 0;

        authenticated = authenticate_user(username, password);
        if (!authenticated) {
            printf("Invalid username/password, please try again\n");
        }
    }

    printf("\n");

    char input[MAX_LINE];
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 0) {
            parse_command(input);
        }
    }

    return 0;
}

void parse_command(char input[MAX_LINE]) {
    char command[MAX_COMMAND];
    sscanf(input, "%s", command);

    if (strcmp(command, "change_password") == 0) {
        char username[MAX_LINE];
        sscanf(input + strlen(command) + 1, "%s", username);

        change_password(username);
        printf("\n");
    } else if (strcmp(command, "create_user") == 0) {
        char username[MAX_LINE], password[MAX_LINE], home_dir[MAX_LINE];
        sscanf(input + strlen(command) + 1, "%s %s %s", username, password, home_dir);

        create_user(username, password, home_dir);
        printf("\n");
    } else if (strcmp(command, "delete_user") == 0) {
        char username[MAX_LINE];
        sscanf(input + strlen(command) + 1, "%s", username);

        delete_user(username);
        printf("\n");
    } else if (strcmp(command, "show_users") == 0) {
        show_users();
        printf("\n");
    } else if (strcmp(command, "help") == 0) {
        help();
        printf("\n");
    } else {
        printf("Unknown command '%s', type 'help' for help\n\n", command);
    }
}

int authenticate_user(char username[MAX_LINE], char password[MAX_LINE]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Welcome, %s!\n", username);
            return 1;
        }
    }

    return 0;
}

void change_password(char username[MAX_LINE]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            char password[MAX_LINE];
            printf("Enter new password for '%s': ", username);
            fgets(password, MAX_LINE, stdin);
            password[strcspn(password, "\n")] = 0;

            printf("Password changed for '%s'\n", username);
            strcpy(users[i].password, password);
            return;
        }
    }

    printf("User '%s' not found\n", username);
}

void create_user(char username[MAX_LINE], char password[MAX_LINE], char home_dir[MAX_LINE]) {
    if (user_count >= MAX_USER) {
        printf("Maximum user count exceeded\n");
        return;
    }

    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User '%s' already exists\n", username);
            return;
        }
    }

    struct User user;
    strcpy(user.username, username);
    strcpy(user.password, password);
    strcpy(user.home_dir, home_dir);

    users[user_count] = user;
    user_count++;

    printf("User '%s' created successfully\n", username);
}

void delete_user(char username[MAX_LINE]) {
    int index_to_delete = -1;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        printf("User '%s' not found\n", username);
        return;
    }

    for (int i = index_to_delete; i < user_count - 1; i++) {
        users[i] = users[i + 1];
    }
    user_count--;

    printf("User '%s' deleted successfully\n", username);
}

void show_users() {
    printf("%-20s %-20s %-20s\n", "Username", "Password", "Home Directory");
    for (int i = 0; i < user_count; i++) {
        printf("%-20s %-20s %-20s\n", users[i].username, users[i].password, users[i].home_dir);
    }
}

void help() {
    printf("Usage: COMMAND [ARGUMENTS]\n\n");
    printf("Available commands:\n");
    printf("  change_password USERNAME     Change the password for specified user\n");
    printf("  create_user USERNAME PASSWORD HOME_DIR\n");
    printf("                               Create a new user with specified username, password, and home directory\n");
    printf("  delete_user USERNAME         Delete the specified user\n");
    printf("  show_users                   Display a list of all users\n");
    printf("  help                         Display this help message\n");
}