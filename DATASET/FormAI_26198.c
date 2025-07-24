//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    printf("Welcome to System Administration Program!\n");
    printf("What would you like to do today?\n");
    printf("1) Check system status\n");
    printf("2) Kill a process\n");
    printf("3) Reboot system\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            printf("System status:\n");
            system("top -n 1");
            break;
        case 2:
            printf("Enter process id to kill:\n");
            int pid;
            scanf("%d", &pid);
            char command[50];
            snprintf(command, 50, "kill %d", pid);
            system(command);
            printf("Process %d killed successfully.\n", pid);
            break;
        case 3:
            printf("Are you sure you want to reboot? (y/n)\n");
            char answer[2];
            scanf("%s", answer);
            if(answer[0] == 'y' || answer[0] == 'Y') {
                printf("Rebooting system...\n");
                system("reboot");
            } else {
                printf("Reboot cancelled.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}