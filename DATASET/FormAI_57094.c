//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include <stdio.h>

int main() {
    printf("Welcome to the System Administration Example Program!\n");

    // Check if the user is logged in as root
    if (geteuid()) {
        printf("ERROR: You need to be logged in as root to run this program.\n");
        return 1;
    }

    // Prompt the user for which operation they would like to perform
    int choice;
    printf("Please choose an operation to perform:\n");
    printf("1. List all users on the system\n");
    printf("2. List all running processes\n");
    printf("3. View system logs\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // List all users on the system
            system("cat /etc/passwd | cut -d: -f1");
            break;
        case 2:
            // List all running processes
            system("ps aux");
            break;
        case 3:
            // View system logs
            system("tail /var/log/syslog");
            break;
        default:
            printf("ERROR: Invalid choice.");
            break;
    }

    return 0;
}