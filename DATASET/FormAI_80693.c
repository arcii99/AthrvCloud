//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Seeding the random number generator

    int alien_ships, shot_frequency, city_population;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien ships: ");
    scanf("%d", &alien_ships);

    printf("Please enter the frequency of alien shots (in seconds): ");
    scanf("%d", &shot_frequency);

    printf("Please enter the population of the city (in millions): ");
    scanf("%d", &city_population);

    printf("\nCalculating probability...\n\n");

    int aliens_per_ship = rand() % 5000 + 1000; // Random number between 1000 and 6000 aliens per ship
    int total_aliens = alien_ships * aliens_per_ship;
    int avg_pop_decrease_per_shot = rand() % 10 + 1; // Random number between 1% and 10%
    int shots_to_destroy_city = (city_population * 1000000) / (avg_pop_decrease_per_shot * total_aliens * shot_frequency);

    double alien_invasion_probability = 1 - pow(1 - ((double) 1 / total_aliens), alien_ships * (city_population * 1000000));

    printf("There are an average of %d aliens per ship.\n", aliens_per_ship);
    printf("There are approximately %d aliens total.\n", total_aliens);
    printf("Each alien shot decreases the population by an average of %d%%.\n", avg_pop_decrease_per_shot);
    printf("It will take approximately %d shots to destroy the city.\n", shots_to_destroy_city);
    printf("The probability of an alien invasion is approximately %.2f%%.\n", alien_invasion_probability * 100);

    return 0;
}