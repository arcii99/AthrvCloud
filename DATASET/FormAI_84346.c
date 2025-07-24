//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets;
    float invasion_probability;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // Ask user for number of planets to calculate
    printf("How many planets would you like to calculate for? ");
    scanf("%d", &num_planets);

    printf("\nCalculating invasion probabilities for %d planets...\n\n", num_planets);

    for (int i = 1; i <= num_planets; i++) {
        // Generate a random invasion probability between 0 and 1
        invasion_probability = (float)rand() / (float)RAND_MAX;

        // Print the invasion probability along with the planet number
        printf("Planet #%d:\tInvasion Probability: %.2f%%\n", i, invasion_probability*100);
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator! Good luck defending the galaxy!\n");

    return 0;
}