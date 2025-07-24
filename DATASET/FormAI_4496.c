//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: romantic
#include <stdio.h>
#include <math.h>

void update_position(double *x, double *y, double *z, double *vx, double *vy, double *vz, double m, double dt) {
    double fx, fy, fz, ax, ay, az;
    fx = fy = fz = 0;
    double G = 6.6743e-11;
    double M = 1.98892e30;

    double r_cubed = pow((*x) * (*x) + (*y) * (*y) + (*z) * (*z), 1.5);
    fx -= G * m * M * (*x) / r_cubed;
    fy -= G * m * M * (*y) / r_cubed;
    fz -= G * m * M * (*z) / r_cubed;

    ax = fx / m;
    ay = fy / m;
    az = fz / m;

    *vx += ax * dt;
    *vy += ay * dt;
    *vz += az * dt;

    *x += (*vx) * dt;
    *y += (*vy) * dt;
    *z += (*vz) * dt;
}

int main() {
    double x_sun = 0, y_sun = 0, z_sun = 0;
    double x_earth = 147e9, y_earth = 0, z_earth = 0;
    double x_moon = 147e9 + 385000000, y_moon = 0, z_moon = 0;
    double vx_earth = 0, vy_earth = 30.3e3, vz_earth = 0;
    double vx_moon = vx_earth + 1.02e3, vy_moon = vy_earth + 1e3, vz_moon = 0;
    double dt = 3600;
    double m_earth = 5.9722e24;
    double m_moon = 7.346e22;

    printf("My love, let's take a trip through the solar system. As we sit here, holding hands, we are orbiting around the sun!\n");

    for(int i = 0; i < 365 * 24 * 60 * 6; i++) {
        update_position(&x_earth, &y_earth, &z_earth, &vx_earth, &vy_earth, &vz_earth, m_earth, dt);
        update_position(&x_moon, &y_moon, &z_moon, &vx_moon, &vy_moon, &vz_moon, m_moon, dt);

        printf("-------------------------------------------------------\n");
        printf("My love, look at the beauty of the solar system:\n");
        printf("Our planet Earth is at position (%lf, %lf, %lf)\n", x_earth, y_earth, z_earth);
        printf("Our faithful moon is at position (%lf, %lf, %lf)\n", x_moon, y_moon, z_moon);
    }

    printf("Our journey together through the solar system has come to an end my love, but we have many adventures ahead of us.\n");

    return 0;
}