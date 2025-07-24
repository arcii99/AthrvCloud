//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random number generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    char userInput;
    do
    {
        printf("\nWhat is the size of the population (in millions)? ");
        int population;
        scanf("%d", &population);

        printf("What is the percentage of the population that is hidden underground? ");
        int undergroundPercent;
        scanf("%d", &undergroundPercent);

        int undergroundPopulation = (population * undergroundPercent) / 100;
        int abovegroundPopulation = population - undergroundPopulation;

        int abovegroundAliens = rand() % abovegroundPopulation + 1; // generate random number of alien ships in aboveground population
        int undergroundAliens = rand() % undergroundPopulation + 1; // generate random number of alien ships in underground population

        float abovegroundAlienProbability = (float)abovegroundAliens / abovegroundPopulation * 100;
        float undergroundAlienProbability = (float)undergroundAliens / undergroundPopulation * 100;

        printf("\nProbability of alien invasion in aboveground population: %.2f\n", abovegroundAlienProbability);
        printf("Probability of alien invasion in underground population: %.2f\n", undergroundAlienProbability);

        printf("\nDo you want to calculate the probability again? (Y/N) ");
        scanf(" %c", &userInput);
    }
    while (userInput == 'Y' || userInput == 'y');

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}