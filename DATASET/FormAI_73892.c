//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float alien_prob, human_prob, alien_ship_prob, alien_stronghold_prob;
    int invasion_overall, invasion_alien_ship, invasion_alien_stronghold;
    
    srand(time(NULL)); // Initialize random seed
    
    // Generate random probabilities for each factor
    alien_prob = ((float)rand()/(float)(RAND_MAX)) * 0.8; // 0 - 0.8
    human_prob = ((float)rand()/(float)(RAND_MAX)) * 0.5; // 0 - 0.5
    alien_ship_prob = ((float)rand()/(float)(RAND_MAX)) * 0.3; // 0 - 0.3
    alien_stronghold_prob = ((float)rand()/(float)(RAND_MAX)) * 0.2; // 0 - 0.2
    
    // Calculate overall invasion probability
    invasion_overall = ((alien_prob * human_prob) + alien_ship_prob + alien_stronghold_prob) * 100;
    
    // Calculate invasion probability from alien ships
    invasion_alien_ship = (alien_prob * human_prob * alien_ship_prob) * 100;
    
    // Calculate invasion probability from alien strongholds
    invasion_alien_stronghold = (alien_prob * human_prob * alien_stronghold_prob * 2) * 100;
    
    // Print out results
    printf("Probability of alien invasion overall: %d %%\n", invasion_overall);
    printf("Probability of alien invasion via ships: %d %%\n", invasion_alien_ship);
    printf("Probability of alien invasion via strongholds: %d %%\n", invasion_alien_stronghold);
    
    return 0;
}