//FormAI DATASET v1.0 Category: Physics simulation ; Style: innovative
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11   // Gravitational Constant
#define M1 5.97e24      // Mass of Earth
#define M2 7.35e22      // Mass of Moon
#define R 3.844e8       // Distance between Earth and Moon

int main () {
    double x1 = 0, y1 = 0, x2 = R, y2 = 0;   // Initial Position
    double vx1 = 0, vy1 = 0, vx2 = 0, vy2 = 1022;   // Initial Velocity
    double ax1 = 0, ay1 = 0, ax2 = 0, ay2 = 0;   // Acceleration
    double Fx, Fy, dx, dy, d, force;   // Variables for Calculations
    double dt = 0.01;    // Time Step
    double t = 0;   // Time elapsed

    while(1) {   // Infinite Loop for Simulation
        t += dt;

        // Calculate Distance between Earth and Moon
        dx = x2 - x1;
        dy = y2 - y1;
        d = sqrt(dx*dx + dy*dy);

        // Calculate Force between Earth and Moon
        force = G * M1 * M2 / (d*d);
        Fx = force * dx / d;
        Fy = force * dy / d;

        // Calculate Acceleration of Moon
        ax2 = Fx / M2;
        ay2 = Fy / M2;

        // Calculate Acceleration of Earth
        ax1 = -Fx / M1;
        ay1 = -Fy / M1;

        // Calculate Velocity of Moon
        vx2 += ax2 * dt;
        vy2 += ay2 * dt;

        // Calculate Velocity of Earth
        vx1 += ax1 * dt;
        vy1 += ay1 * dt;

        // Calculate Position of Moon
        x2 += vx2 * dt;
        y2 += vy2 * dt;

        // Calculate Position of Earth
        x1 += vx1 * dt;
        y1 += vy1 * dt;

        // Print Output
        printf("Time Elapsed: %f seconds\n", t);
        printf("Distance between Earth and Moon: %f meters\n", d);
        printf("Position of Earth: (%f, %f)\n", x1, y1);
        printf("Position of Moon: (%f, %f)\n\n", x2, y2);

        // Stop Simulation if Moon crashes into Earth
        if(d <= 1737100) {
            printf("Moon has crashed into Earth!\n");
            break;
        }
    }

    return 0;
}