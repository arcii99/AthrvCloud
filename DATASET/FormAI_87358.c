//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

// Function to compute gravitational force between 2 masses
double gravity_force(double m1, double m2, double r) {
    double G = 6.67e-11;    // gravitational constant
    return G * m1 * m2 / (r*r);
}

int main() {
    // Define mass and initial position of 2 particles
    double m1 = 10.0;
    double m2 = 20.0;
    double x1 = 0.0;
    double x2 = 50.0;
    
    // Define initial velocity of particles
    double v1 = 0.0;
    double v2 = 0.0;

    // Define simulation time, time step and frequency of printing
    double t = 0.0;
    double t_end = 100.0;
    double dt = 0.01;
    int print_freq = 1000;

    // Define variables for computing particle position and velocity
    double r = x2 - x1;
    double v = v2 - v1;
    double F = gravity_force(m1, m2, r);

    // Open output file for writing results of simulation
    FILE *out_file = fopen("sim_result.txt", "w");
    fprintf(out_file, "Time (s)\tDistance (m)\tVelocity (m/s)\n");

    // Run simulation loop until end time is reached
    while (t < t_end) {
        // Compute new position and velocity of particles
        double dv = (F / m1) * (dt / 2.0);
        v1 += dv;
        v2 -= dv;
        double dx = v * dt;
        x1 += dx;
        x2 -= dx;
        r = x2 - x1;
        F = gravity_force(m1, m2, r);
        dv = (F / m1) * (dt / 2.0);
        v1 += dv;
        v2 -= dv;
        v = v2 - v1;

        // Print results to output file every print_freq steps
        if ((int)(t / dt) % print_freq == 0) {
            fprintf(out_file, "%.2f\t%.2f\t%.2f\n", t, r, v);
        }

        // Increment time by time step
        t += dt;
    }

    // Close output file
    fclose(out_file);

    return 0;
}