//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>

int controlLights(int numLights)
{
    if(numLights < 1)
    {
        return 0;
    }
    else
    {
        int status;
        printf("Turn on light %d? (1 = Yes, 0 = No): ", numLights);
        scanf("%d", &status);
        if(status == 1)
        {
            printf("Light %d turned on!\n", numLights);
        }
        else
        {
            printf("Light %d NOT turned on!\n", numLights);
        }
        controlLights(numLights - 1);
    }
}

int main()
{
    int numLights;
    printf("How many lights do you want to control? (1 - 10): ");
    scanf("%d", &numLights);
    printf("\n\n");
    controlLights(numLights);
    printf("\n\nAll lights have been controlled! Goodbye.\n\n");
    return 0;
}