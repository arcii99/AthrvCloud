//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the limitations of the game world
#define MAX_GALAXIES 10
#define MAX_STARS 100
#define MAX_PLANETS 4

// Define structures for the game objects
typedef struct Planet {
    char name[20];
    int resources;
    int population;
    int tech_level;
} Planet;

typedef struct Star {
    char name[20];
    Planet planets[MAX_PLANETS];
    int num_planets;
    int visited;
} Star;

typedef struct Galaxy {
    char name[25];
    Star stars[MAX_STARS];
    int num_stars;
} Galaxy;

// Define functions for generating the game world
void generate_galaxy(Galaxy* galaxy);

int main() {
    srand(time(NULL)); // Seed the random number generator
    Galaxy galaxy[MAX_GALAXIES];
    int i, j, k;
    
    // Generate the game world
    for (i = 0; i < MAX_GALAXIES; i++) {
        generate_galaxy(&galaxy[i]);
    }

    // Output the generated galaxy data
    for (i = 0; i < MAX_GALAXIES; i++) {
        printf("Galaxy %d: %s\n", i+1, galaxy[i].name);
        for (j = 0; j < galaxy[i].num_stars; j++) {
            printf("\t%s - %d planets\n", galaxy[i].stars[j].name, galaxy[i].stars[j].num_planets);
            for (k = 0; k < galaxy[i].stars[j].num_planets; k++) {
                printf("\t\t%s\n", galaxy[i].stars[j].planets[k].name);
            }
        }
    }

    return 0;
}

// Function for generating a galaxy
void generate_galaxy(Galaxy* galaxy) {
    int i, j, k, num_stars;
    char* galaxy_names[MAX_GALAXIES] = {"Andromeda", "Milky Way", "Whirlpool", "Sombrero", "Pinwheel"};
    char* star_names[MAX_STARS] = {"Alpha Centauri", "Sol", "Vega", "Betelgeuse", "Canopus", "Sirius"};
    char* planet_names[MAX_PLANETS] = {"Terra", "Vulcan", "Mars", "Pandora"};
    
    // Randomly choose number of stars in galaxy
    num_stars = rand() % (MAX_STARS / 2) + (MAX_STARS / 2);
    
    // Generate Galaxy Name
    int randomInt = rand() % 5;
    strcpy(galaxy->name, galaxy_names[randomInt]);

    // Generate stars in galaxy
    galaxy->num_stars = num_stars;
    for (i = 0; i < num_stars; i++) {
        int randomStar = rand() % 6;
        strcpy(galaxy->stars[i].name, star_names[randomStar]);
        galaxy->stars[i].num_planets = rand() % MAX_PLANETS + 1;
        for (j = 0; j < galaxy->stars[i].num_planets; j++) {
            int randomPlanet = rand() % MAX_PLANETS;
            strcpy(galaxy->stars[i].planets[j].name, planet_names[randomPlanet]);
            galaxy->stars[i].planets[j].resources = rand() % 10000;
            galaxy->stars[i].planets[j].population = rand() % 100000;
            galaxy->stars[i].planets[j].tech_level = rand() % 4;
        }
    }
}