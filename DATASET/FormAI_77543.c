//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void enableVerboseMode() {
    printf("Verbose mode enabled\n");
}

void showHelp() {
    printf("This is the help menu\n");
    printf("Available commands:\n");
    printf("\thelp - Display this help menu\n");
    printf("\tverbose - Enable verbose mode\n");
    printf("\tping - Test network connectivity\n");
    printf("\treboot - Reboot the system\n");
    printf("\tshutdown - Turn off the system\n");
    printf("\texit - Exit admin panel\n");
}

void pingServer(char* address) {
    printf("Pinging %s...\n", address);
    // Ping server here
}

void rebootSystem() {
    printf("Rebooting the system...\n");
    // Reboot system here
}

void shutdownSystem() {
    printf("Shutting down the system...\n");
    // Shutdown system here
}

int main() {
    printf("Welcome to the system administration panel\n");
    printf("Type 'help' for a list of commands\n");

    char command[MAX_COMMAND_LENGTH];
    while(1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if(strncmp(command, "help", 4) == 0) {
            showHelp();
        } else if(strncmp(command, "verbose", 7) == 0) {
            enableVerboseMode();
        } else if(strncmp(command, "ping", 4) == 0) {
            char address[MAX_COMMAND_LENGTH];
            printf("Enter server IP address: ");
            fgets(address, MAX_COMMAND_LENGTH, stdin);
            pingServer(address);
        } else if(strncmp(command, "reboot", 6) == 0) {
            rebootSystem();
        } else if(strncmp(command, "shutdown", 8) == 0) {
            shutdownSystem();
        } else if(strncmp(command, "exit", 4) == 0) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}