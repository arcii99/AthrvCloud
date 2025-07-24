//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    char hostname[1024];
    gethostname(hostname, 1024);

    printf("Welcome to %s! You are the System Admin today.\n", hostname);

    char command[1024];
    memset(command, 0, sizeof(command));

    do {
        printf("> ");
        fgets(command, 1024, stdin);
        strtok(command, "\n"); // remove newline character

        if (strcmp(command, "help") == 0) {
            printf("Commands: \n");
            printf("  help: display this message\n");
            printf("  users: display a list of logged in users\n");
            printf("  processes: display a list of running processes\n");
            printf("  reboot: reboot the system\n");
            printf("  shutdown: shut down the system\n");
        }
        else if (strcmp(command, "users") == 0) {
            system("who");
        }
        else if (strcmp(command, "processes") == 0) {
            system("ps -aux");
        }
        else if (strcmp(command, "reboot") == 0) {
            printf("Are you sure you want to reboot the system? (y/n)");
            char confirm[2];
            fgets(confirm, 2, stdin);
            if (strcmp(confirm, "y") == 0) {
                printf("Rebooting...\n");
                sleep(3);
                system("reboot");
            }
            else {
                printf("Reboot cancelled.\n");
            }
        }
        else if (strcmp(command, "shutdown") == 0) {
            printf("Are you sure you want to shut down the system? (y/n)");
            char confirm[2];
            fgets(confirm, 2, stdin);
            if (strcmp(confirm, "y") == 0) {
                printf("Shutting down...\n");
                sleep(3);
                system("shutdown now");
            }
            else {
                printf("Shutdown cancelled.\n");
            }
        }
        else {
            printf("Command not recognized. Type 'help' for a list of commands.\n");
        }

    } while (strcmp(command, "quit") != 0);

    printf("Goodbye! Thanks for being a great System Admin today.\n");
    return 0;
}