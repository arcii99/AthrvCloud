//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: cheerful
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265358979323846

// Structure to hold the coordinates of a celestial body
typedef struct {
    double x;
    double y;
} Point;

// Structure to hold the velocity of a celestial body
typedef struct {
    double dx;
    double dy;
} Velocity;

int main() {

    // Constants for the simulation
    const double G = 6.674e-11;      // Gravitational constant
    const double DT = 3600;          // Time step in seconds
    const double SCALE = 1e9;        // Scale factor for the simulation

    // Sun
    double sunMass = 1.989e30;
    Point sunPos = { 0, 0 };
    Velocity sunVel = { 0, 0 };

    // Mercury
    double mercMass = 3.285e23;
    double mercDist = 5.79e10;
    double mercSpeed = 47.87e3;
    Point mercPos = { mercDist, 0 };
    Velocity mercVel = { 0, mercSpeed };

    // Venus
    double venusMass = 4.867e24;
    double venusDist = 1.082e11;
    double venusSpeed = 35.02e3;
    Point venusPos = { venusDist, 0 };
    Velocity venusVel = { 0, venusSpeed };

    // Earth
    double earthMass = 5.972e24;
    double earthDist = 1.496e11;
    double earthSpeed = 29.78e3;
    Point earthPos = { earthDist, 0 };
    Velocity earthVel = { 0, earthSpeed };

    // Mars
    double marsMass = 6.39e23;
    double marsDist = 2.279e11;
    double marsSpeed = 24.077e3;
    Point marsPos = { marsDist, 0 };
    Velocity marsVel = { 0, marsSpeed };

    // Jupiter
    double jupiterMass = 1.898e27;
    double jupiterDist = 7.785e11;
    double jupiterSpeed = 13.07e3;
    Point jupiterPos = { jupiterDist, 0 };
    Velocity jupiterVel = { 0, jupiterSpeed };

    // Saturn
    double saturnMass = 5.683e26;
    double saturnDist = 1.433e12;
    double saturnSpeed = 9.69e3;
    Point saturnPos = { saturnDist, 0 };
    Velocity saturnVel = { 0, saturnSpeed };

    // Uranus
    double uranusMass = 8.681e25;
    double uranusDist = 2.872e12;
    double uranusSpeed = 6.81e3;
    Point uranusPos = { uranusDist, 0 };
    Velocity uranusVel = { 0, uranusSpeed };

    // Neptune
    double neptuneMass = 1.024e26;
    double neptuneDist = 4.495e12;
    double neptuneSpeed = 5.43e3;
    Point neptunePos = { neptuneDist, 0 };
    Velocity neptuneVel = { 0, neptuneSpeed };

    // Variables for the simulation
    Point positions[9] = { sunPos, mercPos, venusPos, earthPos, marsPos, jupiterPos, saturnPos, uranusPos, neptunePos };
    Velocity velocities[9] = { sunVel, mercVel, venusVel, earthVel, marsVel, jupiterVel, saturnVel, uranusVel, neptuneVel };
    double masses[9] = { sunMass, mercMass, venusMass, earthMass, marsMass, jupiterMass, saturnMass, uranusMass, neptuneMass };
    double accelX[9] = { 0 };
    double accelY[9] = { 0 };

    // Main simulation loop
    printf("\n\nWelcome to the Happy Solar System Simulation!\n\n");
    printf("We are going to simulate the movement of the planets of our solar system.\n");
    printf("Let's see how joyful they can be!\n\n");
    printf("Press Enter to start the simulation:");
    getchar();

    for (int i = 0; i < 365 * 24; i++) {

        // Calculate accelerations
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (j == k) continue;

                double dx = positions[k].x - positions[j].x;
                double dy = positions[k].y - positions[j].y;
                double dist = sqrt(dx * dx + dy * dy);
                double force = G * masses[j] * masses[k] / (dist * dist);

                accelX[j] += force * dx / (masses[j] * SCALE);
                accelY[j] += force * dy / (masses[j] * SCALE);
            }
        }

        // Update velocities
        for (int j = 0; j < 9; j++) {
            velocities[j].dx += accelX[j] * DT;
            velocities[j].dy += accelY[j] * DT;

            positions[j].x += velocities[j].dx * DT / SCALE;
            positions[j].y += velocities[j].dy * DT / SCALE;

            accelX[j] = 0;
            accelY[j] = 0;
        }

    }

    printf("\nThe Happy Solar System Simulation has come to an end!\n");
    printf("Let's see where our planets are now:\n\n");

    // Print final positions
    char* planetNames[9] = { "Sun", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune" };
    for (int i = 0; i < 9; i++) {
        printf("%s is at x = %.2lf km and y = %.2lf km from the Sun.\n",
            planetNames[i], positions[i].x / 1000, positions[i].y / 1000);
    }

    printf("\nThank you for simulating the Happy Solar System with us!\n");

    return 0;
}