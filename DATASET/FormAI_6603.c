//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    srand(time(NULL)); // Seeding random number generator

    int num_simulations;
    printf("Enter number of simulations to run: ");
    scanf("%d", &num_simulations);

    double total_aliens = 0;
    double total_simulations = num_simulations;

    for(int i = 1; i <= num_simulations; i++) {
        int num_planets = 1 + rand() % 10; // Random number of planets to check
        double aliens_per_planet = (double) 100 + rand() % 401; // Random number of aliens per planet
        printf("[Simulation %d]: Checking %d planets with an estimated %f aliens each.\n", i, num_planets, aliens_per_planet);

        double total_aliens_on_mission = num_planets * aliens_per_planet; // Total number of aliens on mission

        double invasion_probability = 1.0;
        int num_attempts = 0;
        while(invasion_probability > 0.01 && num_attempts < 10) { // Keep checking until probability drops below 1%
            double random_num = (double) rand() / RAND_MAX;
            invasion_probability *= random_num; // Success chance decreases with each attempt
            num_attempts += 1;
        }

        if(num_attempts == 10 && invasion_probability > 0.01) {
            printf("[Simulation %d]: No successful invasion attempts after %d tries. Mission failed.\n", i, num_attempts);
        } else {
            printf("[Simulation %d]: Successful invasion after %d tries! Probability of success: %f\n", i, num_attempts, 1.0 - invasion_probability);

            total_aliens += total_aliens_on_mission; // Update total aliens count
        }

        printf("\n");
    }

    double average_aliens = total_aliens / total_simulations; // Calculate average number of aliens encountered
    printf("After %d simulations, the estimated average number of aliens encountered is: %f\n", num_simulations, average_aliens);

    return 0;
}