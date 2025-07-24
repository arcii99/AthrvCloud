//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numOfDays, probability = 0;
    double hitChance;
    
    srand(time(0)); // seeding rand() with current time for pseudorandom values
    
    printf("Welcome to the Alien Invasion probability calculator!\n");
    printf("Enter the number of days you want to calculate the probability for: ");
    scanf("%d", &numOfDays);
    
    for(int i = 0; i < numOfDays; i++)
    {
        int alienInvaded = rand() % 10; // generating a number between 0 and 9 randomly
      
        if(alienInvaded < 3) // assuming only 30% chance of invasion on any given day
        {
            printf("Day %d: Alien invasion detected!\n", i+1);
            probability++;
        }
        else
        {
            printf("Day %d: Everything looks normal.\n", i+1);
        }
    }
    
    hitChance = (double)probability / (double)numOfDays * 100.0; // calculating hit chance percentage
    
    printf("Based on the probability of 30%% per day, for %d days:\n", numOfDays);
    printf("Probability of Alien Invasion: %d/%d\n", probability, numOfDays);
    printf("Hit Chance Percentage: %.2lf%%\n", hitChance);
    
    return 0;
}