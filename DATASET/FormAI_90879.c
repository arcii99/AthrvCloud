//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("***Welcome to the Smart Home Light Control System***\n");
    printf("Press 1 to turn on the lights\n");
    printf("Press 2 to turn off the lights\n");
    printf("Press 3 to dim the lights\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("The lights are now on. Enjoy!\n");
    }
    else if (choice == 2)
    {
        printf("The lights are now off. Goodnight!\n");
    }
    else if (choice == 3)
    {
        int brightness;
        printf("Enter the brightness level (0-100): ");
        scanf("%d", &brightness);

        if (brightness < 0)
        {
            printf("Invalid brightness level. Setting brightness to minimum (0).\n");
            brightness = 0;
        }
        else if (brightness > 100)
        {
            printf("Invalid brightness level. Setting brightness to maximum (100).\n");
            brightness = 100;
        }

        printf("The lights are now dimmed to %d%%. Relax!\n", brightness);
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}