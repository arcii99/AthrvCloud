//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>

int main() {
    int option;

    printf("Welcome to System Administration Program!\n");

    do {
        printf("\nPlease select an option: \n");
        printf("1. View CPU usage\n");
        printf("2. List running processes\n");
        printf("3. View memory usage\n");
        printf("4. Exit\n");

        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nCPU Usage: 40%%\n");
                break;
            case 2:
                printf("\nRunning Processes:\n");
                system("ps -aux");
                break;
            case 3:
                printf("\nMemory Usage: 64 MB\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while(option != 4);

    return 0;
}