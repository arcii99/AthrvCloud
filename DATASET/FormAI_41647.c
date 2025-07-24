//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAV_CONST 6.674E-11
#define MAX_PLANETS 10
#define MAX_X 1000
#define MAX_Y 1000
#define MAX_Z 1000

struct Planet {
    long double mass;
    long double x, y, z;
    long double vx, vy, vz;
};

struct Planet planets[MAX_PLANETS];
int num_planets = 0;

void add_planet(long double mass, long double x, long double y, long double z, long double vx, long double vy, long double vz) {
    planets[num_planets].mass = mass;
    planets[num_planets].x = x;
    planets[num_planets].y = y;
    planets[num_planets].z = z;
    planets[num_planets].vx = vx;
    planets[num_planets].vy = vy;
    planets[num_planets].vz = vz;
    num_planets++;
}

void update_planet(int p, long double fx, long double fy, long double fz, long double dt) {
    long double ax = fx / planets[p].mass;
    long double ay = fy / planets[p].mass;
    long double az = fz / planets[p].mass;
    planets[p].vx += ax * dt;
    planets[p].vy += ay * dt;
    planets[p].vz += az * dt;
    planets[p].x += planets[p].vx * dt;
    planets[p].y += planets[p].vy * dt;
    planets[p].z += planets[p].vz * dt;
}

void gravity_simulate(long double dt, int num_steps) {
    int t, p1, p2;
    long double dx, dy, dz, dist, fx, fy, fz;
    for (t = 0; t < num_steps; t++) {
        // calculate forces
        for (p1 = 0; p1 < num_planets; p1++) {
            fx = fy = fz = 0;
            for (p2 = 0; p2 < num_planets; p2++) {
                if (p1 != p2) {
                    dx = planets[p2].x - planets[p1].x;
                    dy = planets[p2].y - planets[p1].y;
                    dz = planets[p2].z - planets[p1].z;
                    dist = sqrt(dx*dx + dy*dy + dz*dz);
                    fx += GRAV_CONST * planets[p1].mass * planets[p2].mass * dx / (dist*dist*dist);
                    fy += GRAV_CONST * planets[p1].mass * planets[p2].mass * dy / (dist*dist*dist);
                    fz += GRAV_CONST * planets[p1].mass * planets[p2].mass * dz / (dist*dist*dist);
                }
            }
            update_planet(p1, fx, fy, fz, dt);
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    long double mass, x, y, z, vx, vy, vz;
    for (i = 0; i < MAX_PLANETS; i++) {
        mass = (rand() % 10 + 1) * 1E4;
        x = rand() % MAX_X;
        y = rand() % MAX_Y;
        z = rand() % MAX_Z;
        vx = (rand() % 10 - 5) * 1E3;
        vy = (rand() % 10 - 5) * 1E3;
        vz = (rand() % 10 - 5) * 1E3;
        add_planet(mass, x, y, z, vx, vy, vz);
    }
    gravity_simulate(3600, 24);
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d: mass=%Lf, x=%Lf, y=%Lf, z=%Lf, vx=%Lf, vy=%Lf, vz=%Lf\n",
               i, planets[i].mass, planets[i].x, planets[i].y, planets[i].z, planets[i].vx, planets[i].vy, planets[i].vz);
    }
    return 0;
}