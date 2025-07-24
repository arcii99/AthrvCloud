//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Seed the random number generator with the current time
    
    int invasion_odds = rand() % 101;  // Generate a random number between 0-100 for the likelihood of an alien invasion
    
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("The probability of an alien invasion is: %d%%\n", invasion_odds);
    
    // Determine the likelihood of specific types of aliens based on the invasion odds
    if (invasion_odds <= 25)
    {
        printf("\nThis invasion is likely to be carried out by small probing aliens.\n");
    }
    else if (invasion_odds <= 50)
    {
        printf("\nThis invasion is likely to be carried out by tall humanoid aliens.\n");
    }
    else if (invasion_odds <= 75)
    {
        printf("\nThis invasion is likely to be carried out by insectoid aliens.\n");
    }
    else
    {
        printf("\nThis invasion is likely to be carried out by intelligent machine aliens.\n");
    }
    
    return 0;
}