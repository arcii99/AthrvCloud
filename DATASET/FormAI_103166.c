//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float alien_invasion_probability;

    // Initializing random number generator
    srand(time(NULL));

    int number_of_times_invasion_occurs = 0;
    int iterations = 10000;

    for(int i=0; i<iterations; i++)
    {
        // Randomly generating a probability between 0 and 1
        float probability = (float)rand()/(float)RAND_MAX;

        // If probability is greater than 0.5, then the invasion occurs
        if(probability > 0.5)
        {
            number_of_times_invasion_occurs++;
        }
    }

    // Calculating the probability using the number of times invasion occurs and iterations
    alien_invasion_probability = ((float)number_of_times_invasion_occurs/(float)iterations)*100;

    printf("Alien Invasion Probability: %.2f %%\n", alien_invasion_probability);

    return 0;
}