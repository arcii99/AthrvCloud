//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant in m^3/kg*s^2
#define TIMESTEP 86400 // simulate one day of motion at a time
#define TIMESTOP 31557600 // simulate one year of motion

typedef struct {
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

double find_distance(Planet p1, Planet p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    double z_diff = p1.z - p2.z;
    double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
    return distance;
}

double find_gravity(Planet p1, Planet p2) {
    double distance = find_distance(p1, p2);
    double force = G * (p1.mass * p2.mass) / pow(distance, 2);
    return force;
}

void update_velocity(Planet *p1, Planet *p2, double gravity) {
    double distance = find_distance(*p1, *p2);
    double acceleration = gravity / p1->mass;
    double x_diff = p2->x - p1->x;
    double y_diff = p2->y - p1->y;
    double z_diff = p2->z - p1->z;
    p1->vx += acceleration * x_diff / distance * TIMESTEP;
    p1->vy += acceleration * y_diff / distance * TIMESTEP;
    p1->vz += acceleration * z_diff / distance * TIMESTEP;
}

void update_position(Planet *p) {
    p->x += p->vx * TIMESTEP;
    p->y += p->vy * TIMESTEP;
    p->z += p->vz * TIMESTEP;
}

int main() {
    Planet earth = {5.972e24, 6.371e6, 0, 0, 0, 0, 0, 0};
    Planet moon = {7.342e22, 1.737e6, 384400000, 0, 0, 0, 1022, 0};
    double gravitational_force = find_gravity(earth, moon);
    int time = 0;
    while (time < TIMESTOP) {
        update_velocity(&earth, &moon, gravitational_force);
        update_velocity(&moon, &earth, gravitational_force);
        update_position(&earth);
        update_position(&moon);
        time += TIMESTEP;
    }
    printf("Final position of Earth: %.3f %.3f %.3f\n", earth.x, earth.y, earth.z);
    printf("Final position of Moon: %.3f %.3f %.3f\n", moon.x, moon.y, moon.z);
    return 0;
}