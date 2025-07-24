//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational Constant 

typedef struct {
    double x, y; // Position of the body 
    double vx, vy; // Velocity of the body 
    double ax, ay; // Acceleration of the body 
    double m; // Mass of the body 
} Body;

void update_acceleration(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        double ax = 0, ay = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx * dx + dy * dy);
                double f = G * bodies[i].m * bodies[j].m / (r * r);
                ax += f * dx / r / bodies[i].m;
                ay += f * dy / r / bodies[i].m;
            }
        }
        bodies[i].ax = ax;
        bodies[i].ay = ay;
    }
}

void update_velocity(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax * dt;
        bodies[i].vy += bodies[i].ay * dt;
    }
}

void update_position(Body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

int main() {
    const int n = 8;
    const double dt = 60 * 60;

    Body solar_system[] = {
        // x, y, vx, vy, mass 
        {0, 0, 0, 0, 1.989e30}, // Sun 
        {57.9e9, 0, 0, 47.4e3, 3.3e23}, // Mercury 
        {108.2e9, 0, 0, 35.0e3, 4.87e24}, // Venus 
        {149.6e9, 0, 0, 29.8e3, 5.97e24}, // Earth
        {227.9e9, 0, 0, 24.1e3, 6.42e23}, // Mars
        {778.6e9, 0, 0, 13.1e3, 1.899e27}, // Jupiter
        {1433.5e9, 0, 0, 9.7e3, 5.685e26}, // Saturn
        {2872.5e9, 0, 0, 6.8e3, 8.682e25} // Uranus
    };

    const int steps = 365 * 24; // One year worth of steps 
    for (int i = 0; i < steps; i++) {
        update_acceleration(solar_system, n);
        update_velocity(solar_system, n, dt);
        update_position(solar_system, n, dt);

        printf("Step %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("Body %d: x = %.2e m, y = %.2e m\n", j + 1, solar_system[j].x, solar_system[j].y);
        }
        printf("\n");
    }

    return 0;
}