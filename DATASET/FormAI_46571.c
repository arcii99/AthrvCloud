//FormAI DATASET v1.0 Category: Physics simulation ; Style: creative
#include <stdio.h>
#include <math.h>

int main()
{
    // Constants
    const double G = 6.6743e-11; // Gravitational constant
    const double M = 5.97e24;    // Mass of Earth
    const double R = 6.371e6;    // Radius of Earth

    // Variables
    double t, dt;     // Time and time step
    double x, y, z;   // Position
    double vx, vy, vz; // Velocity
    double ax, ay, az; // Acceleration
    double r;         // Distance from center of Earth
    double Fg;        // Gravitational force
    int steps;        // Number of steps

    // Initialize variables
    t = 0;
    dt = 1;
    x = 0;
    y = R;
    z = 0;
    vx = 7500; // Initial velocity of satellite
    vy = 0;
    vz = 0;
    ax = 0;
    ay = 0;
    az = 0;
    Fg = 0;
    steps = 86400; // Number of steps in one day

    // Simulate motion of satellite
    for (int i = 0; i < steps; i++)
    {
        // Calculate distance from center of Earth
        r = sqrt(x*x + y*y + z*z);

        // Calculate gravitational force
        Fg = -G*M/r/r;

        // Calculate acceleration
        ax = Fg*x/r;
        ay = Fg*y/r;
        az = Fg*z/r;

        // Update velocity
        vx += ax*dt;
        vy += ay*dt;
        vz += az*dt;

        // Update position
        x += vx*dt;
        y += vy*dt;
        z += vz*dt;

        // Calculate time
        t += dt;

        // Print position and time
        printf("Position: (%.2f, %.2f, %.2f), Time: %.2f\n", x, y, z, t);
    }

    return 0;
}