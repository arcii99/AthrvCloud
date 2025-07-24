//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_SIMULATIONS 1000000 // number of simulations
#define INVASION_THRESHOLD 0.75 // threshold for invasion probability

int main()
{
    int i, j, k, invaded, total_invasions;
    float invasion_probability;
    double rand_num; // variable for generating random numbers
    
    srand(time(NULL)); // seeding the random number generator with the current time

    total_invasions = 0;
    for (i = 0; i < NUM_OF_SIMULATIONS; i++)
    {
        invaded = 0;
        for (j = 0; j < 100; j++) // assume there are 100 cities
        {
            for (k = 0; k < 10; k++) // assume each city has 10 defense systems
            {
                rand_num = (double)rand() / RAND_MAX; // generating a random number between 0 and 1
                if (rand_num < 0.02) // probability of defense system failing is 2%
                {
                    invaded = 1; // if defense system fails, invasion is successful
                    break;
                }
            }
            if (invaded == 1) // if invasion is successful, no need to check other cities
            {
                break;
            }
        }
        if (invaded == 1) // counting the number of invasions
        {
            total_invasions++;
        }
    }

    invasion_probability = (float)total_invasions / NUM_OF_SIMULATIONS; // calculating invasion probability

    printf("The probability of alien invasion is: %f\n", invasion_probability);

    if (invasion_probability > INVASION_THRESHOLD)
    {
        printf("There is a high probability of alien invasion. Take necessary precautions!\n");
    }
    else
    {
        printf("The probability of alien invasion is within acceptable limits. No need to panic!\n");
    }

    return 0;
}