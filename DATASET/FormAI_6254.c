//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 30
#define MAX_PLANET_NAME_LENGTH 50
#define MAX_ACTION_LENGTH 100

typedef struct Planet {
    char name[MAX_PLANET_NAME_LENGTH];
    int distance_from_earth;
    int resource_level;
} Planet;

typedef struct Ship {
    char name[MAX_NAME_LENGTH];
    int fuel_level;
    Planet current_planet;
} Ship;

void initialize_planet(Planet* planet, char* name, int distance, int resource_level) {
    strcpy(planet->name, name);
    planet->distance_from_earth = distance;
    planet->resource_level = resource_level;
}

void initialize_ship(Ship* ship, char* name, Planet current_planet, int fuel_level) {
    strcpy(ship->name, name);
    ship->current_planet = current_planet;
    ship->fuel_level = fuel_level;
}

void travel_to_new_planet(Ship* ship, Planet* new_planet) {
    int travel_distance = abs(new_planet->distance_from_earth - ship->current_planet.distance_from_earth);
    if (travel_distance > ship->fuel_level) {
        printf("Not enough fuel to reach planet %s. Please refuel.\n", new_planet->name);
    } else {
        ship->fuel_level -= travel_distance;
        ship->current_planet = *new_planet;
        printf("Arrived at planet %s! Distance traveled: %d.\n", new_planet->name, travel_distance);
    }
}

void refuel_ship(Ship* ship) {
    int fuel_needed = 100 - ship->fuel_level;
    int cost = fuel_needed * ship->current_planet.resource_level;
    if (cost > 0) {
        printf("Refueling will cost %d units of resource. Proceed? (y/n)\n", cost);
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "y") == 0) {
            ship->fuel_level += fuel_needed;
            ship->current_planet.resource_level -= cost;
            printf("Refueled! Current fuel level: %d. Remaining resource level on planet %s: %d.\n",
                   ship->fuel_level, ship->current_planet.name, ship->current_planet.resource_level);
        } else {
            printf("Refueling aborted.\n");
        }
    } else {
        printf("Ship is already fully fueled.\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator

    // Initialize planets
    Planet earth, alpha_centauri, sirius, vega;
    initialize_planet(&earth, "Earth", 0, 100);
    initialize_planet(&alpha_centauri, "Alpha Centauri", 40, rand() % 50 + 1);
    initialize_planet(&sirius, "Sirius", 70, rand() % 50 + 1);
    initialize_planet(&vega, "Vega", 120, rand() % 50 + 1);

    // Initialize ship
    Ship player_ship;
    initialize_ship(&player_ship, "Starship", earth, 30);

    // Main game loop
    int quit = 0;
    while (!quit) {
        printf("\nCurrent planet: %s\n", player_ship.current_planet.name);
        printf("Fuel level: %d\n", player_ship.fuel_level);
        printf("Resource level: %d\n", player_ship.current_planet.resource_level);

        printf("\nWhat do you want to do?\n");
        printf("1. Travel to Alpha Centauri (distance from Earth: %d)\n", alpha_centauri.distance_from_earth);
        printf("2. Travel to Sirius (distance from Earth: %d)\n", sirius.distance_from_earth);
        printf("3. Travel to Vega (distance from Earth: %d)\n", vega.distance_from_earth);
        printf("4. Refuel\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                travel_to_new_planet(&player_ship, &alpha_centauri);
                break;
            case 2:
                travel_to_new_planet(&player_ship, &sirius);
                break;
            case 3:
                travel_to_new_planet(&player_ship, &vega);
                break;
            case 4:
                refuel_ship(&player_ship);
                break;
            case 5:
                printf("Thanks for playing!\n");
                quit = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}