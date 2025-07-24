//FormAI DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <math.h>

int main() {
    // get initial conditions from the user
    double x0, v0, m, wall, mu;
    printf("Enter initial position (m): ");
    scanf("%lf", &x0);
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &v0);
    printf("Enter mass (kg): ");
    scanf("%lf", &m);
    printf("Enter distance to wall (m): ");
    scanf("%lf", &wall);
    printf("Enter friction coefficient: ");
    scanf("%lf", &mu);
    
    // set up simulation variables
    double x = x0;
    double v = v0;
    double dt = 0.001;
    double g = 9.81;
    double ke = 0.5 * m * v * v;
    double pe = m * g * x;
    
    // run simulation
    while (x < wall && v > 0) {
        // compute forces
        double f_friction = -mu * m * g * copysign(1.0, v);
        double f_net = f_friction;

        // update velocity and position
        double a = f_net / m;
        v += a * dt;
        x += v * dt;

        // update energy
        double ke_new = 0.5 * m * v * v;
        double pe_new = m * g * x;
        double de = ke_new + pe_new - ke - pe;
        ke = ke_new;
        pe = pe_new;

        // output results
        printf("t=%.3f, x=%.3f, v=%.3f, K=%.3f, U=%.3f, E=%.3f\n",
               x/v, x, v, ke, pe, ke + pe);
    }

    // print final results
    printf("Ball hits the wall at x=%.3f m\n", wall);
    printf("Final velocity: v=%.3f m/s\n", v);
    printf("Final kinetic energy: K=%.3f J\n", ke);
    printf("Final potential energy: U=%.3f J\n", pe);
    printf("Final total energy: E=%.3f J\n", ke + pe);
    
    return 0;
}