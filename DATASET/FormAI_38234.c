//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

int main() {
    // Variables
    int num_simulations = 100000;
    double alien_arrival_time_mean = 30.0; // days
    double alien_arrival_time_sd = 10.0; // days
    double num_aliens_mean = 100.0;
    double num_aliens_sd = 30.0;
    int days_since_last_sighting = 0;
    int total_num_aliens = 0;
    int num_invasions = 0;

    // Seed RNG
    srand(42);

    // Simulation Loop
    for (int i = 0; i < num_simulations; i++) {
        // Generate Random Arrival Time for Aliens
        double alien_arrival_time = rand_double(alien_arrival_time_mean - 2 * alien_arrival_time_sd,
                                                 alien_arrival_time_mean + 2 * alien_arrival_time_sd);

        // Check if Aliens Arrive during the 100 Day Simulation Period
        if (alien_arrival_time < 100.0) {
            // Generate Random Number of Aliens
            int num_aliens = (int) round(rand_double(num_aliens_mean - 2 * num_aliens_sd,
                                                     num_aliens_mean + 2 * num_aliens_sd));

            // Add Aliens to Total Number of Aliens
            total_num_aliens += num_aliens;

            // Check if Aliens Arrive during an Ongoing Invasion
            if (days_since_last_sighting <= 7) {
                // Add Aliens to Current Invasion
                num_invasions++;
            }
            else {
                // Start a New Invasion
                days_since_last_sighting = 0;
                num_invasions++;
            }

            // Increase Days Since Last Sighting
            days_since_last_sighting++;

            // Check if Aliens Have Invaded Earth
            if (total_num_aliens >= 10000) {
                printf("Earth has been invaded by aliens after %d simulations!\n", i + 1);
                return 0;
            }
        }
    }

    printf("Aliens did not invade Earth after %d simulations.\n", num_simulations);
    printf("Average Number of Aliens per Invasion: %f\n", (double) total_num_aliens / num_invasions);

    return 0;
}