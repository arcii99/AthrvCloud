//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant

typedef struct planet {
    char name[20];
    double mass;
    double radius;
    double x, y, z;
    double vx, vy, vz;
    double ax, ay, az;
} Planet;

double distance(Planet *a, Planet *b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    double dz = a->z - b->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_acceleration(Planet *a, Planet *b) {
    double r = distance(a, b);
    double f = G * a->mass * b->mass / (r*r);
    double fx = f * (b->x - a->x) / r;
    double fy = f * (b->y - a->y) / r;
    double fz = f * (b->z - a->z) / r;
    a->ax += fx / a->mass;
    a->ay += fy / a->mass;
    a->az += fz / a->mass;
}

void update_velocity(Planet *a, double dt) {
    a->vx += a->ax * dt;
    a->vy += a->ay * dt;
    a->vz += a->az * dt;
}

void update_position(Planet *a, double dt) {
    a->x += a->vx * dt;
    a->y += a->vy * dt;
    a->z += a->vz * dt;
}

int main() {
    Planet earth = {"Earth", 5.97e24, 6.38e6, 0, 0, 0, 0, 0, 0, 0, 0};
    Planet moon = {"Moon", 7.34e22, 1.74e6, 3.84e8, 0, 0, 0, 1022, 0, 0, 0};
    
    double dt = 60; // time step (in seconds)
    double t = 0;   // current time
    while (t < 86400) { // simulate one day
        // update acceleration for all planets
        earth.ax = earth.ay = earth.az = 0;
        moon.ax = moon.ay = moon.az = 0;
        update_acceleration(&earth, &moon);
        update_acceleration(&moon, &earth);
        
        // update velocity and position for all planets
        update_velocity(&earth, dt);
        update_position(&earth, dt);
        update_velocity(&moon, dt);
        update_position(&moon, dt);
        
        // print current positions
        printf("t=%.1f s: Earth (%.1f km, %.1f km, %.1f km), Moon (%.1f km, %.1f km, %.1f km)\n",
            t, earth.x/1000, earth.y/1000, earth.z/1000, moon.x/1000, moon.y/1000, moon.z/1000);
        
        t += dt;
    }
    
    return 0;
}