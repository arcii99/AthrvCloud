//FormAI DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the System Administration Program.\n");

    char choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Display system information\n");
        printf("2. Display currently logged in users\n");
        printf("3. Restart the system\n");
        printf("4. Shutdown the system\n");
        printf("5. Exit program\n");

        fflush(stdin); // clear any input buffer
        choice = getchar(); // read user's choice

        switch (choice) {
            case '1':
                printf("\nSystem information:\n");
                system("uname -a");
                break;
            case '2':
                printf("\nCurrently logged in users:\n");
                system("who");
                break;
            case '3':
                printf("\nRestarting the system...\n");
                system("sudo shutdown -r now");
                break;
            case '4':
                printf("\nShutting down the system...\n");
                system("sudo shutdown -h now");
                break;
            case '5':
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}