//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n **** Alien Invasion Probability Calculator ****\n\n");

    // Seed RNG for unique probability every run
    srand(time(NULL));

    // Get user input
    int num_ships;
    printf("Enter the number of alien ships in the invasion: ");
    scanf("%d", &num_ships);

    // Calculate probability of successful defense
    float defense_prob = 1;
    for (int i = num_ships; i > 0; i--)
    {
        defense_prob *= (float) i / 10;
    }
    defense_prob *= 100;

    // Calculate probability of individual ship destruction
    float ship_destruction_prob = ((float) (rand() % 21) + 70) / 100;

    // Calculate expected number of destroyed ships
    float expected_destruction = num_ships * ship_destruction_prob;

    // Calculate probability of complete destruction
    float complete_destruction_prob = 1;
    for (int i = num_ships; i > 0; i--)
    {
        complete_destruction_prob *= (float) (i * ship_destruction_prob) / 100;
    }
    complete_destruction_prob *= 100;

    // Print results
    printf("\n-- Results --\n\n");
    printf("Probability of successful defense: %.2f%%\n", defense_prob);
    printf("Probability of individual ship destruction: %.2f%%\n", ship_destruction_prob * 100);
    printf("Expected number of destroyed ships: %.2f\n", expected_destruction);
    printf("Probability of complete destruction: %.2f%%\n\n", complete_destruction_prob);
    
    return 0;
}