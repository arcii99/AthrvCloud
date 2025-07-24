//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float alien_prob; // probability of alien invasion
    int num_observations; // number of observations to make
    
    printf("Alien Invasion Probability Calculator\n");
    printf("-------------------------------------\n\n");
    
    printf("How many observations would you like to make? ");
    scanf("%d", &num_observations);
    
    srand(time(NULL)); // seed the random number generator
    
    for (int i = 1; i <= num_observations; i++)
    {
        int random_num = rand() % 100 + 1; // generate a random number between 1 and 100
        
        if (random_num <= 10) 
        {
            alien_prob = 0.8; // 80% chance of alien invasion if random number is <= 10
        }
        else if (random_num > 10 && random_num <= 25)
        {
            alien_prob = 0.4; // 40% chance of alien invasion if random number is > 10 and <= 25
        }
        else if (random_num > 25 && random_num <= 50)
        {
            alien_prob = 0.2; // 20% chance of alien invasion if random number is > 25 and <= 50
        }
        else 
        {
            alien_prob = 0.05; // 5% chance of alien invasion if random number is > 50 and <= 100
        }
        
        printf("\nObservation #%d\n", i);
        printf("----------------\n");
        printf("Random number generated: %d\n", random_num);
        printf("Probability of alien invasion: %.2f%%\n", alien_prob*100);
    }
    
    return 0;
}