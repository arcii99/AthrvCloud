//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5 // Maximum number of planets

struct Planet {
    char name[50];
    int distance;
    int resources;
};

struct Spaceship {
    char name[50];
    int fuel;
    int cargo;
};

void initializePlanets(struct Planet arr[]) {
    strcpy(arr[0].name, "Earth");
    arr[0].distance = 0;
    arr[0].resources = 100;

    strcpy(arr[1].name, "Mars");
    arr[1].distance = 50;
    arr[1].resources = 80;

    strcpy(arr[2].name, "Jupiter");
    arr[2].distance = 100;
    arr[2].resources = 60;

    strcpy(arr[3].name, "Saturn");
    arr[3].distance = 150;
    arr[3].resources = 40;

    strcpy(arr[4].name, "Neptune");
    arr[4].distance = 200;
    arr[4].resources = 20;
}

void displayPlanets(struct Planet arr[]) {
    printf("Planets in the Space Adventure game:\n");
    for(int i=0; i<MAX_PLANETS; i++) {
        printf("%d.\t%s\t(distance: %d, resources: %d)\n", i+1, arr[i].name, arr[i].distance, arr[i].resources);
    }
}

void printSpaceshipStatus(struct Spaceship ship) {
    printf("\nSpaceship status:\n");
    printf("Name: %s\n", ship.name);
    printf("Fuel: %d\n", ship.fuel);
    printf("Cargo: %d\n", ship.cargo);
}

int main() {
    srand(time(0));

    struct Planet planets[MAX_PLANETS];
    initializePlanets(planets);

    displayPlanets(planets);

    struct Spaceship spaceship;
    printf("\n=== Welcome to the Space Adventure game ===\n");
    printf("Enter a name for your spaceship: ");
    scanf("%[^\n]%*c", spaceship.name);

    spaceship.fuel = 100;
    spaceship.cargo = 0;

    while(1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Travel to a planet\n");
        printf("2. Load resources from current planet\n");
        printf("3. Quit the game\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            int planetChoice;
            printf("Enter the planet number you want to travel to: ");
            scanf("%d", &planetChoice);

            if(planetChoice < 1 || planetChoice > MAX_PLANETS) {
                printf("Invalid planet choice. Please try again.\n");
                continue;
            }

            int distance = planets[planetChoice-1].distance;
            if(distance > spaceship.fuel) {
                printf("Not enough fuel to reach the selected planet. Please load more fuel.\n");
                continue;
            }

            int resources = planets[planetChoice-1].resources;
            spaceship.fuel -= distance;

            printf("\nYou have successfully reached %s planet.\n", planets[planetChoice-1].name);
            printf("Resources available on this planet: %d\n", resources);

            if(spaceship.cargo >= 100) {
                printf("Cargo full. Cannot load any more resources.\n");
                continue;
            }

            int loadAmount = rand() % (resources + 1);
            spaceship.cargo += loadAmount;
            planets[planetChoice-1].resources -= loadAmount;

            printf("Loaded %d resources onto the spaceship.\n", loadAmount);
        }
        else if(choice == 2) {
            int resources = planets[0].resources;
            if(resources == 0) {
                printf("No resources available on the current planet.\n");
                continue;
            }

            if(spaceship.cargo >= 100) {
                printf("Cargo full. Cannot load any more resources.\n");
                continue;
            }

            int loadAmount = rand() % (resources + 1);
            spaceship.cargo += loadAmount;
            planets[0].resources -= loadAmount;

            printf("\nLoaded %d resources onto the spaceship from %s planet.\n", loadAmount, planets[0].name);
        }
        else {
            printf("\nExiting the Space Adventure game.\n");
            break;
        }

        printSpaceshipStatus(spaceship);
    }

    return 0;
}