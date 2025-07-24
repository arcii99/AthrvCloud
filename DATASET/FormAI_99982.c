//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alienShips,defenseTurrets,defenseOperators;
    float defenseRating, invasionProbability;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    
    // User input for number of alien ships
    printf("How many alien ships are estimated to be approaching? ");
    scanf("%d",&alienShips);
    
    // User input for number of defense turrets
    printf("How many defense turrets are currently operational? ");
    scanf("%d",&defenseTurrets);
    
    // User input for number of defense operators
    printf("How many trained defense operators are available? ");
    scanf("%d",&defenseOperators);
    
    // Calculating defense rating based on number of turrets and operators
    defenseRating = (float)defenseTurrets*defenseOperators/100;
    
    // Generating random seed for alien invasion probability
    srand(time(0));
    
    // Calculating alien invasion probability using defense rating and number of alien ships
    invasionProbability = (float)alienShips/(defenseRating+1)*rand()/RAND_MAX;
    
    // Displaying the calculated invasion probability
    printf("\nBased on the current defenses and estimated number of alien ships, the invasion probability is %.2f%%\n",invasionProbability*100);
    
    return 0;
}