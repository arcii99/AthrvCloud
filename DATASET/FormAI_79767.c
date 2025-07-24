//FormAI DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>

int main()
{
    printf("Welcome to the System Administrator Program!\n");

    // set up variables for user input
    char command[100];
    int confirm = 0;

    // loop until user confirms command
    while (!confirm)
    {
        printf("Please enter a command to execute: ");
        scanf("%s", command);

        printf("Are you sure you would like to execute the command '%s'?\n", command);
        printf("Enter 1 for yes, 0 for no: ");
        scanf("%d", &confirm);
    }

    // execute command
    system(command);

    printf("Command executed successfully. Goodbye!\n");

    return 0;
}