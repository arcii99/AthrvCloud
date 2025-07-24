//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G       6.67428e-11
#define INTERVAL    86400.0    /* one day */
#define N       9           /* number of planets */

typedef struct vector {
    double x;
    double y;
    double z;
} Vector;

typedef struct body {
    double mass;
    Vector pos;
    Vector v;
} Body;

const double masses[N] = {1.98892e30, 3.3011e23, 4.8675e24, 5.97237e24, \
        6.41693e23, 1.89813e27, 5.6846e26, 8.6832e25, 1.0243e26};

const double r0[N][3] = { {0, 0, 0}, {-4.50307002058367e10, 0, 0}, \
        {1.77507361393996e11, 0, 0}, {1.47093071925705e11, \
        1.37531529342634e11, 0}, {-3.50421459371027e10, \
        -1.00394072513675e11, 0}, {7.78664036898627e11, \
        -4.94338011440980e11, -2.29371094825520e11}, \
        {-2.77015959179005e12, -3.46139717303314e11, \
        6.83435462024480e10}, {4.40002193175568e12, \
        -1.92774811233020e12, -1.19023964758250e11}, \
        {4.42044771244202e12, 4.97791326218711e12, \
        -5.06485965229117e10} };

const double v0[N][3] = {{0, 0, 0}, {0, -58980.0, 0}, \
        {0, 47060.0, 0}, {28910.0, 27070.0, 0}, \
        {52750.0, -18280.0, 0}, {-13280.0, -21560.0, \
        -7000.0}, {2130.0, -22590.0, -6560.0}, \
        {-5270.0, 11520.0, 3280.0}, {-3080.0, \
        -2680.0, -3010.0}};

Body planets[N];
Vector next_p[N];
Vector forces[N];

void initialize() {
    int i, j;

    for (i = 0; i < N; i++) {
        planets[i].mass = masses[i];
        planets[i].pos.x = r0[i][0];
        planets[i].pos.y = r0[i][1];
        planets[i].pos.z = r0[i][2];
        planets[i].v.x = v0[i][0];
        planets[i].v.y = v0[i][1];
        planets[i].v.z = v0[i][2];
    }

}

void calculate_forces() {
    int i, j;
    double d, f;
    Vector r;
    Vector fij;
    Vector zero = {0,0,0};

    for (i = 0; i < N; i++) {
        forces[i] = zero;
    }

    for (i = 0; i < N; i++) {
        for (j = i+1; j < N; j++) {
            r.x = planets[j].pos.x - planets[i].pos.x;
            r.y = planets[j].pos.y - planets[i].pos.y;
            r.z = planets[j].pos.z - planets[i].pos.z;

            d = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);

            f = G*planets[i].mass*planets[j].mass/(d*d*d);

            fij.x = f*r.x;
            fij.y = f*r.y;
            fij.z = f*r.z;

            forces[j].x -= fij.x;
            forces[j].y -= fij.y;
            forces[j].z -= fij.z;

            forces[i].x += fij.x;
            forces[i].y += fij.y;
            forces[i].z += fij.z;
        }
    }
}

void update_positions() {
    int i;
    Vector a;
    Vector dv;

    for (i = 0; i < N; i++) {
        a.x = forces[i].x/planets[i].mass;
        a.y = forces[i].y/planets[i].mass;
        a.z = forces[i].z/planets[i].mass;

        dv.x = a.x*INTERVAL;
        dv.y = a.y*INTERVAL;
        dv.z = a.z*INTERVAL;

        next_p[i].x = planets[i].pos.x + planets[i].v.x*INTERVAL + \
            0.5*a.x*INTERVAL*INTERVAL;
        next_p[i].y = planets[i].pos.y + planets[i].v.y*INTERVAL + \
            0.5*a.y*INTERVAL*INTERVAL;
        next_p[i].z = planets[i].pos.z + planets[i].v.z*INTERVAL + \
            0.5*a.z*INTERVAL*INTERVAL;

        planets[i].v.x += dv.x;
        planets[i].v.y += dv.y;
        planets[i].v.z += dv.z;
    }
}

void update_velocities() {
    int i;
    Vector a;
    Vector dv;

    for (i = 0; i < N; i++) {
        a.x = forces[i].x/planets[i].mass;
        a.y = forces[i].y/planets[i].mass;
        a.z = forces[i].z/planets[i].mass;

        dv.x = a.x*INTERVAL;
        dv.y = a.y*INTERVAL;
        dv.z = a.z*INTERVAL;

        planets[i].v.x += dv.x;
        planets[i].v.y += dv.y;
        planets[i].v.z += dv.z;
    }
}

void swap_vectors() {
    int i;

    for (i = 0; i < N; i++) {
        planets[i].pos.x = next_p[i].x;
        planets[i].pos.y = next_p[i].y;
        planets[i].pos.z = next_p[i].z;
    }
}

int main() {
    int t;
    int i;

    initialize();

    for (t = 0; t < 365*100; t++) {
        calculate_forces();
        update_positions();
        calculate_forces();
        update_velocities();
        swap_vectors();
    }

    for (i = 0; i < N; i++) {
        printf("%g %g %g\n", planets[i].pos.x, planets[i].pos.y, \
               planets[i].pos.z);
    }

    return 0;
}