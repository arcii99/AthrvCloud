//FormAI DATASET v1.0 Category: System boot optimizer ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C System boot optimizer!\n\n");

    // Gather user input for desired optimization methods
    int option;
    printf("Please select the optimization method you wish to apply:\n");
    printf("1) Disk Cleanup\n");
    printf("2) Registry Cleaner\n");
    printf("3) Startup Manager\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            // Perform disk cleanup operations
            printf("Performing disk cleanup...\n");
            system("cleanmgr /sagerun:1");
            printf("Disk cleanup complete!\n");
            break;
        case 2:
            // Perform registry cleaner operations
            printf("Performing registry cleaner...\n");
            system("regedit /s \"C:\\Users\\User\\Documents\\registry_cleaner.reg\"");
            printf("Registry cleaner complete!\n");
            break;
        case 3:
            // Perform startup manager operations
            printf("Configuring startup programs...\n");
            system("msconfig");
            printf("Startup programs configured!\n");
            break;
        default:
            printf("Invalid option selected!\n");
    }

    printf("\nThe C System boot optimizer has finished running. Goodbye!");

    return 0;
}