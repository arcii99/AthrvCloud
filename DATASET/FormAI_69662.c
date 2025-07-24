//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>

int main()
{
    printf("Welcome to the System Administration program!\n\n");

    char option;

    do {
        printf("Please choose from the following options:\n");
        printf("a. Check Disk Space\n");
        printf("b. View Running Processes\n");
        printf("c. List Network Connections\n");
        printf("d. Exit\n");

        scanf(" %c", &option);

        switch (option) {
            case 'a':
                printf("Checking Disk Space...\n");
                // Code to check disk space
                break;

            case 'b':
                printf("Viewing Running Processes...\n");
                // Code to view running processes
                break;

            case 'c':
                printf("Listing Network Connections...\n");
                // Code to list network connections
                break;

            case 'd':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option, please try again\n");
        }

    } while (option != 'd');

    printf("Thank you for using our System Administration program!\n");

    return 0;
}