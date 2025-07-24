//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>

// Define constants for the solar system simulation
#define G 6.6743e-11    // gravitational constant
#define M_SUN 1.9885e30 // mass of the sun

// Define the structure for a celestial body
typedef struct celestialBody {
    char name[20];    // name of the body
    double mass;      // mass of the body
    double radius;    // radius of the body
    double positionX; // x coordinate of the body's position
    double positionY; // y coordinate of the body's position
    double velocityX; // x component of the body's velocity
    double velocityY; // y component of the body's velocity
    double accelerationX; // x component of the body's acceleration
    double accelerationY; // y component of the body's acceleration
} celestialBody;

int main() {
    // Define the celestial bodies in the solar system
    celestialBody sun = {"Sun", M_SUN, 696340000, 0, 0, 0, 0, 0, 0};
    celestialBody earth = {"Earth", 5.97e24, 6371000, 149.6e9, 0, 0, 29783, 0, 0};
    celestialBody moon = {"Moon", 7.34e22, 1737400, 0, 384400000, 1022, 0, 0, 0};

    // Define the time step, duration and number of steps for the simulation
    double dt = 3600; // time step in seconds
    double duration = 365.25 * 24 * 3600; // duration of the simulation in seconds (1 year)
    int numSteps = duration / dt; // number of time steps in the simulation

    // Simulate the motion of the celestial bodies using the Euler-Cromer method
    for (int i = 0; i < numSteps; i++) {
        // Calculate the gravitational force between the sun and the earth
        double r = sqrt(pow(earth.positionX - sun.positionX, 2) + pow(earth.positionY - sun.positionY, 2));
        double F = G * sun.mass * earth.mass / pow(r, 2);

        // Calculate the gravitational force between the earth and the moon
        double r_moon = sqrt(pow(moon.positionX - earth.positionX, 2) + pow(moon.positionY - earth.positionY, 2));
        double F_moon = G * earth.mass * moon.mass / pow(r_moon, 2);

        // Calculate the acceleration of the earth and the moon
        earth.accelerationX = -F * (earth.positionX - sun.positionX) / (earth.mass * r);
        earth.accelerationY = -F * (earth.positionY - sun.positionY) / (earth.mass * r);

        moon.accelerationX = -F_moon * (moon.positionX - earth.positionX) / (moon.mass * r_moon);
        moon.accelerationY = -F_moon * (moon.positionY - earth.positionY) / (moon.mass * r_moon);

        // Update the velocities and positions of the celestial bodies
        earth.velocityX += earth.accelerationX * dt;
        earth.velocityY += earth.accelerationY * dt;

        moon.velocityX += moon.accelerationX * dt;
        moon.velocityY += moon.accelerationY * dt;

        earth.positionX += earth.velocityX * dt;
        earth.positionY += earth.velocityY * dt;

        moon.positionX += moon.velocityX * dt;
        moon.positionY += moon.velocityY * dt;
    }

    // Print the final positions of the celestial bodies
    printf("%s position: (%.2f, %.2f)\n", sun.name, sun.positionX, sun.positionY);
    printf("%s position: (%.2f, %.2f)\n", earth.name, earth.positionX, earth.positionY);
    printf("%s position: (%.2f, %.2f)\n", moon.name, moon.positionX, moon.positionY);

    return 0;
}