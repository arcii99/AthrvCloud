//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    int alienTechLevel = 0;
    int totalPossibleCivilizations = 1000000;
    int intelligentCivilizations = 0;
    int technologicalCivilizations = 0;
    int broadcastingCivilizations = 0;
    int nearbyCivilizations = 0;
    int contactableCivilizations = 0;

    printf("\nPlease enter the alien civilization's technology level (0-10): ");
    scanf("%d", &alienTechLevel);

    printf("\nCalculating probability...\n\n");

    srand(time(NULL));

    for (int i = 0; i < totalPossibleCivilizations; i++)
    {
        int techLevel = rand() % 11;
        if (techLevel == alienTechLevel)
        {
            intelligentCivilizations++;
            if (rand() % 2 == 1)
            {
                technologicalCivilizations++;
                if (rand() % 2 == 1)
                {
                    broadcastingCivilizations++;
                    if (rand() % 2 == 1)
                    {
                        nearbyCivilizations++;
                        if (rand() % 2 == 1)
                        {
                            contactableCivilizations++;
                        }
                    }
                }
            }
        }
    }

    printf("Based on our calculations, the probability of an alien civilization with a technology level of %d having the following characteristics is as follows:\n", alienTechLevel);
    printf("Intelligent: %f%%\n", ((float)intelligentCivilizations / (float)totalPossibleCivilizations) * 100);
    printf("Technological: %f%%\n", ((float)technologicalCivilizations / (float)totalPossibleCivilizations) * 100);
    printf("Broadcasting: %f%%\n", ((float)broadcastingCivilizations / (float)totalPossibleCivilizations) * 100);
    printf("Nearby: %f%%\n", ((float)nearbyCivilizations / (float)totalPossibleCivilizations) * 100);
    printf("Contactable: %f%%\n", ((float)contactableCivilizations / (float)totalPossibleCivilizations) * 100);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    return 0;
}