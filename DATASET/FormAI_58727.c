//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define FUEL_COST 10

struct Planet {
    char name[20];
    int distance;
    int fuel;
    int aliens;
};

struct Ship {
    int fuel;
    struct Planet location;
};

void initializePlanets(struct Planet planets[]) {
    srand(time(NULL));
    char names[MAX_PLANETS][20] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Alpha Centauri"};
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, names[i]);
        planets[i].distance = rand() % 10000 + 1;
        planets[i].fuel = rand() % 1000 + 1;
        planets[i].aliens = rand() % 20 + 1;
    }
}

void printPlanets(struct Planet planets[]) {
    printf("Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s (Distance: %d, Fuel: %d, Aliens: %d)\n", i + 1, planets[i].name, planets[i].distance, planets[i].fuel, planets[i].aliens);
    }
}

void travel(struct Ship *ship, struct Planet planet) {
    int trip_cost = planet.distance * FUEL_COST;
    if (ship->fuel < trip_cost) {
        printf("Not enough fuel to travel to %s! Need %d more units of fuel.\n", planet.name, trip_cost - ship->fuel);
        return;
    }
    
    printf("Traveling to %s...\n", planet.name);
    ship->fuel -= trip_cost;
    ship->location = planet;
    
    printf("Arrived at %s.\n", planet.name);
    printf("Fuel remaining: %d\n", ship->fuel);
}

int main() {
    struct Planet planets[MAX_PLANETS];
    struct Ship ship;
    int choice;
    
    initializePlanets(planets);
    
    strcpy(ship.location.name, "Earth");
    ship.location.distance = 0;
    ship.location.fuel = 1000;
    ship.location.aliens = 0;
    ship.fuel = 10000;
    
    printf("Welcome to Space Adventure!\n");
    
    while (1) {
        printf("\nCurrent Location: %s\n", ship.location.name);
        printf("Fuel: %d\n\n", ship.fuel);
        printPlanets(planets);
        
        printf("Enter the number of planet to travel to (0 to quit): ");
        scanf("%d", &choice);
        if (choice < 0 || choice > MAX_PLANETS) {
            printf("Invalid choice. Try again.\n");
            continue;
        } else if (choice == 0) {
            printf("Exiting Space Adventure.\n");
            break;
        }
        
        travel(&ship, planets[choice-1]);
    }
    
    return 0;
}