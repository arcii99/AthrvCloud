//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Welcome to my unique system administration example program!\n");
    printf("This program will help you manage your server with ease.\n\n");

    while(1) {
        printf("Please select an option from the following admin commands:\n");
        printf("1. Check system status\n");
        printf("2. View system logs\n");
        printf("3. Restart services\n");
        printf("4. Update packages\n");
        printf("5. Exit program\n\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("top"); // Display system status
                break;
            case 2:
                system("tail /var/log/syslog"); // View system logs
                break;
            case 3:
                system("service apache2 restart && service mysql restart"); // Restart services
                printf("Services have been restarted.\n");
                break;
            case 4:
                system("apt-get update && apt-get upgrade"); // Update packages
                printf("Packages have been updated.\n");
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}