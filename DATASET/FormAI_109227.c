//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); //set the seed for random number generator
    
    int num_of_days;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of days you want to calculate the probability for: ");
    scanf("%d", &num_of_days);
    
    int i, probability = 0;
    for(i = 1; i <= num_of_days; i++)
    {
        int random = rand() % 100 + 1; // generate a random number between 1 and 100
        
        if(random <= 25) // there is a 25% chance of an alien invasion each day
        {
            printf("Day %d: ALIENS ARE ATTACKING!!\n", i);
            probability += 25;
        }
        else
        {
            printf("Day %d: No alien invasion today.\n", i);
        }
    }
    
    if(probability == 0)
    {
        printf("Sorry, the probability of an alien invasion in %d days is 0%%.\n", num_of_days);
    }
    else
    {
        printf("The probability of an alien invasion in %d days is %d%%.\n", num_of_days, probability);
    }
    
    printf("Thank you for using the Alien Invasion Probability Calculator! Stay safe!\n");
    
    return 0;
}