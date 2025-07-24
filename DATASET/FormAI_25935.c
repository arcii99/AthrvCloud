//FormAI DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    printf("Welcome to the remote administration tool!\n");

    while (1) {
        printf("Enter a command: ");
        fgets(command, 100, stdin);

        if (strcmp(command, "shutdown\n") == 0) {
            printf("Are you sure you want to shutdown the system? (y/n) ");
            char response[2];
            fgets(response, 2, stdin);

            if (response[0] == 'y') {
                system("shutdown -h now");
            }
            else {
                printf("Shutdown aborted.\n");
            }
        }
        else if (strcmp(command, "reboot\n") == 0) {
            printf("Are you sure you want to reboot the system? (y/n) ");
            char response[2];
            fgets(response, 2, stdin);

            if (response[0] == 'y') {
                system("reboot");
            }
            else {
                printf("Reboot aborted.\n");
            }
        }
        else if (strcmp(command, "users\n") == 0) {
            system("w");
        }
        else if (strcmp(command, "disk-usage\n") == 0) {
            system("df -h");
        }
        else if (strcmp(command, "cpu-info\n") == 0) {
            system("cat /proc/cpuinfo");
        }
        else if (strcmp(command, "ip-address\n") == 0) {
            system("ifconfig");
        }
        else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}