//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alien_ships, alien_weapons, alien_attackers, total_attacks = 0;

    // Seed the random number generator
    srand(time(0));

    // Generate random numbers for the alien invasion scenario
    alien_ships = rand() % 100 + 1;
    alien_weapons = rand() % 10 + 1;
    alien_attackers = rand() % 1000 + 1;

    // Calculate the probability of an alien invasion
    float alien_invasion_prob = ((float)alien_ships / 100) * ((float)alien_weapons / 10) * ((float)alien_attackers / 1000);

    // Print out the results
    printf("Alien Invasion Probability Calculator\n");
    printf("-------------------------------------\n");
    printf("Number of Alien Ships: %d\n", alien_ships);
    printf("Alien Weapon Strength: %d\n", alien_weapons);
    printf("Number of Alien Attackers: %d\n", alien_attackers);
    printf("\n");
    printf("Based on the above factors, the probability of an alien invasion is: %.2f%%\n", alien_invasion_prob * 100);
    printf("\n");

    // Calculate the total number of attacks by the aliens
    for (int i = 0; i < alien_attackers; i++)
    {
        total_attacks += rand() % 10 + 1;
    }

    // Print out the total number of attacks by the aliens
    printf("Total number of attacks by the aliens: %d\n", total_attacks);

    return 0;
}