//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
// Cyberpunk C Planet Gravity Simulation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Constants
#define NUM_PLANETS 5 // Number of planets in the simulation
#define MAX_XY_COORD 100 // Maximum x and y coordinates for random initial positions
#define MAX_MASS 10 // Maximum mass for random initial masses
#define MAX_VELOCITY 5 // Maximum velocity for random initial velocities
#define G_CONST 6.674E-11 // Gravitational constant

// Structures
typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D pos; // Position vector
    Vector2D vel; // Velocity vector
    Vector2D accel; // Acceleration vector
    double mass; // Mass of the planet
} Planet;

// Function prototypes
double getDistance(Vector2D v1, Vector2D v2);
Vector2D getGravityVector(double mass1, Vector2D pos1, double mass2, Vector2D pos2);
void updatePlanetPositions(Planet planets[]);
void updatePlanetAccelerations(Planet planets[]);
void updatePlanetVelocities(Planet planets[]);
void randomizePlanetInitialConditions(Planet planets[]);
void printPlanetInfo(Planet planet);

int main(void) {

    // Seed the random number generator
    srand(time(NULL));

    // Initialize planets
    Planet planets[NUM_PLANETS];
    randomizePlanetInitialConditions(planets);

    // Main simulation loop
    int i, j, k;
    double force, distance;
    Vector2D gravityVector;
    for (k = 0; k < 1000; k++) {

        // Update positions of all planets
        updatePlanetPositions(planets);

        // Update accelerations of all planets due to gravity
        updatePlanetAccelerations(planets);

        // Update velocities of all planets
        updatePlanetVelocities(planets);

        // Print out information on all planets
        printf("--- Iteration %d ---\n", k+1);
        for (i = 0; i < NUM_PLANETS; i++) {
            printPlanetInfo(planets[i]);
        }
        printf("\n");

    }

    return 0;
}

// Calculates the distance between two 2D vectors
double getDistance(Vector2D v1, Vector2D v2) {
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculates the gravitational force vector acting on planet 1 due to planet 2
Vector2D getGravityVector(double mass1, Vector2D pos1, double mass2, Vector2D pos2) {

    // Calculate the distance between the two planets
    double distance = getDistance(pos1, pos2);

    // Calculate the force acting on planet 1 due to planet 2
    double force = G_CONST * mass1 * mass2 / (distance * distance);

    // Calculate the direction vector of the force
    Vector2D dirVec = {pos2.x - pos1.x, pos2.y - pos1.y};
    double dirVecMag = sqrt(dirVec.x*dirVec.x + dirVec.y*dirVec.y);
    if (dirVecMag != 0.0) {
        dirVec.x /= dirVecMag;
        dirVec.y /= dirVecMag;
    }

    // Calculate the gravitational force vector and return it
    Vector2D gravVec = {force * dirVec.x, force * dirVec.y};
    return gravVec;
}

// Updates the positions of all planets based on their velocities
void updatePlanetPositions(Planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].pos.x += planets[i].vel.x;
        planets[i].pos.y += planets[i].vel.y;
    }
}

// Updates the accelerations of all planets due to gravity
void updatePlanetAccelerations(Planet planets[]) {
    int i, j;
    double force, distance;
    Vector2D gravityVector;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].accel.x = 0.0;
        planets[i].accel.y = 0.0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                // Calculate the gravitational force and add it to the acceleration
                gravityVector = getGravityVector(planets[i].mass, planets[i].pos, planets[j].mass, planets[j].pos);
                planets[i].accel.x += gravityVector.x / planets[i].mass;
                planets[i].accel.y += gravityVector.y / planets[i].mass;
            }
        }
    }
}

// Updates the velocities of all planets based on their accelerations
void updatePlanetVelocities(Planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].vel.x += planets[i].accel.x;
        planets[i].vel.y += planets[i].accel.y;
    }
}

// Randomizes the initial positions, velocities, and masses of all planets
void randomizePlanetInitialConditions(Planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].pos.x = rand() % (2 * MAX_XY_COORD + 1) - MAX_XY_COORD;
        planets[i].pos.y = rand() % (2 * MAX_XY_COORD + 1) - MAX_XY_COORD;
        planets[i].vel.x = rand() % (2 * MAX_VELOCITY + 1) - MAX_VELOCITY;
        planets[i].vel.y = rand() % (2 * MAX_VELOCITY + 1) - MAX_VELOCITY;
        planets[i].mass = rand() % (MAX_MASS + 1);
    }
}

// Prints out information on a single planet
void printPlanetInfo(Planet planet) {
    printf("Position: (%f, %f)\n", planet.pos.x, planet.pos.y);
    printf("Velocity: (%f, %f)\n", planet.vel.x, planet.vel.y);
    printf("Acceleration: (%f, %f)\n", planet.accel.x, planet.accel.y);
    printf("Mass: %f\n", planet.mass);
}