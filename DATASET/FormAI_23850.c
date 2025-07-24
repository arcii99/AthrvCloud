//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the constants
#define DELTA_T 0.01    // time step
#define GRAV_CONST 6.674 // gravitational constant

// Define the structure for planet properties
struct planet
{
    char name[20];
    double mass;
    double x_position;
    double y_position;
    double x_velocity;
    double y_velocity;
};

// Function to compute the gravity force between two planets
double gravity_force(double mass1, double mass2, double distance)
{
    return GRAV_CONST * mass1 * mass2 / pow(distance, 2);
}

// Function to compute the distance between two planets
double distance(struct planet planet1, struct planet planet2)
{
    return sqrt(pow(planet2.x_position - planet1.x_position, 2) + pow(planet2.y_position - planet1.y_position, 2));
}

// Function to update the velocity and position of a planet
void update_planet(struct planet *planet, double x_force, double y_force)
{
    planet->x_velocity += x_force * DELTA_T / planet->mass;
    planet->y_velocity += y_force * DELTA_T / planet->mass;
    planet->x_position += planet->x_velocity * DELTA_T;
    planet->y_position += planet->y_velocity * DELTA_T;
}

int main()
{
    // Declare and initialize the planets
    struct planet earth = {"Earth", 5.97 * pow(10, 24), 0, 0, 0, 0};
    struct planet moon = {"Moon", 7.342 * pow(10, 22), 3.84 * pow(10, 8), 0, 0, 1022};

    // Compute the distance between the planets
    double dist = distance(earth, moon);

    // Compute the initial force
    double force = gravity_force(earth.mass, moon.mass, dist);

    // Compute the initial x and y components of the force
    double x_force = force * (moon.x_position - earth.x_position) / dist;
    double y_force = force * (moon.y_position - earth.y_position) / dist;

    // Update the positions and velocities of the planets
    update_planet(&earth, x_force, y_force);
    update_planet(&moon, -x_force, -y_force);

    // Print the new positions and velocities of the planets
    printf("New position of the Earth: (%f, %f)\n", earth.x_position, earth.y_position);
    printf("New velocity of the Earth: (%f, %f)\n", earth.x_velocity, earth.y_velocity);
    printf("New position of the Moon: (%f, %f)\n", moon.x_position, moon.y_position);
    printf("New velocity of the Moon: (%f, %f)\n", moon.x_velocity, moon.y_velocity);

    return 0;
}