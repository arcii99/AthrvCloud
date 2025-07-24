//FormAI DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

int main(){

    int userOption;
    printf("Welcome to the C system boot optimizer program.\n");
    printf("Please select an option from the menu:\n");
    printf("1. Disable unnecessary startup programs.\n");
    printf("2. Disable system services not needed for boot.\n");
    printf("3. Manage system boot process priority.\n");
    printf("4. Exit program.\n");
    printf("Your option: ");

    // Take user's input
    scanf("%d", &userOption);

    // Switch-case to execute user's desired action
    switch(userOption){
        case 1:
            printf("You have selected to disable unnecessary startup programs.\n");
            // Code to disable unnecessary programs
            break;

        case 2:
            printf("You have selected to disable system services not needed for boot.\n");
            // Code to disable unnecessary services
            break;

        case 3:
            printf("You have selected to manage system boot process priority.\n");
            // Code to manage boot process priority
            break;

        case 4:
            printf("Exiting program...");
            exit(0);

        default:
            printf("Invalid option selected. Please try again.\n");
            break;
    }

    return 0;
}