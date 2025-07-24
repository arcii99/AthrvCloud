//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initialize variables
    int probability = 0;
    int aliens = 0;
    int years = 0;

    //get user input
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens currently detected on Earth: ");
    scanf("%d", &aliens);

    printf("Please enter the number of years into the future you want to calculate: ");
    scanf("%d", &years);

    //calculate probability
    probability = aliens * years;

    //add some randomness to the probability
    probability = probability + (rand() % 100);

    //display results
    printf("\nBased on current data, there is a %d%% chance of an alien invasion in %d years.\n", probability, years);

    return 0;
}