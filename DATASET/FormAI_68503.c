//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_SIMULATIONS 10000

void simulate_invasion(int invasion_probability, int *successful_invasions, int *total_simulations);

int main(void) {
    int invasion_probability;
    int successful_invasions = 0;
    int total_simulations = 0;

    srand(time(NULL));

    printf("Enter the probability of an alien invasion (0-100): ");
    scanf("%d", &invasion_probability);

    simulate_invasion(invasion_probability, &successful_invasions, &total_simulations);

    printf("After %d simulations, the probability of a successful alien invasion is %.2f%%\n", 
            total_simulations, (float) successful_invasions / total_simulations * 100);

    return 0;
}

void simulate_invasion(int invasion_probability, int *successful_invasions, int *total_simulations) {
    for (int i = 0; i < NUMBER_OF_SIMULATIONS; i++) {
        int random_number = rand() % 101;

        if (random_number <= invasion_probability) {
            (*total_simulations)++;

            int alien_strength = rand() % 101;
            int human_defense = rand() % 101;

            if (alien_strength > human_defense) {
                (*successful_invasions)++;
            }
        }
    }
}