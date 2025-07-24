//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionProbability = 0;
    srand(time(NULL)); // Initialize random seed
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien spaceships you believe could invade Earth: ");
    int numSpaceships;
    scanf("%d", &numSpaceships);
    
    if (numSpaceships < 1) {
        printf("Invalid input. Number of spaceships must be greater than or equal to 1.");
        return 0;
    }
    
    printf("Please enter the percentage likelihood (1-100) that they will succeed in their invasion: ");
    int successProbability;
    scanf("%d", &successProbability);
    
    if (successProbability < 1 || successProbability > 100) {
        printf("Invalid input. Probability must be between 1-100.");
        return 0;
    }
    
    // Calculate invasion probability
    invasionProbability = (numSpaceships * successProbability * (rand() % 100)) / 10000;
    
    // Display results
    printf("\nBased on the number of spaceships and their probability of success, there is a %d%% chance of an alien invasion.\n", invasionProbability);
    
    printf("\nThank you for using the Alien Invasion Probability Calculator!");
    
    return 0;
}