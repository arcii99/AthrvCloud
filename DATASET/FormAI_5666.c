//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME 20
#define MAX_ENERGY 100
#define SHIP_ENERGY 50
#define PLANET_ENERGY 20
#define MAX_TRAVEL_DISTANCE 3

typedef struct Planet {
    char name[MAX_NAME];
    int energy;
} Planet;

void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("In this game, you will travel through space in search of planets to collect energy from.\n");
}

void generatePlanets(Planet planets[], int numPlanets) {
    char names[MAX_PLANETS][MAX_NAME] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta", "Iota", "Kappa"}; // pre-defined planet names
    int i, energyRnd;
    srand(time(0)); // seed random number generator

    for (i = 0; i < numPlanets; i++) {
        strcpy(planets[i].name, names[i]); // copy planet name from pre-defined list
        energyRnd = rand() % MAX_ENERGY; // generate random energy value for planet
        planets[i].energy = energyRnd;
    }
}

void printPlanets(Planet planets[], int numPlanets) {
    int i;
    printf("Available planets:\n");
    for (i = 0; i < numPlanets; i++) {
        printf("%s (Energy: %d)\n", planets[i].name, planets[i].energy);
    }
}

int travel(Planet currentPlanet, Planet planets[], int numPlanets) {
    int i, distance, travelDistanceRnd;
    while(1) {
        travelDistanceRnd = rand() % MAX_TRAVEL_DISTANCE + 1;
        distance = currentPlanet.energy + SHIP_ENERGY - PLANET_ENERGY * travelDistanceRnd; // calculate distance from current planet to random planet within max range
        if(distance >= 0) { // if distance is positive, travel to planet
            for(i = 0; i < numPlanets; i++) {
                if(planets[i].energy > 0 && strcmp(planets[i].name, currentPlanet.name) != 0) { // find first planet with energy that is not the current planet
                    currentPlanet.energy -= travelDistanceRnd * PLANET_ENERGY; // deduct energy from current planet for travel distance
                    planets[i].energy -= SHIP_ENERGY; // deduct energy from random planet for ship travel
                    printf("Traveled to %s, collected %d energy\n", planets[i].name, planets[i].energy);
                    return i; // return index of planet traveled to
                }
            }
        }
    }
}

void playGame() {
    Planet planets[MAX_PLANETS];
    generatePlanets(planets, MAX_PLANETS);
    printPlanets(planets, MAX_PLANETS);

    int planetIndex = rand() % MAX_PLANETS; // randomly select a starting planet
    Planet currentPlanet = planets[planetIndex];
    printf("Starting on planet %s\n", currentPlanet.name);

    while(1) {
        printf("Current energy: %d\n", currentPlanet.energy);
        if(currentPlanet.energy == 0) {
            printf("You ran out of energy! Game over.\n");
            break;
        }
        int targetPlanetIndex = travel(currentPlanet, planets, MAX_PLANETS);
        currentPlanet = planets[targetPlanetIndex];
    }
}

int main() {
    printIntro();
    playGame();
    return 0;
}