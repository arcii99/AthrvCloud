//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spaceship {
    char name[20];
    int health;
    int fuel;
    int laser;
} spaceship;

void printSpaceshipStatus(spaceship* myShip) {
    printf("Spaceship Name: %s\n", myShip->name);
    printf("Health: %d\n", myShip->health);
    printf("Fuel: %d\n", myShip->fuel);
    printf("Laser: %d\n", myShip->laser);
}

void travelToPlanet(spaceship* myShip, char* planetName, int distance) {
    if (myShip->fuel >= distance) {
        printf("Travelling to %s!\n", planetName);
        myShip->fuel -= distance;
        printf("Arrived at %s. Fuel remaining: %d\n", planetName, myShip->fuel);
    }
    else {
        printf("Not enough fuel to travel to %s.\n", planetName);
    }
}

void attackAlien(spaceship* myShip, int alienHealth) {
    if (myShip->laser > 0) {
        printf("Attacking alien!\n");
        myShip->laser--;
        printf("Alien health decreased from %d to %d\n", alienHealth, alienHealth-10);
    }
    else {
        printf("Out of laser!\n");
    }
}

int main() {
    spaceship myShip = {"USS Voyager", 100, 50, 3};
    printSpaceshipStatus(&myShip);
    
    travelToPlanet(&myShip, "Mars", 30);
    attackAlien(&myShip, 50);
    travelToPlanet(&myShip, "Jupiter", 20);
    attackAlien(&myShip, 40);
    travelToPlanet(&myShip, "Saturn", 15);
    attackAlien(&myShip, 30);
    
    return 0;
}