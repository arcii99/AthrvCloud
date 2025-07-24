//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Declare the variables to hold the probability values
    double spaceship_prob = 0.0;
    double laser_prob = 0.0;
    double mind_control_prob = 0.0;
    double invasion_prob = 0.0;
    
    // Generate a random number between 0 and 100 for the probability of alien spaceships
    spaceship_prob = rand() % 101;
    printf("Probability of Alien Spaceships: %lf%%\n", spaceship_prob);
    
    // Generate a random number between 0 and 100 for the probability of alien lasers
    laser_prob = rand() % 101;
    printf("Probability of Alien Lasers: %lf%%\n", laser_prob);
    
    // Generate a random number between 0 and 100 for the probability of alien mind control
    mind_control_prob = rand() % 101;
    printf("Probability of Alien Mind Control: %lf%%\n", mind_control_prob);
    
    // Calculate the overall probability of alien invasion based on the probabilities of spaceships, lasers, and mind control
    invasion_prob = (spaceship_prob * laser_prob * mind_control_prob) / 1000.0;
    printf("Probability of Alien Invasion: %lf%%\n", invasion_prob);
    
    return 0;
}