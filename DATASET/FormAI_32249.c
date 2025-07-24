//FormAI DATASET v1.0 Category: Temperature monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature = 0.0;
    int choice = 0;
    srand(time(0));
    printf("Welcome to Unique C Temperature Monitor!\n");
    printf("1. Check current temperature\n");
    printf("2. Check temperature history\n");
    printf("3. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                temperature = (float)(rand() % 15) + 15.0;
                printf("The current temperature is %.2f C\n", temperature);
                break;
            case 2:
                printf("Sorry, this feature is not available yet.\n");
                break;
            case 3:
                printf("Thank you for using Unique C Temperature Monitor!\n");
                exit(0);
            default:
                printf("Invalid choice, please enter a number between 1 and 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}