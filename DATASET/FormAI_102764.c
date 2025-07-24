//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define G 6.67384e-11

typedef struct vector{
    double x;
    double y;
    double z;
} vector;

typedef struct planet{
    char name[50];
    double mass;
    vector position;
    vector velocity;
} planet;

void updatePosition(planet *p, double timeStep){
    double x = p->position.x + (p->velocity.x * timeStep);
    double y = p->position.y + (p->velocity.y * timeStep);
    double z = p->position.z + (p->velocity.z * timeStep);
    p->position.x = x;
    p->position.y = y;
    p->position.z = z;
}

void updateVelocity(planet *p, vector acceleration, double timeStep){
    double vx = p->velocity.x + (acceleration.x * timeStep);
    double vy = p->velocity.y + (acceleration.y * timeStep);
    double vz = p->velocity.z + (acceleration.z * timeStep);
    p->velocity.x = vx;
    p->velocity.y = vy;
    p->velocity.z = vz;
}

double calculateDistance(planet p1, planet p2){
    double xDist = p2.position.x - p1.position.x;
    double yDist = p2.position.y - p1.position.y;
    double zDist = p2.position.z - p1.position.z;
    double distance = sqrt((xDist * xDist) + (yDist * yDist) + (zDist * zDist));
    return distance;
}

vector calculateGravity(planet p1, planet p2){
    double dist = calculateDistance(p1, p2);
    double force = (G * p1.mass * p2.mass) / (dist * dist);
    double xForce = force * (p2.position.x - p1.position.x) / dist;
    double yForce = force * (p2.position.y - p1.position.y) / dist;
    double zForce = force * (p2.position.z - p1.position.z) / dist;
    vector gravity = {xForce, yForce, zForce};
    return gravity;
}

int main(){
    srand(time(NULL));
    int numPlanets = 3;
    double timeStep = 1.0;
    planet planets[numPlanets];
    double universeSize = 1e14; // 10^14 meters
    double maxVelocity = 10000; // m/s
    double maxMass = 1e25; // 10^25 kg

    // Initialize random planets
    for (int i=0; i<numPlanets; i++){
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].mass = (double)rand()/(RAND_MAX/maxMass);
        planets[i].position.x = ((double)rand()/RAND_MAX)*universeSize;
        planets[i].position.y = ((double)rand()/RAND_MAX)*universeSize;
        planets[i].position.z = ((double)rand()/RAND_MAX)*universeSize;
        planets[i].velocity.x = ((double)rand()/RAND_MAX)*maxVelocity;
        planets[i].velocity.y = ((double)rand()/RAND_MAX)*maxVelocity;
        planets[i].velocity.z = ((double)rand()/RAND_MAX)*maxVelocity;
    }

    // Simulation loop
    for (int i=0; i<100; i++){
        printf("\nTime = %d seconds\n", i);
        for (int j=0; j<numPlanets; j++){
            vector totalGravity = {0, 0, 0};
            for (int k=0; k<numPlanets; k++){
                if (j != k){
                    vector gravity = calculateGravity(planets[j], planets[k]);
                    totalGravity.x += gravity.x;
                    totalGravity.y += gravity.y;
                    totalGravity.z += gravity.z;
                }
            }
            updateVelocity(&planets[j], totalGravity, timeStep);
            updatePosition(&planets[j], timeStep);
            printf("%s - Position: (%.2f, %.2f, %.2f), Velocity: (%.2f, %.2f, %.2f)\n", planets[j].name, planets[j].position.x, planets[j].position.y, planets[j].position.z, planets[j].velocity.x, planets[j].velocity.y, planets[j].velocity.z);
        }
    }

    return 0;
}