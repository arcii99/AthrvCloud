//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[100];

    printf("Welcome to the System Admin Program!\n");
    printf("What would you like to do?\n");

    while(1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if(strcmp(command, "shutdown\n") == 0) {
            printf("Are you sure you want to shutdown the system? (y/n)\n");
            char confirmation[2];
            fgets(confirmation, sizeof(confirmation), stdin);

            if(strcmp(confirmation, "y\n") == 0) {
                system("shutdown now");
                break;
            }
        }
        else if(strcmp(command, "reboot\n") == 0) {
            printf("Are you sure you want to reboot the system? (y/n)\n");
            char confirmation[2];
            fgets(confirmation, sizeof(confirmation), stdin);

            if(strcmp(confirmation, "y\n") == 0) {
                system("reboot");
                break;
            }
        }
        else if(strcmp(command, "status\n") == 0) {
            system("systemctl status");
        }
        else if(strcmp(command, "help\n") == 0) {
            printf("Available commands:\n");
            printf("- shutdown: Shutdown the system\n");
            printf("- reboot: Reboot the system\n");
            printf("- status: Display the system's current status\n");
            printf("- help: Show this help menu\n");
            printf("- exit: Quit the program\n");
        }
        else if(strcmp(command, "exit\n") == 0) {
            printf("Quitting the System Admin Program. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command. Type \"help\" to show available commands.\n");
        }
    }

    return 0;
}