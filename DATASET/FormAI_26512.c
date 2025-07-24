//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11    // gravitational constant
#define DT 86400        // time step in seconds (1 day)

typedef struct {
    double x, y;        // position
    double vx, vy;      // velocity
    double m;           // mass
} Body;

Body sun = {0, 0, 0, 0, 1.989e30};
Body earth = {1.496e11, 0, 0, 29783, 5.972e24};
Body moon = {1.496e11 + 3.844e8, 0, 0, 1022, 7.342e22};

void update_position(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

void update_velocity(Body *body, double ax, double ay, double dt) {
    body->vx += ax * dt;
    body->vy += ay * dt;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double gravitational_force(double m1, double m2, double r) {
    return G * m1 * m2 / pow(r, 2);
}

void update_body(Body *body, double fx, double fy, double dt) {
    double ax = fx / body->m;
    double ay = fy / body->m;
    update_velocity(body, ax, ay, dt);
    update_position(body, dt);
}

void compute_forces() {
    double r_earth_sun = distance(earth.x, earth.y, sun.x, sun.y);
    double r_moon_earth = distance(moon.x, moon.y, earth.x, earth.y);
    double r_moon_sun = distance(moon.x, moon.y, sun.x, sun.y);
    double f_earth_sun = gravitational_force(earth.m, sun.m, r_earth_sun);
    double f_moon_earth = gravitational_force(moon.m, earth.m, r_moon_earth);
    double f_moon_sun = gravitational_force(moon.m, sun.m, r_moon_sun);
    double fx_earth_sun = f_earth_sun * (sun.x - earth.x) / r_earth_sun;
    double fy_earth_sun = f_earth_sun * (sun.y - earth.y) / r_earth_sun;
    double fx_moon_earth = f_moon_earth * (earth.x - moon.x) / r_moon_earth;
    double fy_moon_earth = f_moon_earth * (earth.y - moon.y) / r_moon_earth;
    double fx_moon_sun = f_moon_sun * (sun.x - moon.x) / r_moon_sun;
    double fy_moon_sun = f_moon_sun * (sun.y - moon.y) / r_moon_sun;
    update_body(&earth, fx_earth_sun + fx_moon_earth, fy_earth_sun + fy_moon_earth, DT);
    update_body(&moon, fx_moon_sun + fx_moon_earth, fy_moon_sun + fy_moon_earth, DT);
}

int main() {
    for (int i = 0; i < 365; i++) {
        printf("Day %d: Earth x=%lf, y=%lf, vx=%lf, vy=%lf\n", i, earth.x, earth.y, earth.vx, earth.vy);
        printf("Day %d: Moon x=%lf, y=%lf, vx=%lf, vy=%lf\n", i, moon.x, moon.y, moon.vx, moon.vy);
        compute_forces();
    }
    return 0;
}