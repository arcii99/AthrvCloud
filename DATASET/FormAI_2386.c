//FormAI DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_soldiers = 100;
    int num_wounded = 10;
    int num_horses = 90;
    int battlefield_victory = 1;

    // Check if there are enough horses for all the soldiers
    if (num_horses < num_soldiers)
    {
        printf("Ye do not have enough horses for all thy soldiers! Abandon the mission!\n");
        exit(1); // Error code 1: Abandon mission due to lack of horses
    }

    // Check if the number of wounded soldiers is greater than half the total number of soldiers
    if (num_wounded > num_soldiers / 2)
    {
        printf("Ye cannot continue if more than half thy soldiers are wounded! Retreat!\n");
        exit(2); // Error code 2: Retreat due to high number of wounded soldiers
    }

    // Check if the battle was won or lost
    if (battlefield_victory)
    {
        printf("Victory! Glory to thy king!\n");
    }
    else
    {
        printf("Defeat! Thy king shall weep for thy loss...\n");
        exit(3); // Error code 3: Retreat due to loss in battle
    }

    return 0;
}