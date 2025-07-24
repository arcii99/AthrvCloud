//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <math.h>

struct planet {
    double mass;
    double radius;
    double posX;
    double posY;
    double velX;
    double velY;
    double forceX;
    double forceY;
};

// Function to calculate distance between two planets
double distance(struct planet p1, struct planet p2) {
    double dx = p2.posX - p1.posX;
    double dy = p2.posY - p1.posY;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate gravitational force between two planets
double gravitationalForce(double mass1, double mass2, double distance) {
    double G = 6.674 * pow(10, -11);
    return G * ((mass1 * mass2) / (distance * distance));
}

// Function to update velocity and position of a planet
void updatePlanet(struct planet *p, double timeStep) {
    double accelerationX = p->forceX / p->mass;
    double accelerationY = p->forceY / p->mass;
    p->velX += accelerationX * timeStep;
    p->velY += accelerationY * timeStep;
    p->posX += p->velX * timeStep;
    p->posY += p->velY * timeStep;
}

int main() {
    // Create an array of planets
    struct planet planets[3];
    planets[0].mass = 5.97 * pow(10, 24);
    planets[0].radius = 6.37 * pow(10, 6);
    planets[0].posX = 0;
    planets[0].posY = 0;
    planets[0].velX = 0;
    planets[0].velY = 0;
    planets[1].mass = 3.29 * pow(10, 23);
    planets[1].radius = 3.39 * pow(10, 6);
    planets[1].posX = 3.84 * pow(10, 8);
    planets[1].posY = 0;
    planets[1].velX = 0;
    planets[1].velY = 1023.05504;
    planets[2].mass = 6.39 * pow(10, 23);
    planets[2].radius = 3.39 * pow(10, 6);
    planets[2].posX = 3.85 * pow(10, 8);
    planets[2].posY = 0;
    planets[2].velX = 0;
    planets[2].velY = 1007.075;

    // Simulation parameters
    double timeStep = 3600; // 1 hour
    double simulationTime = 365 * 24 * 3600; // 1 year
    int numSteps = simulationTime / timeStep;

    // Simulation loop
    for (int i = 0; i < numSteps; i++) {
        // Calculate forces between planets
        for (int j = 0; j < 3; j++) {
            planets[j].forceX = 0;
            planets[j].forceY = 0;
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                double d = distance(planets[j], planets[k]);
                double f = gravitationalForce(planets[j].mass, planets[k].mass, d);
                double fx = f * (planets[k].posX - planets[j].posX) / d;
                double fy = f * (planets[k].posY - planets[j].posY) / d;
                planets[j].forceX += fx;
                planets[j].forceY += fy;
            }
        }

        // Update planet positions and velocities
        for (int j = 0; j < 3; j++) {
            updatePlanet(&planets[j], timeStep);
        }

        // Print planet positions
        printf("Step %d:\n", i+1);
        for (int j = 0; j < 3; j++) {
            printf("Planet %d: (%f, %f)\n", j+1, planets[j].posX, planets[j].posY);
        }
    }

    return 0;
}