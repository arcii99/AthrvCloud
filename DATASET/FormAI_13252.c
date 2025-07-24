//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH], username[MAX_INPUT_LENGTH], password[MAX_INPUT_LENGTH];
    int login_attempts = 0;
    int password_matched = 0;

    printf("##############################################\n");
    printf("##          Welcome to System Admin         ##\n");
    printf("##############################################\n");

    while (login_attempts < 3 && !password_matched) {
        printf("Please enter your username: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        sscanf(input, "%s", username);

        printf("Please enter your password: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        sscanf(input, "%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "Abcd1234") == 0) {
            printf("Welcome, admin!\n");
            password_matched = 1;
        } else {
            login_attempts++;
            if (login_attempts < 3) {
                printf("Invalid username or password\n");
            }
        }
    }

    if (!password_matched) {
        printf("Too many login attempts. Please try again later.\n");
        exit(1);
    }

    printf("########################################################\n");
    printf("##         System Admin - Post-Apocalyptic Style       ##\n");
    printf("########################################################\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        sscanf(input, "%s", input);

        if (strcmp(input, "shutdown") == 0) {
            printf("Are you sure you want to shut down the system? (y/n): ");
            fgets(input, MAX_INPUT_LENGTH, stdin);
            sscanf(input, "%s", input);

            if (strcmp(input, "y") == 0) {
                printf("Shutting down the system. Goodbye!\n");
                break;
            } else {
                printf("Shutdown cancelled.\n");
            }
        } else if (strcmp(input, "restart") == 0) {
            printf("Are you sure you want to restart the system? (y/n): ");
            fgets(input, MAX_INPUT_LENGTH, stdin);
            sscanf(input, "%s", input);

            if (strcmp(input, "y") == 0) {
                printf("Rebooting the system. Thank you!\n");
                break;
            } else {
                printf("Restart cancelled.\n");
            }
        } else {
            printf("Unknown command, please try again.\n");
        }
    }

    return 0;
}