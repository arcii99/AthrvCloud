//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    char server[MAX_BUFFER_SIZE];
    char mailbox[MAX_BUFFER_SIZE];
    bool isLoggedIn = false;

    printf("Welcome to Retro IMAP Client\n");

    while (true) {
        // Display login or mailbox prompt
        if (isLoggedIn) {
            printf("Retro IMAP Client [%s]: ", mailbox);
        } else {
            printf("Retro IMAP Client (not logged in): ");
        }

        // Read user input
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Parse command
        char *command = strtok(buffer, " \n");
        if (command == NULL) {
            continue;
        }

        if (strcmp(command, "login") == 0) {
            // Parse login details
            char *arg = strtok(NULL, " \n");
            if (arg == NULL) {
                printf("Usage: login <username> <password> <server>\n");
                continue;
            }
            strcpy(username, arg);

            arg = strtok(NULL, " \n");
            if (arg == NULL) {
                printf("Usage: login <username> <password> <server>\n");
                continue;
            }
            strcpy(password, arg);

            arg = strtok(NULL, " \n");
            if (arg == NULL) {
                printf("Usage: login <username> <password> <server>\n");
                continue;
            }
            strcpy(server, arg);

            // TODO: Connect to server and authenticate user
            isLoggedIn = true;
            strcpy(mailbox, "Inbox");
            printf("Logged in to server %s as user %s\n", server, username);

        } else if (strcmp(command, "list") == 0) {
            // TODO: List available mailboxes on server
            if (!isLoggedIn) {
                printf("You must be logged in to list mailboxes\n");
            } else {
                printf("Mailboxes:\n - Inbox\n - Sent\n");
            }

        } else if (strcmp(command, "select") == 0) {
            // TODO: Select a mailbox
            char *arg = strtok(NULL, " \n");
            if (arg == NULL) {
                printf("Usage: select <mailbox>\n");
                continue;
            }
            strcpy(mailbox, arg);
            printf("Selected mailbox %s\n", mailbox);

        } else if (strcmp(command, "peek") == 0) {
            // TODO: Peek at the contents of the selected mailbox
            if (!isLoggedIn) {
                printf("You must be logged in to peek at mail\n");
            } else {
                printf("Peeking at contents of %s mailbox:\n", mailbox);
                printf(" - From: John Smith\n   Subject: Hello World!\n");
                printf(" - From: Jane Doe\n   Subject: Meeting Reminder\n");
            }

        } else if (strcmp(command, "logout") == 0) {
            isLoggedIn = false;
            printf("Logged out of server %s\n", server);

        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);

        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}