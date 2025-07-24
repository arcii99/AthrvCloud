//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int aliens_per_ship = 10; // Average number of aliens per ship
    int num_ships = rand() % 1000 + 1; // Random number of ships between 1 and 1000
    int total_aliens = aliens_per_ship * num_ships; // Calculate total number of aliens
    
    int invasion_probability = (total_aliens * 100) / (5000000); // Calculate invasion probability out of 100
    
    printf("Based on our calculations, there is a %d%% chance of an alien invasion.", invasion_probability);
    
    return 0;
}