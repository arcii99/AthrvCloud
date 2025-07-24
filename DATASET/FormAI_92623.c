//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    float distance, population, technology, invasionProbability;
    
    printf("Please enter the distance of the planet from Earth (in light years): ");
    scanf("%f", &distance);
    printf("Please enter the population of the planet (in millions): ");
    scanf("%f", &population);
    printf("Please enter the technology level of the planet (1-10): ");
    scanf("%f", &technology);
    
    //Calculating probability of invasion based on distance
    if(distance<=5)
        invasionProbability = 0.85;
    else if(distance<=10)
        invasionProbability = 0.75;
    else if(distance<=50)
        invasionProbability = 0.5;
    else if(distance<=100)
        invasionProbability = 0.3;
    else
        invasionProbability = 0.1;
    
    //Adjusting probability based on population and technology level
    invasionProbability -= (population/100) + (10- technology)*0.03;
    
    //Displaying the final probability
    printf("The probability of an alien invasion from this planet is %.2f%%", invasionProbability*100);
    
    return 0;
}