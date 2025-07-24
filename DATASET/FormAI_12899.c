//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasion_probability = 0;
    
    srand(time(NULL));
    
    // Determine the invasion probability
    for (int i = 0; i < 10; i++) {
        int alien_ships = (rand() % 100) + 1; // Generate random number between 1 to 100
        
        // If number is between 1 to 25, assign invasion_probability as high
        if (alien_ships >= 1 && alien_ships <= 25) {
            invasion_probability = invasion_probability + 30;
        }
        
        // If number is between 26 to 75, assign invasion_probability as medium
        else if (alien_ships >= 26 && alien_ships <= 75) {
            invasion_probability = invasion_probability + 20;
        }
        
        // If number is between 76 to 100, assign invasion_probability as low
        else if (alien_ships >= 76 && alien_ships <= 100) {
            invasion_probability = invasion_probability + 10;
        }
    }
    
    printf("Alien invasion probability: %d%%\n", invasion_probability);
    
    return 0;
}