//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 6.67408E-11; // gravitational constant

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Planet;

Vector calculateAcceleration(Planet planet, Planet* planets, int numPlanets) {
    Vector acceleration = {0.0, 0.0};
    for (int i = 0; i < numPlanets; i++) {
        if (planet.position.x == planets[i].position.x && planet.position.y == planets[i].position.y) {
            continue;
        }
        Vector direction = {planets[i].position.x - planet.position.x, planets[i].position.y - planet.position.y};
        double distance = sqrt(direction.x * direction.x + direction.y * direction.y);
        double force = G * planet.mass * planets[i].mass / (distance * distance);
        direction.x /= distance;
        direction.y /= distance;
        acceleration.x += direction.x * force / planet.mass;
        acceleration.y += direction.y * force / planet.mass;
    }
    return acceleration;
}

void updateVelocities(Planet* planets, Vector* accelerations, int numPlanets, double timeStep) {
    for (int i = 0; i < numPlanets; i++) {
        planets[i].velocity.x += accelerations[i].x * timeStep;
        planets[i].velocity.y += accelerations[i].y * timeStep;
    }
}

void updatePositions(Planet* planets, int numPlanets, double timeStep) {
    for (int i = 0; i < numPlanets; i++) {
        planets[i].position.x += planets[i].velocity.x * timeStep;
        planets[i].position.y += planets[i].velocity.y * timeStep;
    }
}

void printPlanetPositions(Planet* planets, int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        printf("Planet %d: x = %f, y = %f\n", i+1, planets[i].position.x, planets[i].position.y);
    }
}

int main() {
    int numPlanets = 4;
    Planet planets[numPlanets];
    
    // Initialize planets
    planets[0].mass = 1.989E30; // mass of the sun
    planets[0].position.x = 0.0;
    planets[0].position.y = 0.0;
    planets[0].velocity.x = 0.0;
    planets[0].velocity.y = 0.0;
    
    planets[1].mass = 5.97E24; // mass of the earth
    planets[1].position.x = 1.49598E11;
    planets[1].position.y = 0.0;
    planets[1].velocity.x = 0.0;
    planets[1].velocity.y = 29783.0;
    
    planets[2].mass = 6.39E23; // mass of mars
    planets[2].position.x = 0.0;
    planets[2].position.y = 2.279E11;
    planets[2].velocity.x = 24007.0;
    planets[2].velocity.y = 0.0;
    
    planets[3].mass = 3.3E23; // mass of pluto
    planets[3].position.x = -5.90637E12;
    planets[3].position.y = 3.12468E12;
    planets[3].velocity.x = -2240.0;
    planets[3].velocity.y = -4445.0;
    
    double time = 0.0;
    double timeStep = 86400.0; // 1 day in seconds
    
    while (1) {
        Vector accelerations[numPlanets];
        for (int i = 0; i < numPlanets; i++) {
            accelerations[i] = calculateAcceleration(planets[i], planets, numPlanets);
        }
        updateVelocities(planets, accelerations, numPlanets, timeStep);
        updatePositions(planets, numPlanets, timeStep);
        printPlanetPositions(planets, numPlanets);
        
        time += timeStep;
        if (time > 365 * 86400.0) { // simulate 1 year
            break;
        }
    }
    
    return 0;
}