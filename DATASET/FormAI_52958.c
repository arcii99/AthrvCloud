//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743 * pow(10, -11) // Gravitational constant
#define TIMESTEP 0.01 // Time step for simulation
#define OUTPUT_INTERVAL 10 // Output interval for simulation

struct Vector {
    double x, y;
};

struct Planet {
    char name[20];
    double mass;
    struct Vector position;
    struct Vector velocity;
    struct Vector acceleration;
};

void updateAcceleration(struct Planet *p, struct Planet allPlanets[], int numPlanets) {
    struct Vector force, acceleration;
    double distance, magnitude;

    for (int i = 0; i < numPlanets; i++) {
        if (strcmp(p->name, allPlanets[i].name) != 0) {
            // calculate distance between the two planets
            distance = sqrt(pow(p->position.x - allPlanets[i].position.x, 2) + pow(p->position.y - allPlanets[i].position.y, 2));

            // calculate the force between the two planets using Newton's law of universal gravitation
            force.x = G * p->mass * allPlanets[i].mass / pow(distance, 2) * (allPlanets[i].position.x - p->position.x) / distance;
            force.y = G * p->mass * allPlanets[i].mass / pow(distance, 2) * (allPlanets[i].position.y - p->position.y) / distance;

            // update the acceleration of the planet
            p->acceleration.x += force.x / p->mass;
            p->acceleration.y += force.y / p->mass;
        }
    }
}

void updateVelocity(struct Planet *p) {
    p->velocity.x += p->acceleration.x * TIMESTEP;
    p->velocity.y += p->acceleration.y * TIMESTEP;
}

void updatePosition(struct Planet *p) {
    p->position.x += p->velocity.x * TIMESTEP;
    p->position.y += p->velocity.y * TIMESTEP;
}

int main() {
    int numPlanets;
    printf("Enter the number of planets: ");
    scanf("%d", &numPlanets);

    struct Planet planets[numPlanets];

    // read in planet data
    for (int i = 0; i < numPlanets; i++) {
        printf("\nPlanet %d\n", i+1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        printf("Mass (kg): ");
        scanf("%lf", &planets[i].mass);
        printf("Initial position (x,y) (m): ");
        scanf("%lf %lf", &planets[i].position.x, &planets[i].position.y);
        printf("Initial velocity (x,y) (m/s): ");
        scanf("%lf %lf", &planets[i].velocity.x, &planets[i].velocity.y);
    }

    // simulate the motion of the planets
    double time = 0;
    int outputCount = 0;
    while (1) {
        // update acceleration of each planet
        for (int i = 0; i < numPlanets; i++) {
            planets[i].acceleration.x = 0; // reset acceleration
            planets[i].acceleration.y = 0;
            updateAcceleration(&planets[i], planets, numPlanets);
        }

        // update velocity and position of each planet
        for (int i = 0; i < numPlanets; i++) {
            updateVelocity(&planets[i]);
            updatePosition(&planets[i]);
        }

        // output planet data at specified intervals
        if (outputCount == OUTPUT_INTERVAL) {
            printf("\nTime: %.2lf s\n", time);
            for (int i = 0; i < numPlanets; i++) {
                printf("Planet %s: (%.2lf, %.2lf)\n", planets[i].name, planets[i].position.x, planets[i].position.y);
            }
            outputCount = 0;
        }

        // increment time and output count
        time += TIMESTEP;
        outputCount++;

        // check if simulation should end
        char endSimulation;
        printf("\nContinue simulation (y/n)? ");
        scanf(" %c", &endSimulation);
        if (endSimulation == 'n') {
            break;
        }
    }

    return 0;
}