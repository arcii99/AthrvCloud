//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between given range
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate the probability of alien invasion
double calculate_invasion_probability(int num_of_aliens, int planet_defense_level) {
    double invasion_probability;
    if (num_of_aliens <= 0) {
        printf("Invalid number of alien invaders!\n");
        return -1.0;
    }
    if (planet_defense_level <= 0) {
        printf("Invalid planet defense level!\n");
        return -1.0;
    }
    invasion_probability = ((double)planet_defense_level / num_of_aliens) * 100.0;
    return invasion_probability;
}

// Main function
int main() {
    int num_of_aliens, planet_defense_level, min_range, max_range;
    double invasion_probability;
    srand(time(NULL));  // Seed for random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Please enter the minimum and maximum range for number of alien invaders: ");
    scanf("%d %d", &min_range, &max_range);

    num_of_aliens = generate_random_number(min_range, max_range);
    printf("Number of alien invaders: %d\n", num_of_aliens);

    printf("Please enter the planet defense level (1-10): ");
    scanf("%d", &planet_defense_level);

    invasion_probability = calculate_invasion_probability(num_of_aliens, planet_defense_level);
    if (invasion_probability != -1.0) {
        printf("The probability of alien invasion is %.2f%%\n", invasion_probability);
    }

    return 0;
}