//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_planets = 7;
    char planet_names[7][20] = {"Alderaan", "Tatooine", "Dagobah", "Hoth", "Endor", "Coruscant", "Naboo"};

    printf("Welcome to Procedural Space Adventure!\n");

    // generate random seed
    srand(time(NULL));

    // select a planet to visit
    int random_planet_index = rand() % num_planets;
    char chosen_planet[20];
    strcpy(chosen_planet, planet_names[random_planet_index]);

    printf("Your spaceship has landed on planet %s\n", chosen_planet);

    // search for alien life
    int has_alien_life = rand() % 2;
    if (has_alien_life) {
        printf("You have encountered alien life on planet %s!\n", chosen_planet);
    } else {
        printf("No alien life has been detected on planet %s.\n", chosen_planet);
    }

    // navigate through the asteroid field
    int asteroid_field_density = rand() % 100;
    if (asteroid_field_density < 30) {
        printf("The asteroid field around planet %s is light.\n", chosen_planet);
    } else if (asteroid_field_density < 70) {
        printf("The asteroid field around planet %s is moderate.\n", chosen_planet);
    } else {
        printf("The asteroid field around planet %s is heavy!\n", chosen_planet);
    }

    // gather resources
    int resource_quantity = rand() % 1000;
    printf("You have collected %d units of resources from planet %s.\n", resource_quantity, chosen_planet);

    // leave the planet
    printf("Your spaceship is now leaving planet %s.\n", chosen_planet);
    printf("Thank you for visiting Procedural Space Adventure!\n");

    return 0;
}