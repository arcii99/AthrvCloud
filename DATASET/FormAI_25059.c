//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Alien invasion probability calculator
int main() {
    int health = 100; // starting health
    int days = 0; // days passed
    float probability = 0.0; // probability of an alien invasion
    float damage = 0.0; // damage from an alien invasion
    
    srand(time(NULL)); // seed random number generator
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Your current health is %d.\n", health);
    printf("You have survived %d days.\n", days);
    
    while (health > 0) { // while still alive
        probability = ((float)rand() / RAND_MAX); // determine probability of invasion
        
        printf("\n");
        printf("Day %d...\n", days);
        printf("Alien invasion probability: %f.\n", probability);
        
        if (probability > 0.5) { // if invasion occurs
            damage = ((float)rand() / RAND_MAX) * 50.0; // determine damage
            
            printf("Oh no! An alien invasion!\n");
            printf("Damage taken: %f.\n", damage);
            
            health -= damage; // subtract damage from health
            
            if (health <= 0) { // if health is depleted
                printf("Your health has been depleted.\n");
                printf("Game over.\n");
                break; // end game
            }
        } else { // if no invasion occurs
            printf("Phew! No invasion today.\n");
        }
        
        days++; // increment days
        printf("Your current health is %d.\n", health);
        printf("You have survived %d days.\n", days);
    }
    
    return 0;
}