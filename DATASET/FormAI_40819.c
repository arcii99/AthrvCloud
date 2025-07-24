//FormAI DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int light=0;
    char choice;
    printf("\n\t\t*** Welcome to Smart Light Control ***\n");
    while(1)
    {
        printf("\nCurrent Light Status: ");
        if(light == 0)
        {
            printf("OFF\n");
        }
        else
        {
            printf("ON\n");
        }

        printf("\nEnter your choice (1 for ON / 0 for OFF / Q for Quit): ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                light = 1;
                printf("Turning On Light...\n");
                break;

            case '0':
                light = 0;
                printf("Turning Off Light...\n");
                break;

            case 'Q':
            case 'q':
                printf("Thank you for using Smart Light Control.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}