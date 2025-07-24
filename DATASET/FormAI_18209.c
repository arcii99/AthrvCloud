//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11  // Gravitational constant
#define SUN_MASS 1.989e30  // Mass of Sun
#define EARTH_MASS 5.972e24  // Mass of Earth
#define AU 1.495e11  // Astronomical unit
#define YEAR 365.25*86400  // One year in seconds

// Structure to hold information about a celestial body
typedef struct {
    char name[20];  // Name of the body
    double mass;  // Mass of the body
    double x, y;  // Position of the body
    double vx, vy;  // Velocity of the body
    double ax, ay;  // Acceleration of the body
    double fx, fy;  // Net force acting on the body
} CelestialBody;

// Function to calculate the distance between two celestial bodies
double distance(CelestialBody b1, CelestialBody b2) {
    double dx = b1.x - b2.x;
    double dy = b1.y - b2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the force acting on a celestial body due to another celestial body
void calculate_force(CelestialBody *b1, CelestialBody *b2) {
    double dist = distance(*b1, *b2);
    double F = G * b1->mass * b2->mass / (dist*dist);
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    b1->fx += F * dx / dist;
    b1->fy += F * dy / dist;
    b2->fx -= F * dx / dist;
    b2->fy -= F * dy / dist;
}

int main() {
    CelestialBody sun = {"Sun", SUN_MASS, 0, 0, 0, 0, 0, 0, 0};
    CelestialBody earth = {"Earth", EARTH_MASS, AU, 0, 0, 29783, 0, 0, 0};
    
    double dt = 0.1*YEAR;  // Time step
    for (double t = 0; t < 10*YEAR; t += dt) {
        // Reset forces
        sun.fx = sun.fy = 0;
        earth.fx = earth.fy = 0;
        
        // Calculate forces
        calculate_force(&sun, &earth);
        
        // Update positions
        earth.x += earth.vx * dt + 0.5 * earth.ax * dt*dt;
        earth.y += earth.vy * dt + 0.5 * earth.ay * dt*dt;
        sun.x += sun.vx * dt + 0.5 * sun.ax * dt*dt;
        sun.y += sun.vy * dt + 0.5 * sun.ay * dt*dt;
        
        // Update velocities
        earth.vx += 0.5 * earth.ax * dt;
        earth.vy += 0.5 * earth.ay * dt;
        sun.vx += 0.5 * sun.ax * dt;
        sun.vy += 0.5 * sun.ay * dt;
        
        // Calculate accelerations
        earth.ax = earth.fx / earth.mass;
        earth.ay = earth.fy / earth.mass;
        sun.ax = sun.fx / sun.mass;
        sun.ay = sun.fy / sun.mass;
        
        // Update velocities again
        earth.vx += 0.5 * earth.ax * dt;
        earth.vy += 0.5 * earth.ay * dt;
        sun.vx += 0.5 * sun.ax * dt;
        sun.vy += 0.5 * sun.ay * dt;
        
        printf("%f\t%f\t%f\t%f\n", t, earth.x, earth.y, distance(sun, earth));
    }
    
    return 0;
}