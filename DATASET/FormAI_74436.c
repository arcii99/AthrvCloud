//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/*************** Structures *****************/
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point location;
    int fuel;
    int health;
} Spaceship;

/*************** Function Declarations *****************/
void displayStatus(Spaceship* spaceship);
void moveSpaceship(Spaceship* spaceship, Point* destination);
void refuelSpaceship(Spaceship* spaceship);

/*************** Main Function *****************/
int main() {
    // Initializing the spaceship
    Spaceship mySpaceship = {.location = {0,0}, .fuel = 100, .health = 100};
    Point destination = {.x = 10, .y = 10};

    // Display initial status of spaceship
    displayStatus(&mySpaceship);

    // Moving spaceship to destination
    moveSpaceship(&mySpaceship, &destination);

    // Refueling spaceship
    refuelSpaceship(&mySpaceship);

    // Display final status of spaceship
    displayStatus(&mySpaceship);

    return 0;
}

/*************** Function Definitions *****************/
void displayStatus(Spaceship* spaceship) {
    printf("Spaceship Status:\n");
    printf("- Current location: (%d,%d)\n", spaceship->location.x, spaceship->location.y);
    printf("- Fuel: %d\n", spaceship->fuel);
    printf("- Health: %d\n\n", spaceship->health);
}

void moveSpaceship(Spaceship* spaceship, Point* destination) {
    // Calculate distance between spaceship location and destination
    int distance = abs(destination->x - spaceship->location.x) + abs(destination->y - spaceship->location.y);

    // Calculate fuel required to reach destination
    int fuelRequired = distance * 2;

    if (fuelRequired > spaceship->fuel) {
        printf("ERROR: Not enough fuel to make the journey.\n");
    } else {
        // Update spaceship location and fuel
        spaceship->location = *destination;
        spaceship->fuel -= fuelRequired;
        printf("Spaceship has successfully traveled to (%d,%d).\n\n", spaceship->location.x, spaceship->location.y);
    }
}

void refuelSpaceship(Spaceship* spaceship) {
    printf("Refueling spaceship...\n");
    spaceship->fuel = 100;
    printf("Spaceship has been refueled.\n\n");
}