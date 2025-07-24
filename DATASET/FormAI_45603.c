//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random number generator
    
    int num_days, num_attempts, num_successful_attacks = 0;
    float prob; 
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many days do you think it will take for the aliens to invade? (Enter a number from 1 to 10)\n");
    scanf("%d", &num_days);
    
    printf("How many times do you want to attempt the invasion? (Enter a number from 1 to 10000)\n");
    scanf("%d", &num_attempts);
    
    printf("Calculating probability....\n");
    
    for (int i = 0; i < num_attempts; i++)
    {
        int invasion_day = rand() % 10 + 1;
        
        if (invasion_day <= num_days)
        {
            num_successful_attacks++;
        }
    }
    
    prob = (float) num_successful_attacks / num_attempts * 100;
    
    printf("Probability of successful invasion within %d days: %.2f%%\n", num_days, prob);
    
    if (prob > 50)
    {
        printf("Looks like the aliens have a good chance of invading soon. You should start preparing!\n");
    }
    else
    {
        printf("The probability of an invasion within %d days is low. You can relax for now.\n", num_days);
    }
    
    return 0;
}