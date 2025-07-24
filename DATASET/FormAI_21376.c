//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function that generates a random integer between two values */
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

/* Enum that represents the different space objects in the game */
enum Object {
    ASTEROID,
    PLANET,
    STAR,
    SHIP
};

/* Struct that represents a space object */
struct SpaceObject {
    enum Object type;
    int x;
    int y;
    int size;
    int health;
};

/* Function that creates a new space object */
struct SpaceObject* createSpaceObject(enum Object type, int x, int y, int size, int health) {
    struct SpaceObject* obj = malloc(sizeof(struct SpaceObject));

    obj->type = type;
    obj->x = x;
    obj->y = y;
    obj->size = size;
    obj->health = health;

    return obj;
}

int main() {
    srand(time(NULL));  // Seed random number generator with current time

    /* Generate some space objects */
    struct SpaceObject* asteroid = createSpaceObject(ASTEROID, randomInt(0, 100), randomInt(0, 100), randomInt(1, 10), randomInt(1, 10));
    struct SpaceObject* planet = createSpaceObject(PLANET, randomInt(0, 100), randomInt(0, 100), randomInt(10, 50), randomInt(50, 100));
    struct SpaceObject* star = createSpaceObject(STAR, randomInt(0, 100), randomInt(0, 100), randomInt(50, 100), randomInt(100, 200));
    struct SpaceObject* ship = createSpaceObject(SHIP, randomInt(0, 100), randomInt(0, 100), randomInt(1, 5), randomInt(10, 20));

    /* Print out the space objects */
    printf("Asteroid: x=%d y=%d size=%d health=%d\n", asteroid->x, asteroid->y, asteroid->size, asteroid->health);
    printf("Planet: x=%d y=%d size=%d health=%d\n", planet->x, planet->y, planet->size, planet->health);
    printf("Star: x=%d y=%d size=%d health=%d\n", star->x, star->y, star->size, star->health);
    printf("Ship: x=%d y=%d size=%d health=%d\n", ship->x, ship->y, ship->size, ship->health);

    /* Calculate the distance between the ship and the other objects */
    float distAsteroid = sqrt(pow(asteroid->x - ship->x, 2) + pow(asteroid->y - ship->y, 2));
    float distPlanet = sqrt(pow(planet->x - ship->x, 2) + pow(planet->y - ship->y, 2));
    float distStar = sqrt(pow(star->x - ship->x, 2) + pow(star->y - ship->y, 2));

    /* Print out the distances */
    printf("Distance from ship to asteroid: %.2f\n", distAsteroid);
    printf("Distance from ship to planet: %.2f\n", distPlanet);
    printf("Distance from ship to star: %.2f\n", distStar);

    /* Free the memory allocated for the space objects */
    free(asteroid);
    free(planet);
    free(star);
    free(ship);

    return 0;
}