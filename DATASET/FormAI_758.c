//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fuel = 100; // Initializing fuel to 100 units
int oxygen = 100; // Initializing oxygen to 100 units

void explorePlanet(void* planet) {
    printf("Exploring planet %s... \n", (char*)planet);
    int foundResources = rand() % 2;

    if (foundResources) {
        printf("Found valuable resources on planet %s! \n", (char*)planet);
    } else {
        printf("No resources found on planet %s. \n", (char*)planet);
    }
}

void* scanPlanet() {
    int number = rand() % 5;
    char* planet;

    switch (number) {
        case 0:
            planet = "Mars";
            break;
        case 1:
            planet = "Jupiter";
            break;
        case 2:
            planet = "Saturn";
            break;
        case 3:
            planet = "Uranus";
            break;
        case 4:
            planet = "Neptune";
            break;
        default:
            planet = "Unidentified Planet";
            break;
    }

    printf("Scanning planet %s... \n", planet);
    return planet;
}

void* refuel() {
    printf("Refueling spacecraft... \n");
    fuel = 100;
    return NULL;
}

void* replenishOxygen() {
    printf("Replenishing oxygen in spacecraft... \n");
    oxygen = 100;
    return NULL;
}

int main() {
    srand(time(NULL)); // Setting seed for random number generation

    printf("Welcome to the Procedural Space Adventure! \n");

    while (fuel > 0 && oxygen > 0) {
        void* planet = scanPlanet();

        int action = rand() % 3;

        switch (action) {
            case 0:
                explorePlanet(planet);
                break;
            case 1:
                refuel();
                break;
            case 2:
                replenishOxygen();
                break;
        }

        fuel -= 10;
        oxygen -= 10;

        printf("Current fuel level: %d units \n", fuel);
        printf("Current oxygen level: %d units \n", oxygen);
        printf("\n");
    }

    if (fuel <= 0 && oxygen <= 0) {
        printf("Mission failed, spacecraft ran out of fuel and oxygen. \n");
    } else if (fuel <= 0) {
        printf("Mission failed, spacecraft ran out of fuel. \n");
    } else {
        printf("Mission failed, spacecraft ran out of oxygen. \n");
    }

    return 0;
}