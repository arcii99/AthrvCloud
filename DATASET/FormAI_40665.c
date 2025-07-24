//FormAI DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declaring variables
    int option, choice;
    char command[50];

    printf("Welcome to the System Administration Program!\n");
    printf("----------------------------------------------\n");

    while(1) // continuous loop until user exits the program
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Check System Information.\n");
        printf("2. Run a System Command.\n");
        printf("3. Exit the Program.\n");

        scanf("%d", &option);

        switch(option)
        {
            case 1: // checking system information
                printf("\nSystem Information:\n");
                system("uname -a"); // running uname -a command to display system information
                break;

            case 2: // running a system command
                printf("\nEnter the system command: ");
                scanf("%s", command);
                system(command); // running the user-entered command
                break;

            case 3: // exiting the program
                printf("\nExiting the System Administration Program. Thank you for using it.\n");
                exit(0); // exiting the program
                break;

            default:
                printf("\nInvalid Choice!\n"); // for invalid choices
                break;
        }
    }

    return 0; // end of program
}