//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.67408E-11 // gravitational constant in m3/kg/s2

// Function to calculate the gravitational force F
double calculate_force(double M1, double M2, double r) {
    return GRAV_CONST * (M1 * M2) / (r * r);
}

// Function to calculate the acceleration a
double calculate_acceleration(double F, double M) {
    return F / M;
}

// Function to calculate the velocity v
double calculate_velocity(double v_initial, double a, double dt) {
    return v_initial + a * dt;
}

// Function to calculate the position x
double calculate_position(double x_initial, double v, double a, double dt) {
    return x_initial + v * dt + 0.5 * a * dt * dt;
}

int main() {
    double M1, M2, r, dt, t, a, F, v_initial1, v_initial2, v1, v2, x_initial1, x_initial2, x1, x2;

    printf("Enter mass of planet 1 in kg: ");
    scanf("%lf", &M1);
    printf("Enter mass of planet 2 in kg: ");
    scanf("%lf", &M2);
    printf("Enter distance between the two planets in meters: ");
    scanf("%lf", &r);
    printf("Enter initial velocity of planet 1 in m/s: ");
    scanf("%lf", &v_initial1);
    printf("Enter initial velocity of planet 2 in m/s: ");
    scanf("%lf", &v_initial2);
    printf("Enter time step in seconds: ");
    scanf("%lf", &dt);
    printf("Enter total time of simulation in seconds: ");
    scanf("%lf", &t);

    // calculate initial positions
    x_initial1 = -r * (M2 / (M1 + M2));
    x_initial2 = r * (M1 / (M1 + M2));

    // set initial velocities
    v1 = v_initial1;
    v2 = v_initial2;

    // simulate the system for given time
    for (double i = 0.0; i <= t; i += dt) {
        // calculate gravitational force between two planets
        F = calculate_force(M1, M2, r);
        
        // calculate acceleration for each planet
        a = calculate_acceleration(F, M1);
        
        // calculate new velocities for each planet
        v1 = calculate_velocity(v1, a, dt);
        v2 = calculate_velocity(v2, a, dt);
        
        // calculate new positions for each planet
        x1 = calculate_position(x_initial1, v1, a, dt);
        x2 = calculate_position(x_initial2, v2, a, dt);
        
        // update position variables
        x_initial1 = x1;
        x_initial2 = x2;

        // print current state of the system
        printf("Time: %lf seconds\n", i);
        printf("Planet 1 position: %lf meters\n", x1);
        printf("Planet 2 position: %lf meters\n", x2);
        printf("\n");
    }

    return 0;
}