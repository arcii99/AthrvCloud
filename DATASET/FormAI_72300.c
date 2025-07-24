//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_PLANET_LENGTH 20
#define MAX_GALAXY_LENGTH 20

// Structure to hold information about a planet
struct Planet {
    char name[MAX_PLANET_LENGTH];
    float distanceFromSun;
    int numOfMoons;
};

// Structure to hold information about a spaceship
struct Spaceship {
    char name[MAX_NAME_LENGTH];
    int fuelLevel;
    struct Planet location;
};

// Structure to hold information about a galaxy
struct Galaxy {
    char name[MAX_GALAXY_LENGTH];
    struct Planet planets[10];
    int numOfPlanets;
};

// Function to initialize a planet
void initializePlanet(struct Planet *planet, char name[], float distance, int moons) {
    strcpy(planet->name, name);
    planet->distanceFromSun = distance;
    planet->numOfMoons = moons;
}

// Function to initialize a spaceship
void initializeSpaceship(struct Spaceship *spaceship, char name[], int fuel, struct Planet location) {
    strcpy(spaceship->name, name);
    spaceship->fuelLevel = fuel;
    spaceship->location = location;
}

// Function to initialize a galaxy
void initializeGalaxy(struct Galaxy *galaxy, char name[]) {
    strcpy(galaxy->name, name);
    galaxy->numOfPlanets = 0;
}

// Function to add a planet to a galaxy
void addPlanet(struct Galaxy *galaxy, struct Planet planet) {
    if (galaxy->numOfPlanets < 10) {
        galaxy->planets[galaxy->numOfPlanets] = planet;
        galaxy->numOfPlanets++;
    } else {
        printf("This galaxy already has the maximum number of planets!");
    }
}

// Function to display the planets in a galaxy
void displayGalaxy(struct Galaxy galaxy) {
    printf("Galaxy: %s\n", galaxy.name);
    printf("Number of planets: %d\n", galaxy.numOfPlanets);
    printf("Planets:\n");
    for (int i = 0; i < galaxy.numOfPlanets; i++) {
        printf("%s - Distance from sun: %.1f - Number of moons: %d\n",
               galaxy.planets[i].name, galaxy.planets[i].distanceFromSun, galaxy.planets[i].numOfMoons);
    }
}

// Function to display the spaceship location
void displayLocation(struct Spaceship spaceship) {
    printf("%s is currently located on %s.\n", spaceship.name, spaceship.location.name);
}

// Function to travel to a planet
void travel(struct Spaceship *spaceship, struct Planet planet) {
    spaceship->location = planet;
    spaceship->fuelLevel -= (int) (planet.distanceFromSun / 10.0);
    if (spaceship->fuelLevel < 0) {
        spaceship->fuelLevel = 0;
        printf("%s has run out of fuel and is now stranded on %s!\n", spaceship->name, spaceship->location.name);
    } else {
        printf("%s has successfully traveled to %s!\n", spaceship->name, planet.name);
    }
}

int main() {
    struct Planet earth, mars, jupiter;
    initializePlanet(&earth, "Earth", 93.0, 1);
    initializePlanet(&mars, "Mars", 142.0, 2);
    initializePlanet(&jupiter, "Jupiter", 484.0, 79);

    struct Spaceship enterprise;
    initializeSpaceship(&enterprise, "USS Enterprise", 100, earth);

    struct Galaxy theMilkyWay;
    initializeGalaxy(&theMilkyWay, "The Milky Way");

    addPlanet(&theMilkyWay, earth);
    addPlanet(&theMilkyWay, mars);
    addPlanet(&theMilkyWay, jupiter);

    displayGalaxy(theMilkyWay);
    displayLocation(enterprise);

    travel(&enterprise, mars);
    displayLocation(enterprise);

    travel(&enterprise, jupiter);
    displayLocation(enterprise);

    travel(&enterprise, earth);
    displayLocation(enterprise);

    return 0;
}