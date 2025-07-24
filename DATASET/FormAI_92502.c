//FormAI DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

int main() {

    // Define initial parameters
    double mass = 5.5;      // kg
    double g = 9.81;        // m/s^2
    double t = 0;           // s
    double dt = 0.001;      // s
    double drag_coeff = 0.47;   // Drag coefficient of a sphere
    double rho = 1.225;     // Density of air
    double radius = 0.1;    // m
    double area = M_PI*pow(radius,2);  // m^2
    double speed = 0;       // m/s
    double x = 0;           // m
    double y = 0;           // m
    double vx = 30;         // m/s
    double vy = 0;          // m/s

    // Define a function to compute the drag force
    double drag_force(double drag_coeff, double rho, double area, double speed) {
        return 0.5 * drag_coeff * rho * area * pow(speed,2);
    }

    // Run the simulation
    while (y >= 0) {
        // Compute the speed
        speed = sqrt(pow(vx,2) + pow(vy,2));

        // Compute the drag force
        double fdrag_x = -drag_force(drag_coeff, rho, area, speed) * vx / speed;
        double fdrag_y = -drag_force(drag_coeff, rho, area, speed) * vy / speed;

        // Compute the net force
        double fnet_x = 0;
        double fnet_y = -mass * g;

        // Add the drag force to the net force
        fnet_x += fdrag_x;
        fnet_y += fdrag_y;

        // Compute the acceleration
        double ax = fnet_x / mass;
        double ay = fnet_y / mass;

        // Update the position and velocity
        x += vx*dt + 0.5*ax*pow(dt,2);
        y += vy*dt + 0.5*ay*pow(dt,2);
        vx += ax*dt;
        vy += ay*dt;

        // Increase time
        t += dt;

        // Print the results
        printf("Time: %f s\tPosition: (%f, %f) m\tVelocity: (%f, %f) m/s\n", t, x, y, vx, vy);
    }

    return 0;
}