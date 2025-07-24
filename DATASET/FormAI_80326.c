//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include<stdio.h>
#include<math.h>

// Function to calculate the gravitational force between two objects
double gravitationalForce(double G, double m1, double m2, double r) {
    return (G * m1 * m2)/(r * r);
}

// Function to simulate the motion of an object under gravity
void simulate(double G, double dt, double mass, double x_init, double y_init, double vx_init, double vy_init, double total_time) {
    double x = x_init, y = y_init; // Initial position of the object
    double vx = vx_init, vy = vy_init; // Initial velocity of the object
    double ax, ay; // Acceleration of the object
    double r, force; // Distance between the object and the Earth, Gravitational force between the object and the Earth

    printf("\nTime\t X-Coordinate\t Y-Coordinate\t Velocity\n");

    for(double t=0; t<=total_time; t+=dt) {
        r = sqrt(x * x + y * y);
        force = gravitationalForce(G, mass, 5.97e+24, r);
        ax = -force/mass * (x/r);
        ay = -force/mass * (y/r);
        vx += ax * dt;
        vy += ay * dt;
        x += vx * dt;
        y += vy * dt;
        printf("%.2lf\t %.2lf\t\t %.2lf\t\t %.2lf\n", t, x, y, sqrt(vx * vx + vy * vy));
    }
}

int main() {
    double G = 6.674e-11; // Gravitational constant
    double dt = 60; // Simulation time step
    double mass = 10000; // Mass of the object
    double x_init = 100000; // Initial x-coordinate of the object
    double y_init = 0; // Initial y-coordinate of the object
    double vx_init = 0; // Initial x-velocity of the object
    double vy_init = 7000; // Initial y-velocity of the object
    double total_time = 9000; // Total simulation time

    simulate(G, dt, mass, x_init, y_init, vx_init, vy_init, total_time);

    return 0;
}