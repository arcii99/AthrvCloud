//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[1000];
    printf("Welcome to the Ephemeral System Administration Program!\n");
    printf("Please enter a command to execute:\n");
    fgets(command, sizeof(command), stdin); // read user input

    // remove newline character from command
    char *pos;
    if ((pos = strchr(command, '\n')) != NULL) {
        *pos = '\0';
    }

    // check if command is valid
    if (strcmp(command, "shutdown") == 0) {
        printf("Are you sure you want to shutdown the system? (y/n)\n");

        char confirm[10];
        fgets(confirm, sizeof(confirm), stdin);

        // remove newline character from confirmation
        if ((pos = strchr(confirm, '\n')) != NULL) {
            *pos = '\0';
        }

        // proceed with shutdown if user confirms
        if (strcmp(confirm, "y") == 0) {
            system("sudo shutdown now");
            printf("System has been shutdown.\n");
        } else {
            printf("Shutdown has been cancelled.\n");
        }

    } else if (strcmp(command, "restart") == 0) {
        printf("Are you sure you want to restart the system? (y/n)\n");

        char confirm[10];
        fgets(confirm, sizeof(confirm), stdin);

        // remove newline character from confirmation
        if ((pos = strchr(confirm, '\n')) != NULL) {
            *pos = '\0';
        }

        // proceed with restart if user confirms
        if (strcmp(confirm, "y") == 0) {
            system("sudo reboot now");
            printf("System has been restarted.\n");
        } else {
            printf("Restart has been cancelled.\n");
        }

    } else if (strcmp(command, "cpuinfo") == 0) {
        system("cat /proc/cpuinfo");

    } else if (strcmp(command, "meminfo") == 0) {
        system("cat /proc/meminfo");

    } else if (strcmp(command, "uptime") == 0) {
        system("uptime");

    } else if (strcmp(command, "users") == 0) {
        system("who");

    } else {
        printf("Invalid command.\n");
    }

    return 0;
}