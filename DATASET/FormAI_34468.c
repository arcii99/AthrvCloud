//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Simulating the solar system
// Disclaimer: planets may not be to scale

typedef struct {
    char name[10];
    float distanceFromSun;
    float diameter;
    float orbitalPeriod;
} Planet;

void printPlanet(Planet planet) {
    printf("Name: %s\n", planet.name);
    printf("Distance from Sun: %.2f million km\n", planet.distanceFromSun);
    printf("Diameter: %.2f thousand km\n", planet.diameter);
    printf("Orbital period: %.2f Earth years\n", planet.orbitalPeriod);
}

int main() {
    srand(time(NULL)); // seed for random number generation

    Planet mercury = {"Mercury", 57.91, 4.88, 0.24};
    Planet venus = {"Venus", 108.2, 12.1, 0.62};
    Planet earth = {"Earth", 149.6, 12.7, 1};
    Planet mars = {"Mars", 227.9, 6.79, 1.88};
    Planet jupiter = {"Jupiter", 778.5, 142.9, 11.86};
    Planet saturn = {"Saturn", 1433.5, 120.5, 29.46};
    Planet uranus = {"Uranus", 2872.5, 51.1, 84.01};
    Planet neptune = {"Neptune", 4495.1, 49.5, 164.79};
    Planet pluto = {"Pluto", 5906.4, 2.37, 248.09};

    Planet planets[9] = {mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};

    printf("Welcome to the hilarious solar system simulation!\n");
    printf("Please fasten your seatbelts as we take off on an epic journey through the cosmos!\n\n");

    int numOfPlanets = sizeof(planets) / sizeof(Planet);
    for (int i = 0; i < numOfPlanets; i++) {
        printf("*****************************************\n");
        printf("We are now approaching planet %s...\n", planets[i].name);
        printf("*****************************************\n\n");
        printPlanet(planets[i]);

        int randomPerc = rand() % 101;
        if (randomPerc > 75) {
            printf("\nWatch out! A huge meteor shower is incoming!\n");
            printf("Brace for impact!!\n");
        } else if (randomPerc > 50) {
            printf("\nUh oh, the onboard AI just malfunctioned!\n");
            printf("We might spiral out of control, this could be the end...\n");
        } else if (randomPerc > 25) {
            printf("\nNo way, we just encountered intelligent alien life!\n");
            printf("They're signaling us to follow them, let's go check it out!\n");
        } else {
            printf("\nWow, what a peaceful place...\n");
            printf("I could easily spend my retirement here, don't you think?\n");
        }
        printf("\n\n");

    }

    printf("Thank you for flying with us today, and we hope you enjoyed our hilariously random simulation of the solar system!\n");
    return 0;
}