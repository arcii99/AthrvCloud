//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize the random number generator
    srand(time(0));

    // Define the variables
    float probability = 0.0;
    int num_of_aliens = 0;

    // Generate a random number of aliens between 10 and 100
    num_of_aliens = rand() % 91 + 10;

    // Display the number of aliens
    printf("According to recent reports, there are %d alien spacecraft approaching Earth.\n", num_of_aliens);

    // Calculate the probability of an alien invasion
    if (num_of_aliens <= 20)
    {
        probability = 0.05;
    }
    else if (num_of_aliens <= 50)
    {
        probability = 0.25;
    }
    else if (num_of_aliens <= 75)
    {
        probability = 0.50;
    }
    else
    {
        probability = 0.75;
    }

    // Display the probability of an alien invasion
    printf("Based on the number of alien spacecraft detected, the probability of an invasion is %.2f%%.\n", probability * 100);

    // Determine if the aliens will invade
    if ((float)rand() / RAND_MAX < probability)
    {
        printf("ALERT: Alien invasion is imminent!\n");
    }
    else
    {
        printf("Good news: The probability of an alien invasion is lower than expected.\n");
    }

    return 0;
}