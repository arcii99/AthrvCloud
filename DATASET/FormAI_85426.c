//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int num_alien_planets;
    printf("Enter the number of alien planets in the universe: ");
    scanf("%d", &num_alien_planets);

    int num_habitable_alien_planets;
    printf("Enter the number of habitable alien planets in the universe: ");
    scanf("%d", &num_habitable_alien_planets);
    
    srand(time(NULL)); // initialize random seed based on time

    float probability_of_invasion = 0.0;
    int num_simulations = 1000000;

    for(int i=0; i<num_simulations; i++)
    {
        int random_int = rand() % num_alien_planets + 1; // generate random integer between 1 and num_alien_planets
        if(random_int <= num_habitable_alien_planets)
        {
            probability_of_invasion += 1.0;
        }
    }

    probability_of_invasion /= num_simulations; // calculate probability as average number of invasions in simulations

    printf("The probability of an alien invasion is: %f", probability_of_invasion);

    return 0;
}