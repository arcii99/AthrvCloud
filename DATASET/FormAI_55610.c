//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int earth_population, military_strength;
    float invasion_probability, alien_technology;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please answer the following questions so we can calculate the probability of an alien invasion.\n");
    printf("What is the current population of Earth (in billions)? ");
    scanf("%d", &earth_population);

    printf("What is the military strength of Earth (in millions of soldiers)? ");
    scanf("%d", &military_strength);

    srand(time(NULL));
    alien_technology = (float)rand() / RAND_MAX;

    if (alien_technology < 0.5)
    {
        printf("Uh oh, it looks like the aliens have advanced technology! This is not looking good for Earth...\n");
        printf("Probability of invasion: 99.9%%\n");
    }
    else
    {
        invasion_probability = (float)earth_population * military_strength / (float)RAND_MAX * alien_technology;
        printf("Calculating invasion probability...\n");
        printf("Probability of invasion: %.2f%%\n", invasion_probability);
    }

    printf("Thank you for using the Alien Invasion Probability Calculator! Please come again when the aliens attack.\n");

    return 0;
}