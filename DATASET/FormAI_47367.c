//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
// C Alien Invasion Probability Calculator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_attacks, num_of_days, alien_ability, invasion_prob;
    srand(time(NULL)); // set the random seed
    printf("=== Alien Invasion Probability Calculator ===\n");
    printf("Enter the number of potential alien attacks: ");
    scanf("%d", &num_of_attacks);
    printf("Enter the number of days to calculate probability over: ");
    scanf("%d", &num_of_days);
    printf("Enter the ability level of the alien species (0-100): ");
    scanf("%d", &alien_ability);
    printf("Calculating probability...\n\n");

    // Probability calculation
    int successful_attacks = 0;
    for (int i = 0; i < num_of_attacks; i++) {
        for (int j = 0; j < num_of_days; j++) {
            int prob = rand() % 100 + 1; // generate a random number between 1-100
            if (prob <= alien_ability) {
                successful_attacks++;
                break;
            }
        }
    }
    invasion_prob = (double) successful_attacks / num_of_attacks * 100;
    printf("The probability of alien invasion is %d%%.\n", invasion_prob);
    if (invasion_prob > 50) {
        printf("We recommend taking extra precautions and preparing for an alien invasion.\n");
    } else {
        printf("The probability of an alien invasion is low, but it is always better to be prepared.\n");
    }
    return 0;
}