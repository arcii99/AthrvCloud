//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    printf("********** ALIEN INVASION PROBABILITY CALCULATOR **********\n");

    int countries = 0;
    printf("Enter the number of countries: ");
    scanf("%d", &countries);

    if (countries < 1) {
        printf("Invalid input! Please enter a number greater than 0.\n");
        return 0;
    }

    int total_population = 0;
    for (int i = 1; i <= countries; i++) {
        int population = 0;
        printf("Enter the population of country %d: ", i);
        scanf("%d", &population);
        total_population += population;
    }

    if (total_population < 1) {
        printf("Invalid input! Please enter valid populations for each country.\n");
        return 0;
    }

    int alien_ships = rand() % (total_population / 5000) + 1; // calculate number of alien ships
    printf("\nCalculating probability of alien invasion...\n\n");
    printf("Number of alien ships: %d\n", alien_ships);

    double invasion_probability = (double)alien_ships / countries * 100; // calculate invasion probability
    printf("Invasion probability: %.2f%%\n", invasion_probability);

    if (invasion_probability > 50) {
        printf("Oh no, the probability of an alien invasion is HIGH! We're doomed!\n");
    } else {
        printf("Phew, the probability of an alien invasion is LOW! We're safe... for now.\n");
    }

    return 0;
}