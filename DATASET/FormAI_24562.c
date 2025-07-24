//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the seed for random numbers
    srand(time(NULL));

    // Define variables for the probability calculation
    double alien_prob = 0.0;
    int days_until_invasion = 0;
    double percentage = 0.0;

    // Generate random numbers for input variables
    int tech_level = rand() % 11; // Tech level from 0-10
    int military_strength = rand() % 101; // Military strength from 0-100
    int alien_aggression = rand() % 101; // Alien aggression from 0-100

    // Calculate the base alien probability based on tech level and military strength
    alien_prob = (double)(tech_level + military_strength) / 20.0;

    // Adjust the alien probability based on alien aggression
    if (alien_aggression >= 25 && alien_aggression <= 75) {
        alien_prob *= 1.5;
    } else if (alien_aggression > 75) {
        alien_prob *= 2.0;
    }

    // Calculate the number of days until invasion based on alien probability
    if (alien_prob >= 0.75) {
        days_until_invasion = rand() % 6 + 1; // Invasion within 1-6 days
    } else if (alien_prob >= 0.50) {
        days_until_invasion = rand() % 11 + 7; // Invasion within 7-17 days
    } else {
        days_until_invasion = rand() % 16 + 18; // Invasion within 18-33 days
    }

    // Calculate the percentage chance of invasion
    percentage = alien_prob * 100.0;

    // Display the results to the user
    printf("Welcome to the Alien Invasion Probability Calculator v1.0\n");
    printf("-------------------------------------------------------\n");
    printf("Based on your input:\n");
    printf("Tech Level: %d\n", tech_level);
    printf("Military Strength: %d\n", military_strength);
    printf("Alien Aggression: %d\n", alien_aggression);
    printf("\nThe probability of an alien invasion is: %.2f%%\n", percentage);
    printf("The invasion is estimated to occur in %d days.\n", days_until_invasion);

    return 0;
}