//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define M_EARTH 5.972e24 // mass of Earth
#define M_MOON 7.342e22 // mass of Moon
#define R_EARTH 6371000 // radius of Earth

int main() {
    double x_e = 0, y_e = 0; // Earth position
    double v_x_e = 0, v_y_e = 0; // Earth velocity
    double x_m = 384400000, y_m = 0; // Moon position
    double v_x_m = 0, v_y_m = 1023; // Moon velocity
    double t = 0; // time
    double dt = 60; // time delta
    double r_em, f_em_x, f_em_y; // Earth-Moon distance, forces
    double a_x_e, a_y_e, a_x_m, a_y_m; // Earth and Moon accelerations

    while (1) {
        // calculate distance and forces between Earth and Moon
        r_em = sqrt(pow(x_m - x_e, 2) + pow(y_m - y_e, 2));
        f_em_x = G * M_EARTH * M_MOON / pow(r_em, 2) * (x_m - x_e) / r_em;
        f_em_y = G * M_EARTH * M_MOON / pow(r_em, 2) * (y_m - y_e) / r_em;

        // calculate accelerations of Earth and Moon
        a_x_e = f_em_x / M_EARTH;
        a_y_e = f_em_y / M_EARTH;
        a_x_m = -f_em_x / M_MOON;
        a_y_m = -f_em_y / M_MOON;

        // update velocities of Earth and Moon
        v_x_e += a_x_e * dt;
        v_y_e += a_y_e * dt;
        v_x_m += a_x_m * dt;
        v_y_m += a_y_m * dt;

        // update positions of Earth and Moon
        x_e += v_x_e * dt;
        y_e += v_y_e * dt;
        x_m += v_x_m * dt;
        y_m += v_y_m * dt;

        // check if Moon crashes into Earth
        if (r_em < R_EARTH) {
            printf("Moon crashes into Earth!\n");
            break;
        }

        // print current positions of Earth and Moon
        printf("t = %.0f, Earth: (%.0f, %.0f), Moon: (%.0f, %.0f)\n",
               t, x_e, y_e, x_m, y_m);

        // update time
        t += dt;
    }

    return 0;
}