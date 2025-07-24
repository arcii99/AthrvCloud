//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define G 6.673e-11 // Gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Coord3D;

typedef struct {
    Coord3D position;
    Coord3D velocity;
    double mass;
} CelestialBody;

int main() {
    // Define the properties of the three planets
    CelestialBody earth = {
        .position = {1.496e11, 0, 0},
        .velocity = {0, 2.9783e4, 0},
        .mass = 5.9742e24
    };
    CelestialBody mars = {
        .position = {2.2798e11, 0, 0},
        .velocity = {0, 2.4077e4, 0},
        .mass = 6.39e23
    };
    CelestialBody jupiter = {
        .position = {7.7857e11, 0, 0},
        .velocity = {0, 1.307e4, 0},
        .mass = 1.898e27
    };
    
    double timestep = 86400; // One day in seconds
    double duration = 31536000 * 2; // Two years in seconds
    
    for (double t = 0; t < duration; t += timestep) {
        // Calculate the forces acting on each planet
        Coord3D earthForce = {0, 0, 0};
        Coord3D marsForce = {0, 0, 0};
        Coord3D jupiterForce = {0, 0, 0};
        
        double distance;
        double forceMagnitude;
        Coord3D forceVector;
        
        // Earth
        distance = sqrt(pow(earth.position.x - mars.position.x, 2) + 
                        pow(earth.position.y - mars.position.y, 2) + 
                        pow(earth.position.z - mars.position.z, 2));
        forceMagnitude = G * earth.mass * mars.mass / pow(distance, 2);
        forceVector = (Coord3D) {
            .x = forceMagnitude * (mars.position.x - earth.position.x) / distance,
            .y = forceMagnitude * (mars.position.y - earth.position.y) / distance,
            .z = forceMagnitude * (mars.position.z - earth.position.z) / distance
        };
        earthForce.x += forceVector.x;
        earthForce.y += forceVector.y;
        earthForce.z += forceVector.z;
        
        distance = sqrt(pow(earth.position.x - jupiter.position.x, 2) + 
                        pow(earth.position.y - jupiter.position.y, 2) + 
                        pow(earth.position.z - jupiter.position.z, 2));
        forceMagnitude = G * earth.mass * jupiter.mass / pow(distance, 2);
        forceVector = (Coord3D) {
            .x = forceMagnitude * (jupiter.position.x - earth.position.x) / distance,
            .y = forceMagnitude * (jupiter.position.y - earth.position.y) / distance,
            .z = forceMagnitude * (jupiter.position.z - earth.position.z) / distance
        };
        earthForce.x += forceVector.x;
        earthForce.y += forceVector.y;
        earthForce.z += forceVector.z;
        
        // Mars
        distance = sqrt(pow(mars.position.x - earth.position.x, 2) + 
                        pow(mars.position.y - earth.position.y, 2) + 
                        pow(mars.position.z - earth.position.z, 2));
        forceMagnitude = G * mars.mass * earth.mass / pow(distance, 2);
        forceVector = (Coord3D) {
            .x = forceMagnitude * (earth.position.x - mars.position.x) / distance,
            .y = forceMagnitude * (earth.position.y - mars.position.y) / distance,
            .z = forceMagnitude * (earth.position.z - mars.position.z) / distance
        };
        marsForce.x += forceVector.x;
        marsForce.y += forceVector.y;
        marsForce.z += forceVector.z;
        
        distance = sqrt(pow(mars.position.x - jupiter.position.x, 2) + 
                        pow(mars.position.y - jupiter.position.y, 2) + 
                        pow(mars.position.z - jupiter.position.z, 2));
        forceMagnitude = G * mars.mass * jupiter.mass / pow(distance, 2);
        forceVector = (Coord3D) {
            .x = forceMagnitude * (jupiter.position.x - mars.position.x) / distance,
            .y = forceMagnitude * (jupiter.position.y - mars.position.y) / distance,
            .z = forceMagnitude * (jupiter.position.z - mars.position.z) / distance
        };
        marsForce.x += forceVector.x;
        marsForce.y += forceVector.y;
        marsForce.z += forceVector.z;
        
        // Jupiter
        distance = sqrt(pow(jupiter.position.x - earth.position.x, 2) + 
                        pow(jupiter.position.y - earth.position.y, 2) + 
                        pow(jupiter.position.z - earth.position.z, 2));
        forceMagnitude = G * jupiter.mass * earth.mass / pow(distance, 2);
        forceVector = (Coord3D) {
            .x = forceMagnitude * (earth.position.x - jupiter.position.x) / distance,
            .y = forceMagnitude * (earth.position.y - jupiter.position.y) / distance,
            .z = forceMagnitude * (earth.position.z - jupiter.position.z) / distance
        };
        jupiterForce.x += forceVector.x;
        jupiterForce.y += forceVector.y;
        jupiterForce.z += forceVector.z;
        
        distance = sqrt(pow(jupiter.position.x - mars.position.x, 2) + 
                        pow(jupiter.position.y - mars.position.y, 2) + 
                        pow(jupiter.position.z - mars.position.z, 2));
        forceMagnitude = G * jupiter.mass * mars.mass / pow(distance, 2);
        forceVector = (Coord3D) {
            .x = forceMagnitude * (mars.position.x - jupiter.position.x) / distance,
            .y = forceMagnitude * (mars.position.y - jupiter.position.y) / distance,
            .z = forceMagnitude * (mars.position.z - jupiter.position.z) / distance
        };
        jupiterForce.x += forceVector.x;
        jupiterForce.y += forceVector.y;
        jupiterForce.z += forceVector.z;
        
        // Update the positions and velocities of each planet
        earth.velocity.x += earthForce.x / earth.mass * timestep;
        earth.velocity.y += earthForce.y / earth.mass * timestep;
        earth.velocity.z += earthForce.z / earth.mass * timestep;
        earth.position.x += earth.velocity.x * timestep;
        earth.position.y += earth.velocity.y * timestep;
        earth.position.z += earth.velocity.z * timestep;
        
        mars.velocity.x += marsForce.x / mars.mass * timestep;
        mars.velocity.y += marsForce.y / mars.mass * timestep;
        mars.velocity.z += marsForce.z / mars.mass * timestep;
        mars.position.x += mars.velocity.x * timestep;
        mars.position.y += mars.velocity.y * timestep;
        mars.position.z += mars.velocity.z * timestep;
        
        jupiter.velocity.x += jupiterForce.x / jupiter.mass * timestep;
        jupiter.velocity.y += jupiterForce.y / jupiter.mass * timestep;
        jupiter.velocity.z += jupiterForce.z / jupiter.mass * timestep;
        jupiter.position.x += jupiter.velocity.x * timestep;
        jupiter.position.y += jupiter.velocity.y * timestep;
        jupiter.position.z += jupiter.velocity.z * timestep;
        
        // Print the positions of each planet
        printf("t = %.0f days\n", t / 86400);
        printf("Earth: x = %.2e m, y = %.2e m, z = %.2e m\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Mars: x = %.2e m, y = %.2e m, z = %.2e m\n", mars.position.x, mars.position.y, mars.position.z);
        printf("Jupiter: x = %.2e m, y = %.2e m, z = %.2e m\n", jupiter.position.x, jupiter.position.y, jupiter.position.z);
    }
    
    return 0;
}