//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Virtual Machine Control Center!\n");
    printf("Initializing System...\n");
    int count = 10;
    while(count >= 1) {
        printf("%d...\n", count);
        count--;
    }
    printf("System initialized successfully!\n");
    printf("What would you like to do?\n");
    printf("1. Start Virtual Machine\n");
    printf("2. Stop Virtual Machine\n");
    printf("3. Restart Virtual Machine\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Starting Virtual Machine...\n");
            system("sudo virsh start myvm");
            printf("Virtual Machine started successfully!\n");
            break;
        case 2:
            printf("Stopping Virtual Machine...\n");
            system("sudo virsh destroy myvm");
            printf("Virtual Machine stopped successfully!\n");
            break;
        case 3:
            printf("Restarting Virtual Machine...\n");
            system("sudo virsh reboot myvm");
            printf("Virtual Machine restarted successfully!\n");
            break;
        default:
            printf("Invalid option selected. Exiting...\n");
            exit(EXIT_FAILURE);
    }
    printf("Thank you for using the Virtual Machine Control Center!\n");
    return 0;
}