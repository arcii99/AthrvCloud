//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_INVASION_THRESHOLD 0.75 // Probability threshold for alien invasion

int main()
{
    double alien_prob; // Probability of alien invasion
    int num_invasions = 0; // Number of simulated invasions
    int num_iterations; // Number of times to repeat the simulation
    int num_successful_inv = 0; // Number of successful invasions
   
    // Seed random number generator
    srand(time(NULL));
    
    // Take input for number of times to simulate
    printf("Enter the number of times to simulate: ");
    scanf("%d", &num_iterations);
    
    // Perform simulation for each iteration
    for(int i = 1; i <= num_iterations; i++){
        alien_prob = (double) rand() / (RAND_MAX); // Generate random probability
        
        printf("\nSimulation %d: Probability of Alien Invasion: %0.2f\n", i, alien_prob);
        
        // Check if invasion is successful
        if(alien_prob >= ALIEN_INVASION_THRESHOLD){
            printf("Alien invasion successful!\n");
            num_successful_inv++;
        }
        else {
            printf("No alien invasion\n");
        }
        num_invasions++;
    }
    
    // Calculate probability of alien invasion and print results
    double invasion_prob = (double) num_successful_inv / (double) num_invasions;
    printf("\n--------------\n");
    printf("Simulation Results\n");
    printf("--------------\n");
    printf("Number of Invasions Simulated: %d\n", num_invasions);
    printf("Number of Successful Invasions: %d\n", num_successful_inv);
    printf("Probability of Alien Invasion: %0.2f\n", invasion_prob);
    
    return 0;
}