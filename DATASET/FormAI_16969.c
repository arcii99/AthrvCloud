//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator
    int num_iterations = 100000; // number of iterations for the simulation
    int alien_attacks = 0; // number of successful alien attacks
    int total_population = 1000000000; // total population of Earth
    int invasion_success_threshold = total_population * 0.7; // percentage of population required for successful invasion

    for (int i = 0; i < num_iterations; i++) 
    {
        int alien_population = rand() % 10000000 + 10000000; // random number for alien population
        int invasion_success = rand() % total_population + 1; // random number for invasion success rate
        if (invasion_success <= invasion_success_threshold) // if invasion is successful
        {
            alien_attacks++; //increment successful attack count
        } 
    }

    float probability = (float) alien_attacks / num_iterations * 100; //calculate probability of alien invasion

    printf("Based on the simulation of %d iterations, the probability of a successful alien invasion on Earth is %.2f%%.", num_iterations, probability);

    return 0;
}