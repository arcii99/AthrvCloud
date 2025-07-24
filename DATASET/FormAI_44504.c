//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator\n");

    srand(time(NULL)); // Initialize random generator with current time

    int planets_explored = rand() % 1000 + 1; // Generate random number between 1 and 1000

    printf("Based on our data, there have been %d planets explored by humans.\n", planets_explored);

    int likelihood_of_encounter;
    if (planets_explored > 500) {
        likelihood_of_encounter = rand() % 40 + 1; // Generate random number between 1 and 40
    } else {
        likelihood_of_encounter = rand() % 10 + 1; // Generate random number between 1 and 10
    }

    printf("The likelihood of encountering aliens on a given planet is %d percent.\n", likelihood_of_encounter);

    int alien_aggressiveness = rand() % 10 + 1; // Generate random number between 1 and 10

    printf("Assuming aliens are encountered, their aggressiveness would be rated at %d out of 10.\n", alien_aggressiveness);

    int years_until_invasion = rand() % 200 + 1; // Generate random number between 1 and 200

    printf("Based on current trends, we estimate that it would take %d years until an alien invasion occurs.\n", years_until_invasion);

    float invasion_probability = ((float) likelihood_of_encounter / 100) * alien_aggressiveness * (1 - (years_until_invasion / 1000.0));

    printf("Using this data, we calculate that there is a %f percent probability of an alien invasion occurring.\n", invasion_probability);

    return 0;
}