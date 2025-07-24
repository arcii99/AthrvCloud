//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator

    printf("                    Alien Invasion Probability Calculator\n\n");
    printf("                   ##########################################\n\n");

    printf("This program will determine the likelihood of an alien invasion based on a few variables.\n\n");

    int numPlanets = rand() % 10000 + 1; // Generate a random number of planets in the galaxy
    int numInhabitablePlanets = rand() % numPlanets + 1; // Generate a random number of inhabitable planets in the galaxy

    printf("According to our research, there are approximately %d planets in the galaxy.\n", numPlanets);
    printf("Out of those planets, it is estimated that %d are potentially inhabitable by intelligent life.\n\n", numInhabitablePlanets);

    printf("Please specify the percentage of intelligent life on each of these inhabitable planets: ");
    float intelligentLifePercentage;
    scanf("%f", &intelligentLifePercentage);

    printf("\nBased on your input, we can conclude that approximately %.2f%% of all inhabitable planets have intelligent life.\n\n", intelligentLifePercentage);

    printf("Next, we need to determine the probability that these intelligent beings have the technology for interstellar travel.\n");
    int techChance = rand() % 101; // Generate a random number between 0 and 100 for the chance of interstellar technology
    printf("\nBased on our analysis, there is a %d%% chance that intelligent life has interstellar travel capability.\n\n", techChance);

    printf("Lastly, we need to consider the probability that these interstellar beings would choose to visit Earth.\n");
    printf("Please specify the percentage chance that these intelligent beings would choose to visit Earth: ");
    int invasionChance;
    scanf("%d", &invasionChance);
    printf("\nBased on your input, there is a %d%% chance that any interstellar beings would choose to visit Earth.\n\n", invasionChance);

    float totalChance = ((float)numInhabitablePlanets / (float)numPlanets) * (intelligentLifePercentage / 100) * (techChance / 100.0) * (invasionChance / 100.0);
    printf("After our calculations, we have determined that the probability of an alien invasion is approximately %.6f%%.\n", totalChance * 100);

    printf("\n                    Thank you for using the Alien Invasion Probability Calculator!\n\n");
    printf("                   ##########################################\n");

    return 0;
}