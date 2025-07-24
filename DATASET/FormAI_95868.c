//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

int main()
{
    int lightStatus = LIGHT_OFF;

    printf("Welcome to the Smart Home Light Control System\n");

    while(1)
    {
        printf("\nEnter 1 to turn on the lights or 0 to turn them off: ");

        int userInput;
        scanf("%d", &userInput);

        if(userInput == 1)
        {
            lightStatus = LIGHT_ON;
            printf("Lights turned ON\n");
        }
        else if(userInput == 0)
        {
            lightStatus = LIGHT_OFF;
            printf("Lights turned OFF\n");
        }
        else
        {
            printf("Invalid input! Please try again.\n");
            continue;
        }

        if(lightStatus == LIGHT_ON)
        {
            printf("It's bright in here!\n");
        }
        else if(lightStatus == LIGHT_OFF)
        {
            printf("It's dark in here!\n");
        }
    }

    return 0;
}