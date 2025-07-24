//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k;
    double prob;
    int alien_ships, time_to_arrival, earth_population;
    char cont;

    srand(time(NULL)); //Initializing random seed

    do
    {
        printf("\nWelcome to the Alien Invasion Probability Calculator!\n");
        printf("=====================================================\n");

        printf("\nEnter the number of alien ships: ");
        scanf("%d", &alien_ships);

        printf("Enter the time until their arrival (in days): ");
        scanf("%d", &time_to_arrival);

        printf("Enter the population of Earth: ");
        scanf("%d", &earth_population);

        printf("\nCalculating invasion probability...\n\n");

        // Calculating probability based on various factors
        prob = (double) alien_ships / (time_to_arrival / 10) * (earth_population / 1000000000.0) * (rand() % 101) / 100.0;

        if(prob > 100) //Limiting probability to maximum 100%
        {
            prob = 100;
        }

        printf("Based on %d alien ships arriving in %d days, with Earth population at %d billion,\n", alien_ships, time_to_arrival, earth_population);
        printf("the probability of an alien invasion is %.2lf%%.\n", prob);

        printf("\nDo you want to calculate again (Y/N)? ");
        scanf(" %c", &cont);

    } while(cont == 'Y' || cont == 'y');

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}