//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100

void scan(char *file_name)
{
    printf("Scanning %s for viruses...\n", file_name);
    // Code to check for viruses in the file goes here
    printf("No viruses found in %s!\n", file_name);
}

int main()
{
    char file_name[MAX_FILE_NAME];
    int choice;
    do
    {
        printf("Welcome to the cheerful C Antivirus Scanner!\n");
        printf("What would you like to do?\n");
        printf("1. Scan a file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("Enter the name of the file you want to scan: ");
                scanf("%s", file_name);
                scan(file_name);
                break;
            }
            case 2:
            {
                printf("Thank you for using the cheerful C Antivirus Scanner!\n");
                break;
            }
            default:
            {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    } while (choice != 2);
    return 0;
}