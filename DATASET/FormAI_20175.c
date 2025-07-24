//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.674E-11	// Gravitational constant (m^3 kg^-1 s^-2)

typedef struct {
    double x, y;        // Position vector
    double vx, vy;      // Velocity vector
    double ax, ay;      // Acceleration vector
    double mass;        // Mass of the object (kg)
} Body;

int main()
{
    const int num_bodies = 2;   // Number of bodies in the simulation
    const int time_step = 3600; // Time step in seconds (1 hour)
    const int num_steps = 24;   // Number of time steps in one simulation (1 day)
    const double s_per_meter = 1.0 / 299792458.0; // Convert seconds to meters
    const double m_per_km = 1000.0;              // Convert meters to kilometers

    // Define the bodies in the simulation
    Body bodies[num_bodies];
    bodies[0].x = 0.0;
    bodies[0].y = 0.0;
    bodies[0].vx = 0.0;
    bodies[0].vy = 0.0;
    bodies[0].ax = 0.0;
    bodies[0].ay = 0.0;
    bodies[0].mass = 1.989E30;  // Mass of the sun
    bodies[1].x = -147095000.0;
    bodies[1].y = 0.0;
    bodies[1].vx = 0.0;
    bodies[1].vy = 30300.0;
    bodies[1].ax = 0.0;
    bodies[1].ay = 0.0;
    bodies[1].mass = 5.972E24;  // Mass of the earth

    // Simulate the motion of the bodies
    for (int t = 0; t < num_steps; t++) {
        // Calculate the gravitational force between each pair of bodies
        double fx[num_bodies];
        double fy[num_bodies];
        for (int i = 0; i < num_bodies; i++) {
            fx[i] = 0.0;
            fy[i] = 0.0;
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    double dx = bodies[j].x - bodies[i].x;
                    double dy = bodies[j].y - bodies[i].y;
                    double r = sqrt(dx*dx + dy*dy);
                    double f = GRAV_CONST * bodies[i].mass * bodies[j].mass / (r*r);
                    fx[i] += f * dx / r;
                    fy[i] += f * dy / r;
                }
            }
        }

        // Update the position and velocity of each body
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].ax = fx[i] / bodies[i].mass;
            bodies[i].ay = fy[i] / bodies[i].mass;
            bodies[i].vx += bodies[i].ax * time_step;
            bodies[i].vy += bodies[i].ay * time_step;
            bodies[i].x += bodies[i].vx * time_step * s_per_meter * m_per_km;
            bodies[i].y += bodies[i].vy * time_step * s_per_meter * m_per_km;
        }

        // Print the position of the earth
        printf("Earth @ x=%f, y=%f\n", bodies[1].x, bodies[1].y);
    }

    return 0;
}