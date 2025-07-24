//FormAI DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    printf("Welcome to the Super SysAdmin Tool!\n");
    while(1) {
        printf("Please enter a command:\n");
        scanf("%s", command);
        if(strcmp(command, "reboot") == 0) {
            printf("Rebooting the system...\n");
            system("reboot");
        } else if(strcmp(command, "status") == 0) {
            printf("Checking system status...\n");
            system("systemctl status");
        } else if(strcmp(command, "shutdown") == 0) {
            printf("Shutting down the system...\n");
            system("shutdown -h now");
        } else if(strcmp(command, "log") == 0) {
            printf("Viewing system logs...\n");
            system("journalctl -u systemd-journald");
        } else if(strcmp(command, "backup") == 0) {
            printf("Backing up the system...\n");
            system("tar -czvf /backup/mybackup.tar.gz /");
            printf("Backup completed successfully!\n");
        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting Super SysAdmin Tool...\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}