//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: immersive
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct
{
    double x;
    double y;
} Vector2D;

typedef struct
{
    Vector2D position;
    Vector2D velocity;
    double mass;
} Body;

int main()
{
    // Create bodies for each planet and the Sun
    Body sun = {
        .position = {0, 0},
        .velocity = {0, 0},
        .mass = 1.989e30 // mass of the Sun in kg
    };

    Body earth = {
        .position = {147.09e9, 0},
        .velocity = {0, 30.29e3},
        .mass = 5.97e24 // mass of the Earth in kg
    };

    Body mars = {
        .position = {-206.62e9, 0},
        .velocity = {0, -26.50e3},
        .mass = 6.39e23 // mass of Mars in kg
    };

    // Define simulation parameters
    const double dt = 3600; // time step in seconds
    const int steps = 8760; // number of simulation steps per year

    // Run simulation for one Earth year
    for (int i = 0; i < steps; i++)
    {
        // Calculate distance between Earth and Sun
        Vector2D direction = {earth.position.x - sun.position.x, earth.position.y - sun.position.y};
        double distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

        // Calculate gravitational force between Earth and Sun
        double force = G * sun.mass * earth.mass / pow(distance, 2);

        // Calculate acceleration of Earth
        Vector2D acceleration = {force * direction.x / earth.mass, force * direction.y / earth.mass};

        // Update velocity and position of Earth
        earth.velocity.x += acceleration.x * dt;
        earth.velocity.y += acceleration.y * dt;
        earth.position.x += earth.velocity.x * dt;
        earth.position.y += earth.velocity.y * dt;

        // Repeat for Mars
        Vector2D mars_direction = {mars.position.x - sun.position.x, mars.position.y - sun.position.y};
        double mars_distance = sqrt(pow(mars_direction.x, 2) + pow(mars_direction.y, 2));
        double mars_force = G * sun.mass * mars.mass / pow(mars_distance, 2);
        Vector2D mars_acceleration = {mars_force * mars_direction.x / mars.mass, mars_force * mars_direction.y / mars.mass};
        mars.velocity.x += mars_acceleration.x * dt;
        mars.velocity.y += mars_acceleration.y * dt;
        mars.position.x += mars.velocity.x * dt;
        mars.position.y += mars.velocity.y * dt;

        // Print positions of planets and Sun
        printf("Year %d\n", i + 1);
        printf("Earth position: (%.2lf, %.2lf)\n", earth.position.x, earth.position.y);
        printf("Mars position: (%.2lf, %.2lf)\n", mars.position.x, mars.position.y);
        printf("Sun position: (0, 0)\n\n");
    }

    return 0;
}