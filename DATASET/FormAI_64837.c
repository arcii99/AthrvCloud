//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLANETS 10

typedef struct {
    char name[30];
    bool has_life;
    int distance;
} Planet;

Planet planets[MAX_PLANETS];

int num_planets = 0;

void addPlanet(char name[], bool has_life, int distance) {
    if (num_planets < MAX_PLANETS) {
        strcpy(planets[num_planets].name, name);
        planets[num_planets].has_life = has_life;
        planets[num_planets].distance = distance;
        num_planets++;
    }
}

void createPlanets() {
    addPlanet("Mercury", false, 36); 
    addPlanet("Venus", false, 67);
    addPlanet("Earth", true, 93); 
    addPlanet("Mars", false, 141); 
    addPlanet("Jupiter", false, 483);
    addPlanet("Saturn", false, 886);
    addPlanet("Uranus", false, 1782);
    addPlanet("Neptune", false, 2793);
    addPlanet("Pluto", false, 3670);
    addPlanet("Alpha Centauri", true, 4.37); 
}

void launchSpaceship() {
    srand(time(0)); //random seed
    int random_planet = rand() % num_planets; //pick a random planet
    printf("Initiating takeoff sequence...\n");
    printf("Destination planet: %s\n", planets[random_planet].name);
    printf("Travel distance: %d AU\n", planets[random_planet].distance);
    printf("Preparing for hyperspace jump...\n");
    printf("In hyperspace...\n");
    if (planets[random_planet].has_life) {
        printf("Welcome to %s! The planet is teeming with life.\n", planets[random_planet].name);
    } else {
        printf("Arrived at %s. Unfortunately, there is no evidence of life on the planet.\n", planets[random_planet].name);
    }
}

int main() {
    createPlanets();
    launchSpaceship();
    return 0;
}