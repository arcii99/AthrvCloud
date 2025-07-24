//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: synchronous
#include <stdio.h>

#define G 6.67e-11 // gravitational constant

// structure to hold the attributes of a planet
typedef struct {
    char name[20];
    double mass;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

int main() {
    // define the planets in the simulation
    Planet earth = {"Earth", 5.97e24, 0, 0, 0, 0};
    Planet moon = {"Moon", 7.34e22, 384400000, 0, 0, 1022};

    // set up the simulation parameters
    double timestep = 3600; // 1 hour
    double totalTime = 31536000; // 1 year
    double currentTime = 0;

    // advance the simulation in time steps
    while (currentTime < totalTime) {
        // calculate the distance and direction between the planets
        double dx = moon.x - earth.x;
        double dy = moon.y - earth.y;
        double d = sqrt(dx*dx + dy*dy);
        double theta = atan2(dy, dx);

        // calculate the force between the planets
        double force = G * earth.mass * moon.mass / (d*d);

        // calculate the acceleration of each planet
        double accelEarth = force / earth.mass;
        double accelMoon = force / moon.mass;

        // calculate the new velocity of each planet
        earth.vx += accelEarth * cos(theta) * timestep;
        earth.vy += accelEarth * sin(theta) * timestep;
        moon.vx -= accelMoon * cos(theta) * timestep;
        moon.vy -= accelMoon * sin(theta) * timestep;

        // update the position of each planet
        earth.x += earth.vx * timestep;
        earth.y += earth.vy * timestep;
        moon.x += moon.vx * timestep;
        moon.y += moon.vy * timestep;

        // update the current time
        currentTime += timestep;
    }

    // print the final position of each planet
    printf("%s: (%.2f, %.2f)\n", earth.name, earth.x, earth.y);
    printf("%s: (%.2f, %.2f)\n", moon.name, moon.x, moon.y);

    return 0;
}