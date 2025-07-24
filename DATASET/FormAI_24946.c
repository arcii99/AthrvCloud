//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define G 6.67e-11   // gravitational constant
#define DT 1         // time step for simulation
#define D 100        // diameter of each planet in pixels

typedef struct {
    double mass;   // mass of the planet in kg
    double x;      // x position of the planet
    double y;      // y position of the planet
    double vx;     // x velocity of the planet in m/s
    double vy;     // y velocity of the planet in m/s
} Planet;

int main() {
    int num_planets = 3;
    Planet planets[num_planets];

    // initialize each planet's properties
    planets[0].mass = 1e24;   // Earth
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[1].mass = 5.97e24;   // Moon
    planets[1].x = 400e6;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022;
    planets[2].mass = 6.39e23;   // Mars
    planets[2].x = 227.9e9;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 24.1e3;

    // simulate the motion of the planets for 365 days
    int num_steps = 365*24*60*60/DT;
    for (int i = 0; i < num_steps; i++) {
        // calculate the gravitational force between each pair of planets
        for (int j = 0; j < num_planets; j++) {
            Planet* planet1 = &planets[j];
            double fx = 0;
            double fy = 0;
            for (int k = 0; k < num_planets; k++) {
                if (j == k) continue;
                Planet* planet2 = &planets[k];
                double dx = planet2->x - planet1->x;
                double dy = planet2->y - planet1->y;
                double distance = sqrt(dx*dx + dy*dy);
                double force = G * planet1->mass * planet2->mass / (distance*distance);
                fx += force * dx / distance;
                fy += force * dy / distance;
            }
            // update the planet's velocity and position based on the gravitational force and time step
            planet1->vx += fx / planet1->mass * DT;
            planet1->vy += fy / planet1->mass * DT;
            planet1->x += planet1->vx * DT;
            planet1->y += planet1->vy * DT;
        }

        // print out the position of each planet to the console for visualization
        printf("%10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
                planets[0].x, planets[0].y, planets[1].x, planets[1].y, planets[2].x, planets[2].y, i*DT);
    }

    return 0;
}