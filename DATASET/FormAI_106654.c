//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int choice;

    printf("Welcome to the peaceful system administration program.\n\n");

    printf("Please select one of the following options:\n");
    printf("1. View Processes\n");
    printf("2. View Disk Space\n");
    printf("3. Shutdown Machine\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            // Code to view processes
            printf("Listing processes...\n");
            system("ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head");
            break;

        case 2:
            // Code to view disk space
            printf("Displaying disk space...\n");
            system("df -h");
            break;

        case 3:
            // Code to shutdown machine
            printf("Shutting down machine...\n");
            system("shutdown -P now");
            break;

        case 4:
            // Exit program
            printf("Exiting program...\n");
            exit(0);
            break;

        default:
            printf("Invalid selection, please try again.\n");
            break;
    }

    return 0;
}