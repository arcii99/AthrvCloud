//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting the seed for generating random numbers
    srand(time(NULL));

    int earth_defense, alien_technology, alien_intelligence, alien_numbers;
    float invasion_probability;

    // Getting input values from the user
    printf("Enter Earth's defense capability (1-10): ");
    scanf("%d", &earth_defense);
    printf("Enter Alien technology superiority (1-10): ");
    scanf("%d", &alien_technology);
    printf("Enter Alien intelligence (1-10): ");
    scanf("%d", &alien_intelligence);
    printf("Enter number of alien ships (1-100): ");
    scanf("%d", &alien_numbers);

    // Calculating invasion probability
    int earth_strength = (earth_defense + 5) * 10;
    int alien_strength = (alien_technology + alien_intelligence + 5) * alien_numbers;

    invasion_probability = (float)alien_strength/earth_strength;

    // Checking the probability and displaying the result
    if(invasion_probability <= 0.2)
    {
        printf("\nAlien invasion probability: %.2f%%\n", invasion_probability*100);
        printf("Earth's defense forces are much stronger than the alien forces. We are safe... for now.\n");
    }
    else if(invasion_probability <= 0.5)
    {
        printf("\nAlien invasion probability: %.2f%%\n", invasion_probability*100);
        printf("The aliens might pose a threat, but Earth still has a chance to win the war.\n");
    }
    else
    {
        printf("\nAlien invasion probability: %.2f%%\n", invasion_probability*100);
        printf("Earth is in grave danger. We need to prepare for the worst.\n");
    }

    return 0;
}