//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char path[100];
    printf("Enter path to analyze: ");
    scanf("%s", path);

    int choice;
    printf("Choose an option: \n");
    printf("1. Get total disk space usage\n");
    printf("2. Get space usage by file type\n");
    printf("3. Identify largest files\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            // Code to calculate total disk space usage
            break;
        case 2:
            // Code to calculate disk space usage by file type
            break;
        case 3:
            // Code to identify largest files
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }

    printf("Thank you for using our program! We hope you're happy with the results.\n");
    return 0;
}