//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alien_level, defense_level;
    float invasion_probability;

    printf("Welcome to the C Alien Invasion Probability Calculator!\n");
    printf("Please enter the level of alien threat (1-10): ");
    scanf("%d", &alien_level);

    printf("Please enter the level of planetary defense (1-10): ");
    scanf("%d", &defense_level);

    // Calculate invasion probability based on alien and defense levels
    srand(time(NULL));
    invasion_probability = ((float)alien_level / defense_level) * (float)(rand() % 101) / 100;

    printf("Calculating invasion probability...\n");
    printf("The invasion probability is %f.\n", invasion_probability);

    // Check if invasion probability is high enough for invasion to occur
    if (invasion_probability > 0.5)
    {
        printf("ALERT! Alien invasion imminent!\n");
    }
    else
    {
        printf("Invasion probability is low. No immediate threat detected.\n");
    }

    return 0;
}