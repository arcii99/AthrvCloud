//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Set random seed based on current time

    int num_iterations = 1000;  // Number of simulations to run
    int num_invaders = 1000;  // Number of alien invaders in each simulation
    int num_successful = 0;  // Number of successful invasions
    float probability = 0.0;  // Probability of a successful invasion

    for (int i = 0; i < num_iterations; i++) {
        int invasion_strength = rand() % 100 + 1;  // Random invasion strength between 1-100
        int defensive_strength = rand() % 100 + 1;  // Random defensive strength between 1-100
        int invasion_strength_remaining = invasion_strength;  // Initialize remaining invasion strength

        while (invasion_strength_remaining > 0 && num_invaders > 0) {
            int attack_power = rand() % 50 + 1;  // Random attack power between 1-50
            int defense_power = rand() % 50 + 1;  // Random defense power between 1-50
            int damage = attack_power - defense_power;  // Calculate damage

            if (damage > 0) {  // If damage is greater than zero
                num_invaders--;  // Subtract one from number of invaders
                invasion_strength_remaining -= damage;  // Subtract damage from invasion strength
            }
        }

        if (num_invaders == 0) {  // If all invaders were eliminated
            num_successful++;  // Increment number of successful invasions
        }

        num_invaders = 1000;  // Reset number of invaders for next simulation
    }

    probability = (float) num_successful / num_iterations * 100;  // Calculate success probability

    printf("The probability of a successful alien invasion is %.2f%%.\n", probability);

    return 0;
}