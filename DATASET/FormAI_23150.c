//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int intel; // Alien intelligence level
    int tech; // Alien technology level
    int invasion_prob; // Probability of alien invasion
    srand(time(0)); // Set random seed
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the estimated alien intelligence level (1-10): ");
    scanf("%d", &intel);
    
    printf("Please enter the estimated alien technology level (1-10): ");
    scanf("%d", &tech);
    
    // Calculate invasion probability
    invasion_prob = ((intel * 2) + (tech * 3)) * (rand() % 50 + 51);
    
    // Check for valid probability range
    if (invasion_prob > 100)
    {
        invasion_prob = 100;
    }
    else if (invasion_prob < 0)
    {
        invasion_prob = 0;
    }
    
    printf("Based on the estimated alien intelligence level of %d and technology level of %d,\n", intel, tech);
    printf("the probability of an alien invasion is approximately %d percent.\n", invasion_prob);
    
    if (invasion_prob >= 50)
    {
        printf("The probability of an invasion is quite high. Please take all necessary precautions.\n");
    }
    else
    {
        printf("The probability of an invasion is relatively low. However, it is always better to be prepared.\n");
    }
    
    return 0;
}