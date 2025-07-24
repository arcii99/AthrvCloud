//FormAI DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double mass = 5.0; // Mass of the object
    double k = 10.0; // Spring constant
    double x = 2.0; // Initial displacement
    double v = 0.0; // Initial velocity
    double a = 0.0; // Initial acceleration

    double t = 0.0; // Time elapsed
    double dt = 0.01; // Time step

    double x_i; // Displacement at the previous time step
    double v_i; // Velocity at the previous time step

    /* Print the initial conditions */
    printf("Initial conditions:\n");
    printf("  mass = %g kg\n", mass);
    printf("  spring constant = %g N/m\n", k);
    printf("  initial displacement = %g m\n", x);
    printf("  initial velocity = %g m/s\n", v);
    printf("\n");

    /* Run the simulation for 10 seconds */
    while (t <= 10.0) {

        /* Store previous values */
        x_i = x;
        v_i = v;

        /* Calculate acceleration */
        a = -k / mass * x_i;

        /* Calculate new values */
        x = x_i + v_i * dt + 0.5 * a * dt * dt;
        v = v_i + 0.5 * (a + a) * dt;

        /* Print current values */
        printf("Time: %g s\n", t);
        printf("  displacement = %g m\n", x);
        printf("  velocity = %g m/s\n", v);
        printf("  acceleration = %g m/s^2\n", a);
        printf("\n");

        /* Increase time */
        t += dt;
    }

    return 0;
}