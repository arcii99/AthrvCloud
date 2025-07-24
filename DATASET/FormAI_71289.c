//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed for random number generator
    int alien_population, invader_ships, invasion_probability;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the alien population of the planet: ");
    scanf("%d", &alien_population);

    // Calculate the number of invader ships based on population
    if (alien_population < 5000) invader_ships = 1;
    else if (alien_population < 10000) invader_ships = 2;
    else if (alien_population < 50000) invader_ships = 3;
    else if (alien_population < 100000) invader_ships = 5;
    else invader_ships = 10;
    printf("Based on the alien population of %d, there will be %d invader ships.\n", alien_population, invader_ships);

    // Calculate the invasion probability
    invasion_probability = rand() % 100 + 1; // Random number between 1 and 100
    for (int i = 0; i < invader_ships; i++) {
        int success_chance = rand() % 100 + 1; // Random chance of a ship making it through
        if (success_chance <= 40) {
            invasion_probability += 20; // Chance of invasion increases by 20%
            printf("Invader ship %d has successfully made it through planetary defenses.\n", i+1);
        } else {
            printf("Invader ship %d was destroyed by planetary defenses.\n", i+1);
        }
    }

    // Output the invasion probability
    printf("After simulating %d invader ships, the invasion probability is %d%%.\n", invader_ships, invasion_probability);

    return 0;
}