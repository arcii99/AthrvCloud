//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of alien invasion based on player input
float calculate_probability(int players, int aliens, int planets) {
    float probability = 1.0;
    probability *= (float)(aliens * 5) / (float)planets; // Higher number of aliens and fewer planets increase probability
    probability *= (float)players / (float)(planets * 2); // More players and fewer planets decrease probability
    probability *= (float)rand() / (float)RAND_MAX; // Random factor
    return probability;
}

int main() {
    srand(time(NULL));
    int players, aliens, planets;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of players: ");
    scanf("%d", &players);
    printf("Please enter the number of aliens: ");
    scanf("%d", &aliens);
    printf("Please enter the number of planets: ");
    scanf("%d", &planets);

    float probability = calculate_probability(players, aliens, planets);

    printf("\nThe probability of an alien invasion is %.2f%%\n", probability * 100);

    return 0;
}