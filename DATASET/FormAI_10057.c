//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/***********************************************************************

Program: Alien Invasion Probability Calculator

Description: This program calculates the probability of an alien invasion
             based on statistical data. It takes user inputs and returns 
             the probability in percentage.
             
Authors: [YOUR NAME]

Date: [DATE]

************************************************************************/

int main()
{
    int planets, civilizations, contact, invasion, i;
    float average, deviation, probability, n;

    printf("Welcome to Alien Invasion Probability Calculator!\n");

    /* Getting user inputs */

    printf("\nEnter the number of planets in the universe: ");
    scanf("%d", &planets);

    printf("\nEnter the number of planets that can support life: ");
    scanf("%d", &civilizations);

    printf("\nEnter the number of civilizations that have achieved the technological level necessary for interstellar communication: ");
    scanf("%d", &contact);

    printf("\nEnter the number of civilizations that have shown hostile intent towards other species: ");
    scanf("%d", &invasion);

    /* Calculating the average and deviation */

    average = (float)civilizations / (float)planets;

    deviation = sqrt((average * (1 - average)) / (float)planets);

    /* Calculating the probability of an alien invasion */

    n = (float)contact - (average * (float)planets);

    probability = 100 * (1 - exp(pow(n, 2) / (-2 * pow(deviation, 2))));
    
    if(probability < 0)
    {
        probability = 0;
    }
    else if(probability > 100)
    {
        probability = 100;
    }

    /* Displaying the result */

    printf("\nThe probability of an alien invasion is: %.2f%%\n", probability);

    return 0;
}