//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67428e-11 //Gravitational constant

//Structure to store planet information
typedef struct {
    char name[20];
    double mass;
    double radius;
    double x, y, z; //Position coordinates
    double vx, vy, vz; //Velocity components
} Planet;

//Function to calculate the gravitational force between two planets
void calculateGravitationalForce(Planet p1, Planet p2, double *fx, double *fy, double *fz) {
    double distance = sqrt((p2.x - p1.x) * (p2.x - p1.x) 
                            + (p2.y - p1.y) * (p2.y - p1.y) 
                            + (p2.z - p1.z) * (p2.z - p1.z));
    double force = G * p1.mass * p2.mass / (distance * distance);
    *fx = force * (p2.x - p1.x) / distance;
    *fy = force * (p2.y - p1.y) / distance;
    *fz = force * (p2.z - p1.z) / distance;
}

//Function to update planet positions and velocities based on gravitational forces
void updatePlanet(Planet *planet, double fx, double fy, double fz, double timeStep) {
    double ax = fx / planet->mass;
    double ay = fy / planet->mass;
    double az = fz / planet->mass;
    planet->vx += ax * timeStep;
    planet->vy += ay * timeStep;
    planet->vz += az * timeStep;
    planet->x += planet->vx * timeStep;
    planet->y += planet->vy * timeStep;
    planet->z += planet->vz * timeStep;
}

int main() {
    const int N = 4; //Number of planets
    const double timeStep = 86400; //Time step in seconds (1 day)
    
    Planet planets[N]; //Array of N planets
    
    //Initialize planet information
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.9885e30; //Mass of Sun: 1.9885 x 10^30 kg
    planets[0].radius = 695700; //Radius of Sun: 695,700 km
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    
    strcpy(planets[1].name, "Earth");
    planets[1].mass = 5.97e24; //Mass of Earth: 5.97 x 10^24 kg
    planets[1].radius = 6371; //Radius of Earth: 6,371 km
    planets[1].x = 147e9; //Distance from Sun: 147 x 10^9 m
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 30290; //Velocity around Sun: 29.29 km/s
    planets[1].vz = 0;
    
    strcpy(planets[2].name, "Mars");
    planets[2].mass = 6.39e23; //Mass of Mars: 6.39 x 10^23 kg
    planets[2].radius = 3389; //Radius of Mars: 3,389 km
    planets[2].x = 249e9; //Distance from Sun: 249 x 10^9 m
    planets[2].y = 0;
    planets[2].z = 0;
    planets[2].vx = 0;
    planets[2].vy = 24130; //Velocity around Sun: 24.13 km/s
    planets[2].vz = 0;
    
    strcpy(planets[3].name, "Jupiter");
    planets[3].mass = 1.9e27; //Mass of Jupiter: 1.9 x 10^27 kg
    planets[3].radius = 69911; //Radius of Jupiter: 69,911 km
    planets[3].x = 778e9; //Distance from Sun: 778 x 10^9 m
    planets[3].y = 0;
    planets[3].z = 0;
    planets[3].vx = 0;
    planets[3].vy = 13070; //Velocity around Sun: 13.07 km/s
    planets[3].vz = 0;
    
    //Perform N(N-1)/2 calculations to determine gravitational forces between each pair of planets
    double fx, fy, fz;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            calculateGravitationalForce(planets[i], planets[j], &fx, &fy, &fz);
            //Update planet i with force from planet j
            updatePlanet(&planets[i], fx, fy, fz, timeStep);
            //Update planet j with force from planet i (opposite direction)
            updatePlanet(&planets[j], -fx, -fy, -fz, timeStep);
        }
    }
    
    //Print final positions of planets
    for (int i = 0; i < N; i++) {
        printf("%s position: (%.3e, %.3e, %.3e)\n", planets[i].name, 
               planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}