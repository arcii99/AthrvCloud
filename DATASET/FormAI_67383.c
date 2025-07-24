//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONSTANT    6.67e-11     // Gravitational constant in SI units

// Structure that defines a planet
typedef struct {
    char name[20];      // Name of the planet
    double mass;        // Mass of the planet in kg
    double radius;      // Radius of the planet in km
    double x;           // x coordinate of the planet in km
    double y;           // y coordinate of the planet in km
    double vx;          // x component of velocity of the planet in m/s
    double vy;          // y component of velocity of the planet in m/s
} Planet;

// Function to calculate the force between two planets
void calculateForce(Planet *p1, Planet *p2, double *fx, double *fy) {
    double distance, force;

    // Calculate the distance between the two planets
    distance = sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));

    // Calculate the force between the two planets
    force = (G_CONSTANT * p1->mass * p2->mass) / pow(distance, 2);

    // Calculate the x and y components of the force
    *fx = force * (p2->x - p1->x) / distance;
    *fy = force * (p2->y - p1->y) / distance;
}

// Function to update the position and velocity of a planet
void updatePlanet(Planet *p, double fx, double fy, double timeStep) {
    double ax, ay;

    // Calculate the x and y components of acceleration
    ax = fx / p->mass;
    ay = fy / p->mass;

    // Update the position of the planet
    p->x += p->vx * timeStep + 0.5 * ax * pow(timeStep, 2);
    p->y += p->vy * timeStep + 0.5 * ay * pow(timeStep, 2);

    // Update the velocity of the planet
    p->vx += ax * timeStep;
    p->vy += ay * timeStep;
}

int main() {
    int i, j, numPlanets;
    double timeStep, simulationTime;
    double fx, fy;

    // Get the number of planets from the user
    printf("Enter the number of planets in the simulation: ");
    scanf("%d", &numPlanets);

    // Allocate memory for the planets
    Planet *planets = (Planet*) malloc(numPlanets * sizeof(Planet));

    // Get the details of each planet from the user
    for (i = 0; i < numPlanets; i++) {
        printf("Enter the details of planet %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        printf("Mass (in kg): ");
        scanf("%lf", &planets[i].mass);
        printf("Radius (in km): ");
        scanf("%lf", &planets[i].radius);
        printf("Distance from the sun (in km): ");
        scanf("%lf", &planets[i].x);
        planets[i].y = 0.0;
        printf("Velocity (in m/s) - x component: ");
        scanf("%lf", &planets[i].vx);
        printf("Velocity (in m/s) - y component: ");
        scanf("%lf", &planets[i].vy);
    }

    // Get the time step and simulation time from the user
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &timeStep);
    printf("Enter the simulation time (in seconds): ");
    scanf("%lf", &simulationTime);

    // Perform the simulation
    for (double time = 0; time < simulationTime; time += timeStep) {
        // Calculate the force between every pair of planets
        for (i = 0; i < numPlanets; i++) {
            for (j = i + 1; j < numPlanets; j++) {
                calculateForce(&planets[i], &planets[j], &fx, &fy);
                updatePlanet(&planets[i], fx, fy, timeStep);
                updatePlanet(&planets[j], -fx, -fy, timeStep); // Opposite force to second planet
            }
        }

        // Print the details of each planet
        printf("Time: %.2lf seconds\n", time);
        for (i = 0; i < numPlanets; i++) {
            printf("%s - Position (x, y): (%.2lf, %.2lf) km | Velocity (x, y): (%.2lf, %.2lf) m/s\n", 
                planets[i].name, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
        }
    }

    // Free the memory allocated for the planets
    free(planets);

    return 0;
}