//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BODIES 10 // maximum number of bodies in the system
#define G 6.67430e-11 // gravitational constant
#define TIME_STEP 60 // time step in seconds

// structure for a body
struct Body {
    char name[20];
    double mass;
    double radius;
    double position[3]; // position in x, y, z coordinates
    double velocity[3]; // velocity in x, y, z coordinates
    double acceleration[3]; // acceleration in x, y, z coordinates
};

int main () {
    struct Body solarSystem[MAX_BODIES];
    int numBodies = 0;
    double simulationTime = 0;
    double elapsedTime = 0;
    double distance, force;
    int i, j;
    
    // add bodies to the solar system
    strcpy(solarSystem[0].name, "Sun");
    solarSystem[0].mass = 1.989e30; // kg
    solarSystem[0].radius = 696340; // km
    solarSystem[0].position[0] = 0;
    solarSystem[0].position[1] = 0;
    solarSystem[0].position[2] = 0;
    solarSystem[0].velocity[0] = 0;
    solarSystem[0].velocity[1] = 0;
    solarSystem[0].velocity[2] = 0;
    numBodies++;
    
    strcpy(solarSystem[1].name, "Earth");
    solarSystem[1].mass = 5.972e24;
    solarSystem[1].radius = 6371;
    solarSystem[1].position[0] = 147.095e6; // km
    solarSystem[1].position[1] = 0;
    solarSystem[1].position[2] = 0;
    solarSystem[1].velocity[0] = 0;
    solarSystem[1].velocity[1] = 29.78e3; // m/s
    solarSystem[1].velocity[2] = 0;
    numBodies++;
    
    // run the simulation until elapsed time is 365 days (1 year)
    while (elapsedTime <= 365*24*3600) {
        // calculate acceleration and velocity for each body
        for (i = 0; i < numBodies; i++) {
            // reset acceleration for current time step
            solarSystem[i].acceleration[0] = 0;
            solarSystem[i].acceleration[1] = 0;
            solarSystem[i].acceleration[2] = 0;
            
            // calculate acceleration due to gravitational force from other bodies
            for (j = 0; j < numBodies; j++) {
                if (i == j) continue; // skip same body
                distance = sqrt(pow(solarSystem[j].position[0]-solarSystem[i].position[0], 2) + 
                    pow(solarSystem[j].position[1]-solarSystem[i].position[1], 2) +
                    pow(solarSystem[j].position[2]-solarSystem[i].position[2], 2));
                force = G * solarSystem[i].mass * solarSystem[j].mass / pow(distance, 2);
                solarSystem[i].acceleration[0] += force * (solarSystem[j].position[0]-solarSystem[i].position[0]) / (solarSystem[i].mass);
                solarSystem[i].acceleration[1] += force * (solarSystem[j].position[1]-solarSystem[i].position[1]) / (solarSystem[i].mass);
                solarSystem[i].acceleration[2] += force * (solarSystem[j].position[2]-solarSystem[i].position[2]) / (solarSystem[i].mass);
            }
            
            // update velocity and position for current time step
            solarSystem[i].velocity[0] += solarSystem[i].acceleration[0] * TIME_STEP;
            solarSystem[i].velocity[1] += solarSystem[i].acceleration[1] * TIME_STEP;
            solarSystem[i].velocity[2] += solarSystem[i].acceleration[2] * TIME_STEP;
            solarSystem[i].position[0] += solarSystem[i].velocity[0] * TIME_STEP;
            solarSystem[i].position[1] += solarSystem[i].velocity[1] * TIME_STEP;
            solarSystem[i].position[2] += solarSystem[i].velocity[2] * TIME_STEP;
        }
        
        simulationTime += TIME_STEP;
        elapsedTime += TIME_STEP;
    }
    
    // print final positions of bodies
    for (i = 0; i < numBodies; i++) {
        printf("%s:\n", solarSystem[i].name);
        printf("\tPosition:\t (%.2f, %.2f, %.2f) km\n", solarSystem[i].position[0], solarSystem[i].position[1], solarSystem[i].position[2]);
    }
    
    return 0;
}