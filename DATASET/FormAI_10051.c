//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.67408E-11 // M3/Kg-s²

struct planet {
    double mass;
    double x;
    double y;
    double velocityX;
    double velocityY;
};

typedef struct planet Planet;

void updatePosition(Planet *planet, double timeStep) {
    planet->x += planet->velocityX*timeStep;
    planet->y += planet->velocityY*timeStep;
}

void updateVelocity(Planet *planet, double timeStep, double netForceX, double netForceY) {
    double accelerationX = netForceX/planet->mass;
    double accelerationY = netForceY/planet->mass;
    planet->velocityX += accelerationX*timeStep;
    planet->velocityY += accelerationY*timeStep;
}

double distance(Planet planet1, Planet planet2) {
    double deltaX = planet1.x - planet2.x;
    double deltaY = planet1.y - planet2.y;
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

void calculateGravity(Planet *planet1, Planet *planet2, double timeStep) {
    double force = GRAVITY_CONSTANT*planet1->mass*planet2->mass/distance(*planet1, *planet2);
    double angle = atan2((planet1->y - planet2->y), (planet1->x - planet2->x));
    double forceX = force*cos(angle);
    double forceY = force*sin(angle);

    updateVelocity(planet1, timeStep, -forceX, -forceY);
    updateVelocity(planet2, timeStep, forceX, forceY);
}

void simulate(double timeStep, int steps, Planet *planets, int numPlanets) {
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < numPlanets; j++) {
            Planet *planet1 = &planets[j];
            double netForceX = 0.0;
            double netForceY = 0.0;

            for(int k = 0; k < numPlanets; k++) {
                if (j == k) continue;
                Planet *planet2 = &planets[k];
                calculateGravity(planet1, planet2, timeStep);
            }

            updatePosition(planet1, timeStep);
        }
    }
}

int main() {
    Planet planets[] = {
        {1E12, 0.0, 0.0, 0.0, 5000.0},
        {1E12, 384400000.0, 0.0, 0.0, 0.0}
    };

    simulate(86400.0, 30, planets, 2);
    return 0;
}