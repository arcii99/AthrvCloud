//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void controlLights(int level)
{
    if (level == 0)
    {
        printf("All lights are turned off.\n");
    }
    else
    {
        printf("Lights are turned on for level %d.\n", level);
        controlLights(level - 1);
    }
}

int main()
{
    int level;

    printf("Enter the level to turn on lights (0 for turning off all lights): ");
    scanf("%d", &level);

    if (level < 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    controlLights(level);

    return 0;
}