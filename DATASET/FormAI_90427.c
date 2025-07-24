//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the game
#define MAX_PLANETS 10
#define MAX_RESOURCE 100
#define SUCCESS 1
#define FAILURE 0

// Define the planet structure
typedef struct planet {
    char name[20];
    int resource;
    int distance;
} Planet;

// Function to get random integer between min and max (inclusive)
int getRandomInt(int min, int max) {
    if (max < min) {
        int tmp = max;
        max = min;
        min = tmp;
    }
    return min + rand() % (max - min + 1);
}

// Function to generate a random planet
Planet getRandomPlanet(int distanceMin, int distanceMax, int resourceMin, int resourceMax) {
    Planet p;
    char names[MAX_PLANETS][20] = {"Alderaan", "Bespin", "Coruscant", "Dagobah", "Endor", "Hoth", "Naboo", "Tatooine", "Yavin", "Zebes"};
    strcpy(p.name, names[rand() % MAX_PLANETS]);
    p.distance = getRandomInt(distanceMin, distanceMax);
    p.resource = getRandomInt(resourceMin, resourceMax);
    return p;
}

// Function to print the details of a planet
void printPlanet(Planet p) {
    printf("%s [Distance: %d Light Years, Resource: %d]\n", p.name, p.distance, p.resource);
}

// Function to play the game
void playGame(int maxDist, int maxRes, int minDist, int minRes) {
    Planet planets[MAX_PLANETS];
    int i;
    for (i = 0; i < MAX_PLANETS; i++) {
        planets[i] = getRandomPlanet(minDist, maxDist, minRes, maxRes);
    }
    printf("Available Planets:\n");
    for (i = 0; i < MAX_PLANETS; i++) {
        printf("%d. ", i+1);
        printPlanet(planets[i]);
    }
    int shipResource = 50;
    int shipDistance = 0;
    int currentPlanet = 1;
    while (shipResource > 0 && shipDistance < planets[MAX_PLANETS-1].distance) {
        printf("\nCurrent Location:\n");
        printPlanet(planets[currentPlanet-1]);
        printf("Ship Status:\nResource: %d\nDistance Travelled: %d Light Years\n", shipResource, shipDistance);
        printf("Enter the number of the planet you want to travel to (or 0 to stay on current planet): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Staying on current planet...\n");
        }
        else if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice. Please choose again.\n");
        }
        else {
            int newDistance = shipDistance + planets[choice-1].distance - planets[currentPlanet-1].distance;
            if (newDistance > maxDist) {
                printf("Ship cannot travel that far at once. Please choose again.\n");
            }
            else {
                int resourceChange = getRandomInt(-10, 20);
                if (shipResource + resourceChange > maxRes) {
                    shipResource = maxRes;
                }
                else if (shipResource + resourceChange < 0) {
                    shipResource = 0;
                }
                else {
                    shipResource += resourceChange;
                }
                shipDistance = newDistance;
                currentPlanet = choice;
                printf("Travelling to %s...\n", planets[currentPlanet-1].name);
            }
        }
    }

    if (shipResource <= 0) {
        printf("\nShip has run out of resources. Game over.\n");
    }
    else {
        printf("\nCongratulations, you have completed the game!\n");
    }
}

int main() {
    srand(time(NULL));
    playGame(200, MAX_RESOURCE, 30, 10);
    return 0;
}