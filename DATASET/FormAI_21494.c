//FormAI DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COMMAND_SIZE 100

int main() {
    printf("Welcome to the Visionary System Administration Program.\n");
    printf("Enter system commands below:\n");

    char command[MAX_COMMAND_SIZE];
    fgets(command, MAX_COMMAND_SIZE, stdin); // read input command from user

    if (strcmp(command, "reboot\n") == 0) { // user wants to reboot the system
        printf("Rebooting the system...\n");
        system("sudo reboot");
    } else if (strcmp(command, "shutdown\n") == 0) { // user wants to shutdown the system
        printf("Shutting down the system...\n");
        system("sudo shutdown -h now");
    } else if (strcmp(command, "listusers\n") == 0) { // user wants to list all user accounts
        printf("List of user accounts:\n");
        system("sudo cat /etc/passwd | cut -d: -f1");
    } else if (strcmp(command, "listprocesses\n") == 0) { // user wants to list all running processes
        printf("List of running processes:\n");
        system("sudo ps aux");
    } else if (strcmp(command, "diskusage\n") == 0) { // user wants to check disk usage
        printf("Disk usage:\n");
        system("sudo df -h");
    } else if (strcmp(command, "firewallstatus\n") == 0) { // user wants to check firewall status
        printf("Firewall status:\n");
        system("sudo ufw status");
    } else if (strcmp(command, "updatetime\n") == 0) { // user wants to update system time
        printf("Updating system time...\n");
        system("sudo ntpdate -u pool.ntp.org");
    }

    printf("Thank you for using the Visionary System Administration Program.\n");
    return 0;
}