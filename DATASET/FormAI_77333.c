//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surprised
#include <stdio.h>

int main() {
    printf("Oh my stars, I can hardly believe it! I've just simulated the entire solar system!\n");
    printf("I'm so excited to show it to you, so sit back and enjoy the ride!\n\n");

    // Let's define some constants
    const double G = 6.67e-11; // Gravitational constant
    const double M_sun = 1.9885e+30; // Mass of the Sun
    const double M_earth = 5.972e+24; // Mass of the Earth

    // Define the initial positions and velocities of the objects we're simulating
    double x_sun = 0, y_sun = 0, z_sun = 0;
    double vx_sun = 0, vy_sun = 0, vz_sun = 0;
    double x_earth = 147e+9, y_earth = 0, z_earth = 0;
    double vx_earth = 0, vy_earth = 30.29e+3, vz_earth = 0;

    // Set the simulation time step and number of steps
    double delta_t = 86400; // 1 day
    int n_steps = 365; // 1 year

    // Simulation loop
    for (int step = 0; step < n_steps; step++) {
        // Calculate the distance between the Sun and the Earth
        double dx = x_earth - x_sun;
        double dy = y_earth - y_sun;
        double dz = z_earth - z_sun;
        double r = sqrt(dx*dx + dy*dy + dz*dz);

        // Calculate the gravitational force between the Sun and the Earth
        double F = G * M_sun * M_earth / (r*r);

        // Calculate the components of the force in each direction
        double Fx = -F * dx / r;
        double Fy = -F * dy / r;
        double Fz = -F * dz / r;

        // Update the velocities
        vx_earth += Fx / M_earth * delta_t;
        vy_earth += Fy / M_earth * delta_t;
        vz_earth += Fz / M_earth * delta_t;
        vx_sun -= Fx / M_sun * delta_t;
        vy_sun -= Fy / M_sun * delta_t;
        vz_sun -= Fz / M_sun * delta_t;

        // Update the positions
        x_earth += vx_earth * delta_t;
        y_earth += vy_earth * delta_t;
        z_earth += vz_earth * delta_t;
        x_sun += vx_sun * delta_t;
        y_sun += vy_sun * delta_t;
        z_sun += vz_sun * delta_t;

        // Print out the positions of the Earth and the Sun
        printf("Day %d: Earth at (%e, %e, %e), Sun at (%e, %e, %e)\n", step, x_earth, y_earth, z_earth, x_sun, y_sun, z_sun);
    }

    printf("\n\nI hope you enjoyed that! Leave me a comment and let me know what you think!\n");
    return 0;
}