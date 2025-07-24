//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alienProb, humanProb, randNum;

    srand(time(0)); // Seed the random number generator

    alienProb = rand() % 101; // Generate a random alien probability (0-100)
    humanProb = 100 - alienProb; // Calculate the human probability

    printf("Alien Invasion Probability: %d percent\n", alienProb);
    printf("Human Survival Probability: %d percent\n", humanProb);

    // Check the probability and give a recommendation
    if(alienProb < 25)
    {
        printf("The probability of an alien invasion is low. Don't worry too much!\n");
    }
    else if(alienProb < 50)
    {
        printf("The probability of an alien invasion is moderate. Keep an eye out!\n");
    }
    else if(alienProb < 75)
    {
        printf("The probability of an alien invasion is high. Prepare for the worst!\n");
    }
    else
    {
        printf("The probability of an alien invasion is very high. We are likely doomed!\n");
    }

    return 0;
}